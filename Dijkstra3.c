#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX_NUM 6
#define INFINITY INT_MAX

typedef struct
{
    int vertex[MAX_VERTEX_NUM];
    long long arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int numVertexes;
    int numEdges;
} MGraph;

void Dijkstra(MGraph G, int start)
{
    int dist[MAX_VERTEX_NUM];
    int path[MAX_VERTEX_NUM];
    int visited[MAX_VERTEX_NUM];

    for (int i = 0; i < G.numVertexes; ++i)
    {
        dist[i] = G.arcs[start][i];
        path[i] = (G.arcs[start][i] < INFINITY) ? start : -1;
        visited[i] = 0;
    }

    visited[start] = 1;

    for (int i = 1; i < G.numVertexes; ++i)
    {
        int minDist = INFINITY;
        int u = start;
        for (int j = 0; j < G.numVertexes; ++j)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < G.numVertexes; ++v)
        {
            if (!visited[v] && dist[u] + G.arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G.arcs[u][v];
                path[v] = u;
            }
        }
    }

    for (int i = 0; i < G.numVertexes; ++i)
    {
        if (i != start)
        {
            printf("从顶点%d到顶点%d的最短路径长度为：%d\n", start, i, dist[i]);
        }
    }
}

int main()
{
    MGraph G;
    G.numVertexes = 6; // 设置顶点数
    G.numEdges = 9;    // 设置边数

    long long arcs[6][6] = {
        {0, 12, INFINITY, INFINITY, INFINITY, 16},
        {12, 0, 10, INFINITY, INFINITY, 7},
        {INFINITY, 10, 0, 3, 5, 6},
        {INFINITY, INFINITY, 3, 0, 4, INFINITY},
        {INFINITY, INFINITY, 5, 4, 0, 2},
        {16, 7, 6, INFINITY, 2, 0}};

    for (int i = 0; i < G.numVertexes; ++i)
    {
        for (int j = 0; j < G.numVertexes; ++j)
        {
            G.arcs[i][j] = arcs[i][j];
        }
    }
    Dijkstra(G, 0);
    return 0;
}
