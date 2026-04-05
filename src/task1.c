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

void addAtEndt1(Node** head, double v) {
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
        newNode->randam=(newNode->v - aux->v)/newNode->v;
        newNode->next = NULL; 
    }
}