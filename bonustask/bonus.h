#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

struct MemoryStruct {
    char *memory;
    size_t size;
};

double *get_open_prices(const char *symbol, const char *interval, const char *range, int *count_out);

void bonustask(FILE* fin,FILE* fout);