#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Elem{
double val,randam; 
struct Elem* next;
};

typedef struct Elem Node;

void addAtBeginning(Node** head, double v);
void addAtEnd(Node** head, double v,double *miu);
double volatilitate(Node* head,int N,double miu);
double trunchiere(double x);
void freeList(Node *head);