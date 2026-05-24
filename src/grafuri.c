#include "grafuri.h"

GraphNode *createNode(GraphNode** graph, int stare)
{
    GraphNode* node;
    node=malloc(sizeof(GraphNode));
    if (node==NULL)
    {
        printf("Nu s-a alocat dinamic");
        exit(1);
    }
    node->stare=stare;
    node->total=0;
    node->edges=NULL;
    node->azi.numarator=0;
    node->azi.numitor=1;
    node->maine.numarator=0;
    node->maine.numitor=1;
    node->next=*graph;
    *graph=node;
    return node;
}
Edge* creareMuchie(GraphNode *node, int to)
{
    Edge *edge;
    edge=malloc(sizeof(Edge));
    if (edge==NULL)
    {
        printf("Nu s-a alocat dinamic");
        exit(1);
    }
    edge->to=to;
    edge->count=1;
    edge->next=node->edges;
    node->edges=edge;
    return edge;
}
Edge *gasesteMuchie(Edge* edges,int to)
{
    while(edges!=NULL)
    {
        if (edges->to==to)
            return edges;
        edges=edges->next;
    }
    return NULL;
}
GraphNode *gasesteNod(GraphNode* graph,int stare)
{
    while (graph!=NULL)
    {
        if (graph->stare==stare)
            return graph;
        graph=graph->next;
    }
    return NULL;
}
void addtranzitie(GraphNode **graph,int from,int to)
{
    GraphNode *node;
    Edge *edge;

    node=gasesteNod(*graph,from);

    if (node==NULL)
        node=createNode(graph,from);
    if (gasesteNod(*graph,to)==NULL)
        createNode(graph,to);

    edge=gasesteMuchie(node->edges,to);
    (node->total)++;

    if (edge==NULL)
        creareMuchie(node,to);
    else
        (edge->count)++;
}
GraphNode* populareGraf(FILE* fin, int N, double d)
{
    double n;
    GraphNode *graph=NULL;
    fscanf(fin,"%lf",&n);
    int stare_veche=(int) floor(n/d);
    for (int i=1;i<N;i++)
    {
        fscanf(fin,"%lf",&n);
        int stare_noua=(int) floor(n/d);
        addtranzitie(&graph,stare_veche,stare_noua);
        stare_veche=stare_noua;
    }
    return graph;
}