#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    int data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int numVertexes;
    int numEdges;
} Graph;

void InitGraph(Graph *G, int numVertexes, int numedges)
{
    G->numVertexes = numVertexes;
    G->numEdges = numedges;
    for (int i = 0; i < numVertexes; ++i)
    {
        G->vertices[i].data = i;
        G->vertices[i].firstarc = NULL;
    }
}

void AddEdge(Graph *G, int start, int end)
{
    ArcNode *newNode = (ArcNode *)malloc(sizeof(ArcNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->adjvex = end;
    newNode->nextarc = G->vertices[start].firstarc;
    G->vertices[start].firstarc = newNode;
}

void TopologicalSort(Graph *G){
    int *inDegree = (int *)malloc(G->numVertexes * sizeof(int));
    if(inDegree == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0;i < G->numVertexes;++i){
        ArcNode *p = G->vertices[i].firstarc;
        while(p != NULL){
            ++inDegree[p->adjvex];
            p = p->nextarc;
        }
    }

    int queue[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    for(int i =  0;i < G->numVertexes;++i){
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
}
printf("Topological order: ");
while (front != rear)
{
    int v = queue[front++]; 
    printf("%d ", v);       
    ArcNode *p = G->vertices[v].firstarc;
    while (p != NULL)
    {
        if (--inDegree[p->adjvex] == 0)
        {
            queue[rear++] = p->adjvex;
        }
        p = p->nextarc;
    }
}
printf("\n");

free(inDegree);
}

int main()
{
    Graph G;
    int numVertexes = 6; 
    int numEdges = 6;    
    InitGraph(&G, numVertexes, numEdges);
    AddEdge(&G, 0, 1);
    AddEdge(&G, 0, 2);
    AddEdge(&G, 1, 3);
    AddEdge(&G, 1, 4);
    AddEdge(&G, 2, 4);
    AddEdge(&G, 3, 5);
    AddEdge(&G, 4, 3);

    TopologicalSort(&G);

    return 0;
}