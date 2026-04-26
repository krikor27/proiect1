#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode
{
    double val;
    struct StackNode* next;
};

typedef struct StackNode Stiva;
void push(Stiva**top, double v);
double pop(Stiva**top);
double top(Stiva *top);
int isEmptys(Stiva*top);
void deleteStack(Stiva**top);