#include "cozi.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue *q, P v)
{
    P *newNode = (P *)malloc(sizeof(P));
   // newNode->val = v;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}
/*
P deQueue(Queue *q)
{
    Node *aux;
    int d;
    if (isEmptyq(q))
        return -999999999;
    aux = q->front;
    d = aux->val;
    q->front = (q->front)->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(aux);
    return d;
}
*/
int isEmptyq(Queue *q)
{
    return (q->front == NULL);
}
