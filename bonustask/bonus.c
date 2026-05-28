#include "bonus.h"

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb,
    void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);

    if (!ptr) {
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

double *get_open_prices(const char *symbol, const char *interval, const char *range, int *count_out)
{
    CURL *curl_handle;
    struct MemoryStruct chunk = {malloc(1), 0};
    char url[256];
    double *prices = NULL;

    sprintf(url,
        "https://query1.finance.yahoo.com/v8/finance/chart/%s?interval=%s&range=%s",
        symbol, interval, range);

    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    if (curl_easy_perform(curl_handle) == CURLE_OK) {
        cJSON *json = cJSON_Parse(chunk.memory);
        cJSON *result = cJSON_GetArrayItem(cJSON_GetObjectItem(
            cJSON_GetObjectItem(json, "chart"), "result"), 0);
        cJSON *quote = cJSON_GetArrayItem(cJSON_GetObjectItem(
            cJSON_GetObjectItem(result, "indicators"), "quote"), 0);
        cJSON *open_prices = cJSON_GetObjectItem(quote, "open");

        *count_out = cJSON_GetArraySize(open_prices);
        prices = malloc((*count_out) * sizeof(double));

        if (prices==NULL)
            exit(1);


        for (int i = 0; i < *count_out; i++) {
            cJSON *val = cJSON_GetArrayItem(open_prices, i);
            prices[i] = cJSON_IsNumber(val) ? val->valuedouble : -1.0;
        }

        cJSON_Delete(json);
    }

    curl_easy_cleanup(curl_handle);
    free(chunk.memory);

    return prices;
}

void bonustask(FILE* fin,FILE* fout)
{
    char symbol[16],interval [16],range[16];
    double *prices;
    int count,i;

    fseek(fin,6,SEEK_SET);
    fscanf(fin,"%15s",symbol);
    fscanf(fin,"%15s",interval);
    fscanf(fin,"%15s",range);

    prices= get_open_prices(symbol,interval,range,&count);
    if (prices==NULL)
    {
        fprintf(fout,"eroare API\n");
        exit(1);
    }
    fprintf(fout,"Compania: %s\n",symbol);
    fprintf(fout,"Preturi din %s in %s zile\n",interval,interval);
    fprintf(fout,"In ultima/ultimele: %s\n",range);
    for (i=0;i<count;i++)
        if (prices[i]>0)
            fprintf(fout,"%.2lf\n",prices[i]);
    free(prices);
}