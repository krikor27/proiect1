#include "liste.h"

int main(int argc,const char* argv[])
{
    int N,i;
    double a;
    FILE* fout,*fin;
    Node *head;
    head=NULL;

    if((fin=fopen(argv[1],"rt"))==NULL)
    {
        printf("Fisierul in nu a putut fi deschis\n");
        exit(1);
    }
    fscanf(fin,"%d",&N);
    p=(Node*)malloc(sizeof(Node));
    
    for(i=0;i<N;i++)
    {
        fscanf(fin,"%lf",&a);
        addAtEndt1(&head,a);
    }

    if((fout=fopen(argv[2],"wt"))==NULL)
    {
        printf("Fisierul out nu a putut fi deschis\n");
        exit(1);
    }

    fclose(fout);
}