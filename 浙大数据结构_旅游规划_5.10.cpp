/* 邻接矩阵存储 - 有权图的单源最短路算法 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
typedef int Vertex;
#define ERROR -1
#define MaxVertexNum 100
#define INFINITY 65535
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    int G[MaxVertexNum][MaxVertexNum];
    int w[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;
int cost[MaxVertexNum];
int S, D;
int count[MaxVertexNum];
MGraph CreateGraph(int VertexNum)
{
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (int i = 0; i < VertexNum; i++)
    {
        for (int j = 0; j < VertexNum; j++)
        {
            //if(i==j)
            //Graph->G[i][j] = 0;
            //else
            Graph->G[i][j] = INFINITY;
            Graph->w[i][j] = INFINITY;
        }
    }
    return Graph;
}

MGraph BuildGraph()
{
    MGraph Graph;
    int n;
    cin >> n;
    Graph = CreateGraph(n);
    cin >> Graph->Ne;
    cin >> S >> D;
    if (Graph->Ne != 0)
    {
        for (int i = 0; i < Graph->Ne; i++)
        {
            int v1, v2, w, m;
            cin >> v1 >> v2 >> w >> m;
            Graph->G[v1][v2] = w;
            Graph->G[v2][v1] = w;
            Graph->w[v1][v2] = m;
            Graph->w[v2][v1] = m;
        }
    }
    return Graph;
}

//
//Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
//{ /* 返回未被收录顶点中dist最小者 */
//    Vertex MinV, V;
//    int MinDist = INFINITY;
//
//    for (V = 0; V < Graph->Nv; V++)
//    {
//        if (collected[V] == false && dist[V] < MinDist)
//        {
//            /* 若V未被收录，且dist[V]更小 */
//            MinDist = dist[V]; /* 更新最小距离 */
//            MinV = V;          /* 更新对应顶点 */
//        }
//    }
//    if (MinDist < INFINITY) /* 若找到最小dist */
//        return MinV;        /* 返回对应的顶点下标 */
//    else
//        return ERROR; /* 若这样的顶点不存在，返回错误标记 */
//}
//
//bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
//{
//
//    int collected[MaxVertexNum];
//    Vertex V, W;
//
//    /* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
//    for (V = 0; V < Graph->Nv; V++)
//    {
//        dist[V] = Graph->G[S][V];
//        if (dist[V] < INFINITY)
//            path[V] = S;
//        else
//            path[V] = -1;
//        collected[V] = false;
//    }
//    /* 先将起点收入集合 */
//    dist[S] = 0;
//    collected[S] = true;
//
//    while (1)
//    {
//        /* V = 未被收录顶点中dist最小者 */
//        V = FindMinDist(Graph, dist, collected);
//        if (V == ERROR)                 /* 若这样的V不存在 */
//            break;                      /* 算法结束 */
//        collected[V] = true;            /* 收录V */
//        for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
//            /* 若W是V的邻接点并且未被收录 */
//            if (collected[W] == false && Graph->G[V][W] < INFINITY)
//            {
//                if (Graph->G[V][W] < 0) /* 若有负边 */
//                    return false;       /* 不能正确解决，返回错误标记 */
//                /* 若收录V使得dist[W]变小 */
//                if (dist[V] + Graph->G[V][W] < dist[W])
//                {
//                    dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
//                    path[W] = V;                        /* 更新S到W的路径 */
//                }
//            }
//    }            /* while结束*/
//    return true; /* 算法执行完毕，返回正确标记 */
//}
//
int FindMinDist(MGraph Graph, int dist[], int collected[])
{
    int MinDist = INFINITY;
    int MinV;
    for (int i = 0; i < Graph->Nv; i++)
    {
        if (!collected[i] && dist[i] < MinDist)
        {
            MinDist = dist[i];
            MinV = i;
        }
    }
    if (MinDist < INFINITY)
        return MinV;
    else
        return ERROR;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], int S)
{
    int v, w;
    int collected[MaxVertexNum];

    for (int i = 0; i < Graph->Nv; i++)
    {
        cost[i] = Graph->w[S][i];
        dist[i] = Graph->G[S][i];
        if (dist[i] < INFINITY)
        {
            path[i] = S; //易错点
            //count[i] = S;
        }
        else
        {
            path[i] = -1;
            //count[i] = -1;
        }

        collected[i] = false;
    }
    count[S] = 1;
    cost[S] = 0;
    dist[S] = 0;
    collected[S] = true;
    while (1)
    {
        v = FindMinDist(Graph, dist, collected);
        if (v == ERROR)
            break;
        collected[v] = true;
        for (w = 0; w < Graph->Nv; w++)
            if (!collected[w] && Graph->G[v][w] < INFINITY)
            {
                if (Graph->G[v][w] < 0)
                    return false;
                if (dist[v] + Graph->G[v][w] < dist[w])
                {
                    dist[w] = dist[v] + Graph->G[v][w];
                    path[w] = v;
                    cost[w] = cost[v] + Graph->w[v][w];
                    count[w] = count[v];
                }
                else if ((dist[v] + Graph->G[v][w] == dist[w])&& (cost[v] + Graph->w[v][w] < cost[w]))
                {
                    cost[w] = cost[v] + Graph->w[v][w];
                    count[w] += count[v];
                }
            }
    }
    return true;
}

int main()
{

    MGraph Graph = BuildGraph();
    int dist[Graph->Nv], path[Graph->Nv];
    Dijkstra(Graph, dist, path, S);

    cout << dist[D] << " " << cost[D];
    /*  stack<int> s;
    int k = Graph->Nv - 1;
    while (path[k] != -1)
    {
        s.push(k);
        k = path[k];
    }
    cout << k << " ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }*/
    return 0;
}
