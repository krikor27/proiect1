#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "arbori.h"

int citpreturi(FILE* fin,double* pret);
void citiresimbol(FILE* fin, char simbol[10][5]);
TreeNode* construiestearbore(FILE* fin,char simbol[10][5]);