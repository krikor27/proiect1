#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Oportunitate{
    int zi;
    double diferenta;
    char piata[30];
    struct Oportunitate *next;
    
};
typedef struct Oportunitate O;

struct Q
{
    O *front,*rear;
};
typedef struct Q Queue;

Queue* createQueue();
void enQueue(Queue *q, int zi, double diferenta,const char *piata);
void printq(Queue *q,FILE* fout);
void deleteq(Queue *q);