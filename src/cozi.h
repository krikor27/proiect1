#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oportunitate{
    int zi;
    double diferenta;
    char piata[30];
    struct Oportunitate *next;
    
};
typedef struct Oportunitate P;

struct Q
{
    P *front,*rear;
};
typedef struct Q Queue;

Queue* createQueue();
void enQueue(Queue* q, P v);
//int deQueue(Queue*q);
int isEmptyq(Queue*q);