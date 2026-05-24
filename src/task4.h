#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "grafuri.h"

int cmmdc(int a, int b);
void simplifica(Fractie *f);
Fractie inmfractii(Fractie a, Fractie b);
Fractie adunarefractii(Fractie a,Fractie b);
void afisFractie(FILE* fout, Fractie f);
void resetmaine(GraphNode *graph);
void copyMaineinAzi(GraphNode *graph);
Fractie cautaProbabil(GraphNode *graph,int stare);
void calculeazaMaine(GraphNode *graph);
void afisaret4(GraphNode *graph,FILE *fout, int K, int stare_target);
void citireT4(FILE *fin, int *N, double *d, int *K, int *stare_start, int *stare_target);
void initializarestart(GraphNode** graph,int stare_start);