#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX_NUM 100 // 最大顶点数
#define INFINITY INT_MAX   // 定义无穷大

typedef struct
{
    int vertex[MAX_VERTEX_NUM];               // 顶点数组
    long long arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵，用于表示顶点间的边
    int numVertexes;                          // 顶点数量
    int numEdges;                             // 边的数量
} MGraph;

// Dijkstra 算法函数，计算顶点 start 到其他顶点的最短路径
void Dijkstra(MGraph G, int start)
{
    int dist[MAX_VERTEX_NUM];    // 存储 start 到各顶点的最短距离
    int path[MAX_VERTEX_NUM];    // 存储最短路径的前驱节点
    int visited[MAX_VERTEX_NUM]; // 标记顶点是否已访问

    // 初始化
    for (int i = 0; i < G.numVertexes; ++i)
    {
        dist[i] = G.arcs[start][i];                           // 初始化距离数组
        path[i] = (G.arcs[start][i] < INFINITY) ? start : -1; // 初始化路径数组
        visited[i] = 0;                                       // 初始化标记数组
    }

    dist[start] = 0;    // 初始节点到自身距离为0
    visited[start] = 1; // 标记起始节点已访问

    // 循环更新最短路径
    for (int i = 1; i < G.numVertexes; ++i)
    {
        int minDist = INFINITY;
        int u = start;

        // 寻找当前未访问节点中距离起始节点最近的节点
        for (int j = 0; j < G.numVertexes; ++j)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = 1; // 标记该节点已访问

        // 更新最短路径
        for (int v = 0; v < G.numVertexes; ++v)
        {
            if (!visited[v] && dist[u] + G.arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G.arcs[u][v];
                path[v] = u;
            }
        }
    }

    // 打印最短路径
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

    // 邻接矩阵表示的图的初始化
    long long arcs[6][6] = {
        {0, 12, INFINITY, INFINITY, INFINITY, 16},
        {12, 0, 10, INFINITY, INFINITY, 7},
        {INFINITY, 10, 0, 3, 5, 6},
        {INFINITY, INFINITY, 3, 0, 4, INFINITY},
        {INFINITY, INFINITY, 5, 4, 0, 2},
        {16, 7, 6, INFINITY, 2, 0}};

    // 将邻接矩阵赋值给图
    for (int i = 0; i < G.numVertexes; ++i)
    {
        for (int j = 0; j < G.numVertexes; ++j)
        {
            G.arcs[i][j] = arcs[i][j];
        }
    }

    // 从顶点0开始计算最短路径
    Dijkstra(G, 0);

    return 0;
}
