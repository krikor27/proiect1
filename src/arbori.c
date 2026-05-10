#include "arbori.h"

TreeNode *createTreeNode(int depth)
{
    TreeNode* node=malloc(sizeof(TreeNode));
    if(node==NULL)
    {
        printf("Alocare dinamica esuata\n");
        exit(1);
    }
    node->stocks=NULL;
    node->left=NULL;
    node->right=NULL;
    node->depth=depth;
    return node;
}
void addListtoNode(TreeNode* node,char *simbol)
{
    StockList* newStock=malloc(sizeof(StockList));
    if (newStock==NULL)
    {
        printf("nu s-a putut aloca dinamic\n");
        exit(1);
    }
    strcpy(newStock->symbol,simbol);
    newStock->next=NULL;
    if (node->stocks==NULL)
    {
        node->stocks =newStock;
        return;
    }
    StockList* aux=node->stocks;
    while (aux->next !=NULL)
    aux=aux->next;
    aux->next=newStock;
}
TreeNode* moveleft(TreeNode* node,char *simbol)
{
    if (node->left==NULL)
    node->left=createTreeNode(node->depth+1);
    addListtoNode(node->left,simbol);
    return node->left;
}

TreeNode* moveright(TreeNode* node,char *simbol)
{
    if (node->right==NULL)
    node->right=createTreeNode(node->depth+1);
    addListtoNode(node->right,simbol);
    return node->right;
}


