#include "task3.h"

int citpreturi(FILE* fin,double* pret)
{
    int i;
    if (fscanf(fin,"%lf,",&pret[0])!=1)
    return 0;
    for (i=1;i<9;i++)
    fscanf(fin,"%lf,",&pret[i]);
    fscanf(fin,"%lf",&pret[i]);
    return 1;
}
void citiresimbol(FILE* fin, char simbol[10][5])
{
    int i;
    for (i=0;i<9;i++)
        fscanf(fin,"%4[^,],",simbol[i]);
    fscanf(fin,"%4[^\n]",simbol[i]);
    fgetc(fin);
}
TreeNode* construiestearbore(FILE* fin,char simbol[10][5])
{
    TreeNode* root=createTreeNode(0);
    StockList* tail=NULL;
    double pretVechi[10];
    double pretNou[10];
    TreeNode* pozitieNod[10]; //tine minte ultimul nod in care se afla compania 

    citiresimbol(fin,simbol);
    for (int i=0;i<10;i++)
    {
        StockList* newStock=malloc(sizeof(StockList));
        if (newStock==NULL)
        {
          printf("nu s-a putut aloca dinamic\n");
          exit(1);
        }
        strcpy(newStock->symbol,simbol[i]);
        newStock->next=NULL;
        if (root->stocks==NULL)
        {
          root->stocks =newStock;
           tail=newStock;
        }
        else 
        {
           tail->next=newStock;
           tail=newStock;
        }
    }
    // am construit radacina
    for (int i=0;i<10;i++)
        pozitieNod[i]=root;
    if (!citpreturi(fin,pretVechi))
    {
        printf("Nu s-au citit primele preturi");
        exit(1);
    }
    while (citpreturi(fin,pretNou))
    {
        for (int i=0;i<10;i++)
            if (pretNou[i]>pretVechi[i])
                pozitieNod[i]=moveright(pozitieNod[i],simbol[i]);
            else 
                pozitieNod[i]=moveleft(pozitieNod[i],simbol[i]);
        for (int i=0;i<10;i++)
            pretVechi[i]=pretNou[i];
    }
    return root;
}
