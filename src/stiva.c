#include "stiva.h"

void push(Stiva** top, double v) //adaugare
{
    Stiva* newStiva=(Stiva*)malloc(sizeof(Stiva));
    newStiva->val=v;
    newStiva->next=*top;
    *top=newStiva;
}
double pop(Stiva**top)
{
    // returneaza informatia stocata in varf si sterge nodul
    if (isEmptys(*top)) return -9999999;
    // stocheaza adresa varfului in temp
    Stiva *temp=(*top);
    // stocheaza valoarea din varf in aux
    double aux=temp->val;
    // sterge elementul din varf
    *top=(*top)->next;
    free(temp);
    return aux;
}
int isEmptys(const Stiva*top)
{   
    return top==NULL;
}
void deleteStack(Stiva**top)
{
    while ((*top)!=NULL){ // !isEmpty(*top)
        Stiva *temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}