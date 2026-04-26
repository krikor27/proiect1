#include "task2.h"
void citire(FILE* fin,char *piata,int dim,Stiva **stackTop)
{
    double n;
    fgets(piata,dim,fin);
    piata[strcspn(piata, "\r\n")] = '\0';
    while(fscanf(fin,"%lf",&n)==1)
        push(stackTop,n);
}
void comparatie(Queue *q,Stiva **stackTop1,Stiva **stackTop2,Stiva **stackTop3,const char *piata1,const char *piata2,const char *piata3)
{
    int zi=1;
    while (!isEmptys(*stackTop1) && !isEmptys(*stackTop2) && !isEmptys(*stackTop3))
    {
        double pret1=pop(stackTop1);
        double pret2=pop(stackTop2);
        double pret3=pop(stackTop3);
        if (pret1==pret2 && pret1!=pret3)
        {
            enQueue(q,zi,fabs(pret3-pret1),piata3);
        }
        else if(pret1==pret3 && pret1!=pret2)
        {
            enQueue(q,zi,fabs(pret2-pret1),piata2);
        }
        else if(pret2==pret3 && pret2!=pret1)
        {
            enQueue(q,zi,fabs(pret1-pret2),piata1);
        }
        zi++;
    }
    
}