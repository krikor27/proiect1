#include "cozi.h"

Queue *createQueue()
{
    Queue *q= (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
    printf("Nu s-a putut aloca dinamic\n");
    exit(1);
}
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue *q, int zi, double diferenta,const char *piata)
{
    O *newNode = (O *)malloc(sizeof(O));
    if (newNode==NULL)
    {
        printf("Nu s-a putut aloca dinamic\n");
        exit(1);
    }
    newNode->zi=zi;
    newNode->diferenta=diferenta;
    strcpy(newNode->piata,piata);
    newNode->next = NULL;
    if (q->rear == NULL){
        q->front = newNode;
        q->rear=newNode;
    }
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
}
void printq(Queue *q,FILE* fout)
{
    O *aux=q->front;
    while (aux!=NULL)
    {
    fprintf(fout,"ziua %d - %.2lf - %s\n",aux->zi,aux->diferenta,aux->piata);
    aux=aux->next;
    }
}
void deleteq(Queue *q)
{
    while (q->front!=NULL)
    {
        O *aux=q->front;
        q->front=q->front->next;
        free(aux);
    }
    q->rear=NULL;
    free(q);
}
