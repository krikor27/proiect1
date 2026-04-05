#include "liste.h"
void addAtBeginning(Node** head, double v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL)
    {
        printf("Nu s-a putut aloca dinamic(la crearea listei)\n");
        exit(1);
    }
	newNode->val = v;
    newNode->randam=0.0;
	newNode->next = *head;
	*head = newNode;
}

void addAtEndt1(Node** head, double v,double *miu) {
    if (*head == NULL) 
        addAtBeginning(&*head, v);
    else 
    {
    Node *aux = *head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) 
    {
        printf("Nu s-a alocat dinamic newNode(addAtEndt1)");
        exit(1);
    } 
    newNode->val = v; 
        while (aux->next != NULL) 
            aux = aux->next;
        aux->next = newNode;
        newNode->randam=(newNode->val - aux->val)/aux->val;
        (*miu)+=newNode->randam;
        newNode->next = NULL; 
    }
}
double volatilitate(Node* head,int N,double miu)
{
    int i;
    double volat=0;
    for(i=0;i<N;i++)
    {
        volat+=(head->randam-miu)*(head->randam-miu);
        head=head->next;
    }
        volat/=N;
    volat=sqrt(volat);
    return volat;
}
double trunchiere(double x)
{
    return ((long long)(x*1000.0)/1000.0);
}