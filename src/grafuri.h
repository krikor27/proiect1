#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Fractie
{
    int numarator;
    int numitor;
};

typedef struct Fractie Fractie;

struct Edge
{
    int to;
    int count;
    struct Edge *next;
};
typedef struct Edge Edge;

struct Node
{
    int stare;
    int total;
    Fractie azi;
    Fractie maine;
    Edge* edges;
    struct Node* next;
};
typedef struct Node GraphNode;

GraphNode *createNode(GraphNode** graph, int stare);
Edge* creareMuchie(GraphNode *node, int to);
Edge *gasesteMuchie(Edge* edges,int to);
GraphNode *gasesteNod(GraphNode* graph,int stare);
void addtranzitie(GraphNode **graph,int from,int to);
GraphNode* populareGraf(FILE* fin, int N, double d);