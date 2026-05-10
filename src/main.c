#include "liste.h"
#include "task2.h"
#include "task3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
    if(argc<3)
    {
        printf("Trebuie introduse si fisierele input output");
        exit(1);
    }
    FILE* fin;
    if((fin=fopen(argv[1],"rt"))==NULL)
    {
        printf("Fisierul in nu a putut fi deschis\n");
        exit(1);
    }
    int task= nrtask(fin);
    //task 1
    if (task==1)
    {
    int N,i;
    double a,miu=0,volat,SR;
    FILE* fout1;
    Node *head=NULL;

    fscanf(fin,"%d",&N);
    if (N<2)
    {
        printf("Eroare");
        exit(1);
    }
    for(i=0;i<N;i++)
    {
        fscanf(fin,"%lf",&a);
        addAtEnd(&head,a,&miu);
    }
    fclose(fin);

    miu/=(N-1);
    volat=volatilitate(head->next,N-1,miu);
    SR=miu/volat;

    if((fout1=fopen(argv[2],"wt"))==NULL)
    {
        printf("Fisierul out nu a putut fi deschis\n");
        exit(1);
    }
    fprintf(fout1,"%.3lf\n%.3lf\n%.3lf\n",trunchiere(miu),trunchiere(volat),trunchiere(SR));
    fclose(fout1);
    freeList(head);
}
    //task 2
    if (task==2)
    {
    FILE* fout2;
    char piata1[30],piata2[30],piata3[30];
    Stiva *stackTop1=NULL;
    Stiva *stackTop2=NULL;
    Stiva *stackTop3=NULL;
    citire(fin,piata1,sizeof(piata1),&stackTop1);
    citire(fin,piata2,sizeof(piata2),&stackTop2);
    citire(fin,piata3,sizeof(piata3),&stackTop3);
    fclose(fin);
    Queue *q=createQueue();
    comparatie(q,&stackTop1,&stackTop2,&stackTop3,piata1,piata2,piata3);
    if((fout2=fopen(argv[2],"wt"))==NULL)
    {
        printf("Fisierul out nu a putut fi deschis\n");
        exit(1);
    }
    printq(q,fout2);
    fclose(fout2);
    deleteq(q);
    deleteStack(&stackTop1);
    deleteStack(&stackTop2);
    deleteStack(&stackTop3);
}
    if(task==3)
    {
        FILE* fout;
        char simbol[10][5];
        int opus[10][10]={0};
        TreeNode* root=construiestearbore(fin,simbol);
        fclose(fin);
        oglinda(root->left,root->right,simbol,opus);
        if((fout=fopen(argv[2],"wt"))==NULL)
        {
            printf("Fisierul out nu a putut fi deschis\n");
            exit(1);
        }
        afisperechi(fout,simbol,opus);
        fclose(fout);
        freeTree(root);
    }
}