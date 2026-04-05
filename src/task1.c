#include "liste.h"
void addAtBeginning(Node** head, double v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL)
    {
        printf("Nu s-a putut aloca dinamic(la crearea listei)\n");
        exit(1);
    }
	newNode->val = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEndt1(Node** head, double v,double *miu) {
    Node *aux = *head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) 
    {
        printf("Nu s-a alocat dinamic newNode(addAtEndt1)");
        exit(1);
    } 
    newNode->val = v; 

    if (*head == NULL) 
        addAtBeginning(&*head, v);
    else {
        while (aux->next != NULL) 
            aux = aux->next;
        aux->next = newNode;
        newNode->randam=(newNode->val - aux->val)/newNode->val;
        (*miu)+=newNode->randam;
        newNode->next = NULL; 
    }
}
double volatilitate(Node* head,int N)
{
    int i;
    double volat=0;
    for(i=0;i<N;i++)
    {
        volat+=(head->val-head->randam)*(head->val-head->randam);
        head=head->next;
    }
        volat/=N;
    volat=sqrt(volat);
    return volat;
}