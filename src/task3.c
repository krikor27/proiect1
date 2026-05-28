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
            if (pretNou[i]>=pretVechi[i])
                pozitieNod[i]=moveright(pozitieNod[i],simbol[i]);
            else 
                pozitieNod[i]=moveleft(pozitieNod[i],simbol[i]);
        for (int i=0;i<10;i++)
            pretVechi[i]=pretNou[i];
    }
    return root;
}
int indiceSimbol(const char simbol[10][5],const char* cautat)
{
    for (int i=0;i<10;i++)
        if(strcmp(simbol[i],cautat)==0)
            return i;
    return -999999;
}

void oglinda(TreeNode* st, TreeNode* dr, char simbol[10][5],int opus[10][10])
{
    if (st==NULL || dr==NULL) return;
    if (st->left==NULL && st->right==NULL &&
        dr->left==NULL && dr->right==NULL)
        {
            StockList* auxst=st->stocks; //lista din frunza din stanga

            while(auxst!=NULL)
            {
                StockList* auxdr=dr->stocks;
                
                while (auxdr!=NULL)
                {
                    int i=indiceSimbol(simbol,auxst->symbol);
                    int j=indiceSimbol(simbol,auxdr->symbol);
                    opus[i][j]=opus[j][i]=1;
                    auxdr=auxdr->next;
                }
                auxst=auxst->next;
            }
            return;
        }
        oglinda(st->left,dr->right,simbol,opus);
        oglinda(st->right,dr->left,simbol,opus);
        
}

void afisperechi(FILE* fout,const char simbol[10][5],const int opus[10][10])
{
    int primul=1;
    for (int i=0;i<10;i++)
        for (int j=i+1;j<10;j++)
            if (opus[i][j])
            {
                if(!primul)
                    fprintf(fout,"\n");
                fprintf(fout,"%s-%s",simbol[i],simbol[j]);
                primul=0;
            }
                
}