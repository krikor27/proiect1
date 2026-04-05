#include "liste.h"

int main(int argc,const char* argv[])
{
    int N,i;
    double a,miu,volat,SR;
    FILE* fout,*fin;
    Node *head;
    head=NULL;

    if((fin=fopen(argv[1],"rt"))==NULL)
    {
        printf("Fisierul in nu a putut fi deschis\n");
        exit(1);
    }
    fscanf(fin,"%d",&N);
    head=(Node*)malloc(sizeof(Node));
    if (head==NULL)
    {
        printf("Alocare dinamica esuata");
        exit(1);
    }
    for(i=0;i<N;i++)
    {
        fscanf(fin,"%lf",&a);
        addAtEndt1(&head,a,&miu);
    }
    fclose(fin);
    miu/=(N-1);
    volat=volatilitate(head->next,N-1);
    SR=miu/volat;
    if((fout=fopen(argv[2],"wt"))==NULL)
    {
        printf("Fisierul out nu a putut fi deschis\n");
        exit(1);
    }
    fprintf(fout,"%.3lf \n %.3lf \n %.3lf",miu,volat,SR);
    fclose(fout);
}