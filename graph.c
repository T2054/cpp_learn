#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 10
#define INFINITY 65536

typedef int Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodes;
    int numedges;
} Mgraph;

void CreateMGraph(Mgraph *G)
{
    int i, j, k, w;
    printf("请输入顶点数和边数");
    scanf(" %d,%d", &G->numNodes, &G->numedges);
    for (i = 0; i < G->numNodes; i++)
    {
        scanf(" %c", &G->vexs[i]);
    }
    for (i = 0; i < G->numNodes; i++)
    {
        for (j = 0; j < G->numNodes; j++)
        {
            G->arc[i][j] = INFINITY;
        }
    }
    for (k = 0; k < G->numedges; k++)
    {
        printf("输入边vi,vj上的下标i,下标j和权w\n");
        scanf(" %d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}
void PrintMGraph(Mgraph G)
{
    printf("顶点数：%d\n", G.numNodes);
    printf("边数：%d\n", G.numedges);
    printf("邻接矩阵：\n");
    printf("  ");
    for (int i = 0; i < G.numNodes; i++)
    {
        printf("%c ", G.vexs[i]);
    }
    printf("\n");
    for (int i = 0; i < G.numNodes; i++)
    {
        printf("%c ", G.vexs[i]);
        for (int j = 0; j < G.numNodes; j++)
        {
            if (G.arc[i][j] == INFINITY)
            {
                printf("∞ ");
            }
            else
            {
                printf("%d ", G.arc[i][j]);
            }
        }
        printf("\n");
    }
}

int main111(void)
{
    Mgraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    return 0;
}
