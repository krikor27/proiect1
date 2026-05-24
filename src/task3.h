#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "arbori.h"

int citpreturi(FILE* fin,double* pret);
void citiresimbol(FILE* fin, char simbol[10][5]);
TreeNode* construiestearbore(FILE* fin,char simbol[10][5]);
int indiceSimbol(const char simbol[10][5],const char* cautat);
void oglinda(TreeNode* st, TreeNode* dr, char simbol[10][5],int opus[10][10]);
void afisperechi(FILE* fout,const char simbol[10][5],const int opus[10][10]);