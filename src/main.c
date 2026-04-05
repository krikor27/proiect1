#include "liste.h"

int main(int argc,const char* argv[])
{
    if(argc<3)
    {
        printf("Trebuie introduse si fisierele input output");
        exit(1);
    }

    int N,i;
    double a,miu=0,volat,SR;
    FILE* fout,*fin;
    Node *head=NULL;

    if((fin=fopen(argv[1],"rt"))==NULL)
    {
        printf("Fisierul in nu a putut fi deschis\n");
        exit(1);
    }
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++)
    {
        fscanf(fin,"%lf",&a);
        addAtEnd(&head,a,&miu);
    }
    fclose(fin);

    miu/=(N-1);
    volat=volatilitate(head->next,N-1,miu);
    SR=miu/volat;

    if((fout=fopen(argv[2],"wt"))==NULL)
    {
        printf("Fisierul out nu a putut fi deschis\n");
        exit(1);
    }
    fprintf(fout,"%.3lf\n%.3lf\n%.3lf\n",trunchiere(miu),trunchiere(volat),trunchiere(SR));
    fclose(fout);
    freeList(head);
}