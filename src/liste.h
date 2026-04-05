#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Elem{
double val,randam; 
struct Elem* next;
};

typedef struct Elem Node;

addAtBeginning(Node** head, double v);
addAtEnd(Node** head, double v);
