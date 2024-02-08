#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef struct
{
    int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int visited[MAX_VERTEX_NUM];
    int num_vertices;
    int num_edges;
} Graph;

void initGraph(Graph *G, int n)
{
    G->num_vertices = n;
    G->num_edges = 0;
    for (int i = 0; i < n; ++i)
    {
        G->visited[i] = 0;
        for (int j = 0; j < n; ++j)
        {
            G->edges[i][j] = 0;
        }
    }
}

void addEdge(Graph *G, int u, int v)
{
    G->edges[u][v] = 1;
    G->edges[v][u] = 1;
    G->num_edges++;
}

void DFS(Graph *G, int v)
{
    printf("%d ", v); 
    G->visited[v] = 1;
    for (int i = 0; i < G->num_vertices; ++i)
    {
        if (G->edges[v][i] && !G->visited[i])
        {
            DFS(G, i);
        }
    }
}

void BFS(Graph *G, int v)
{
    int queue[MAX_VERTEX_NUM];
    int front = 0, rear = 0;
    printf("%d ", v);
    G->visited[v] = 1;
    queue[rear++] = v;
    while (front != rear)
    {
        int u = queue[front++];
        for (int i = 0; i < G->num_vertices; ++i)
        {
            if (G->edges[u][i] && !G->visited[i])
            {
                printf("%d ", i);
                G->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    Graph G;
    int n, m;
    printf("请输入图的顶点数和边数：\n");
    scanf("%d %d", &n, &m);
    initGraph(&G, n);
    printf("请输入%d条边的两个端点：\n", m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&G, u, v);
    }
    printf("深度优先搜索结果：\n");
    for (int i = 0; i < n; ++i)
    {
        if (!G.visited[i])
        {
            DFS(&G, i);
        }
    }
    printf("\n");
    for (int i = 0; i < n; ++i)
    {
        G.visited[i] = 0;
    }
    printf("广度优先搜索结果：\n");
    for (int i = 0; i < n; ++i)
    {
        if (!G.visited[i])
        {
            BFS(&G, i);
        }
    }
    printf("\n");
    return 0;
}
