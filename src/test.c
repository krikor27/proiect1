#include <stdio.h>
#include <stdlib.h>
int main(int argc,const char* argv[])
{
   // FILE* fin=fopen(argv[1],wt);
    FILE* fout=fopen(argv[2],"wt");
    fprintf(fout,"this is a demo ref file");
    fclose(fout);
}