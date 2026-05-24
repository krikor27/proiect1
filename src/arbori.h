#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SYM 5

typedef struct StockList {
    char symbol[MAX_SYM];// NVDA are 4 caractere, poti face MAX_SYM = 5 pentru final \0
    struct StockList *next;
} StockList;

typedef struct TreeNode {
    StockList *stocks; // toate actiunile care trec prin acest nod
    struct TreeNode *left; // aici se duc actiunile care scad
    struct TreeNode *right; // aici se duc actiunile care cresc
    int depth;
} TreeNode;
TreeNode *createTreeNode(int depth);
void addListtoNode(TreeNode* node,const char *simbol);
TreeNode* moveleft(TreeNode* node,const char *simbol);
TreeNode* moveright(TreeNode* node,const char *simbol);
void freeStockList(StockList* head);
void freeTree(TreeNode* root);
