#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100

typedef int Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjvex;
    EdgeType info;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges;
} GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for (i = 0; i < G->numNodes; i++)
    {
        printf("输入顶点的数据:\n");       // 提示用户输入顶点数据
        scanf(" %c", &G->adjList[i].data); // 使用 %c 读取单个字符，前面加空格用于跳过空白字符
        G->adjList[i].firstedge = NULL;
    }

    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

void PrintGraph(GraphAdjList G)
{
    int i;
    EdgeNode *p;
    for (i = 0; i < G.numNodes; i++)
    {
        printf("%c -> ", G.adjList[i].data);
        p = G.adjList[i].firstedge;
        while (p != NULL)
        {
            printf("%c ", G.adjList[p->adjvex].data);
            p = p->next;
        }
        printf("\n");
    }
}

int main(void)
{
    GraphAdjList G;
    CreateALGraph(&G);

    printf("邻接表表示的图:\n");
    PrintGraph(G);

    return 0;
}
