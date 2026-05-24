#include "task4.h"

int cmmdc(int a, int b)
{
    if (a<0)
        a=-a;
    if (b<0)
        b=-b;
    while (b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }   
    return a;
}
void simplifica(Fractie *f)
{
    if (f->numarator==0)
    {
        f->numitor=1;
        return;
    }
    int div=cmmdc(f->numarator,f->numitor);
    f->numarator/=div;
    f->numitor/=div;
}
Fractie inmfractii(Fractie a, Fractie b)
{
    a.numarator=a.numarator*b.numarator;
    a.numitor=a.numitor*b.numitor;
    simplifica(&a);
    return a;
}
Fractie adunarefractii(Fractie a,Fractie b)
{
    a.numarator=a.numarator*b.numitor + b.numarator* a.numitor;
    a.numitor=a.numitor*b.numitor;
    simplifica(&a);
    return a;
}
void afisFractie(FILE* fout, Fractie f)
{
    simplifica(&f);
    if (f.numarator==0)
        fprintf(fout,"0");
    else if (f.numitor==1)
        fprintf(fout,"%d",f.numarator);
    else
        fprintf(fout,"%d/%d",f.numarator,f.numitor);
}
void resetmaine(GraphNode *graph)
{
    while(graph!=NULL)
    {
        graph->maine.numarator=0;
        graph->maine.numitor=1;
        graph=graph->next;
    }
}
void copyMaineinAzi(GraphNode *graph)
{
    while(graph!=NULL)
    {
        graph->azi=graph->maine;
        graph=graph->next;
    }
}
Fractie cautaProbabil(GraphNode *graph,int stare)
{
    GraphNode *node;
    Fractie zero;
    zero.numitor=1;
    zero.numarator=0;
    node=gasesteNod(graph,stare);
    if (node==NULL) return zero;
    else return node->azi;
}
void calculeazaMaine(GraphNode *graph)
{
    GraphNode *node,*dest;
    Edge *edge;
    Fractie probMuchie;
    Fractie val;
    resetmaine(graph);
    node=graph;
    while (node!=NULL)
    {   
        edge=node->edges;
        while (edge!=NULL)
        {
            dest=gasesteNod(graph,edge->to);
            probMuchie.numarator=edge->count;
            probMuchie.numitor=node->total;
            simplifica(&probMuchie);
            val=inmfractii(node->azi,probMuchie);
            dest->maine=adunarefractii(dest->maine,val);
            edge=edge->next;
        }
        node=node->next;
    }
    copyMaineinAzi(graph);
}
void afisaret4(GraphNode *graph,FILE *fout, int K, int stare_target)
{
    Fractie probabilitate;
    for(int zi=0;zi<K;zi++)
    {
        probabilitate=cautaProbabil(graph,stare_target);
        afisFractie(fout,probabilitate);
        if (zi!=K-1)
        {
            calculeazaMaine(graph);
            fprintf(fout,"\n");
        }
            
    }
}
void citireT4(FILE *fin, int *N, double *d, int *K, int *stare_start, int *stare_target)
{
    double P_start,P_target;
    fscanf(fin,"%d %lf %d %lf %lf",N,d,K,&P_start,&P_target);
    *stare_start=(int) floor(P_start/(*d));
    *stare_target=(int) floor(P_target/(*d));
}
void initializarestart(GraphNode** graph,int stare_start)
{
    GraphNode* startNode;
    if (gasesteNod(*graph,stare_start)==NULL)
        createNode(graph,stare_start);
    
    startNode=gasesteNod(*graph,stare_start);
    startNode->azi.numarator=1;
    startNode->azi.numitor=1;
}
