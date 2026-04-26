#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct StackNode
{
    double val;
    struct StackNode* next;
};

typedef struct StackNode Stiva;
void push(Stiva**top, double v);
double pop(Stiva**top);
int isEmptys(const Stiva*top);
void deleteStack(Stiva**top);