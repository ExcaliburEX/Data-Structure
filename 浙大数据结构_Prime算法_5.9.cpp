/* 邻接矩阵存储 - Prim最小生成树算法 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef int Vertex;
typedef int WeightType;
#define ERROR -1
#define MaxVertexNum 5000
#define INFINITY 65535

typedef struct ENode *Edge;
struct ENode{
    int v1, v2;
    int weight;
};
typedef struct GNode *MGraph;
struct GNode{
    int Nv;
    int Ne;
    int G[MaxVertexNum][MaxVertexNum];
};

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    int data;
    PtrToAdjVNode next;
    int weight;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
} adjlist[MaxVertexNum];

typedef struct LNode *LGraph;
struct LNode{
    int Nv;
    int Ne;
    adjlist G;
};
int TotalWeight;
LGraph CreateGraph(int vertexnum)
{
    LGraph LG = (LGraph)malloc(sizeof(struct LNode));
    LG->Nv = vertexnum;
    LG->Ne = 0;
    for (int i = 0; i < LG->Nv;i++)
        LG->G[i].FirstEdge = NULL;
    return LG;
}

void InsertEdge(LGraph LG,Edge E)
{
    PtrToAdjVNode node;
    node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->weight = E->weight;
    node->data = E->v1;
    node->next = LG->G[E->v2].FirstEdge;
    LG->G[E->v2].FirstEdge = node;

    node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->weight = E->weight;
    node->data = E->v2;
    node->next = LG->G[E->v1].FirstEdge;
    LG->G[E->v1].FirstEdge = node;
}

//Vertex FindMinDist(MGraph Graph, WeightType dist[])
//{ /* 返回未被收录顶点中dist最小者 */
//    Vertex MinV, V;
//    WeightType MinDist = INFINITY;
//
//    for (V = 0; V < Graph->Nv; V++)
//    {
//        if (dist[V] != 0 && dist[V] < MinDist)
//        {
//            /* 若V未被收录，且dist[V]更小 */
//            MinDist = dist[V]; /* 更新最小距离 */
//            MinV = V;          /* 更新对应顶点 */
//        }
//    }
//    if (MinDist < INFINITY) /* 若找到最小dist */
//        return MinV;        /* 返回对应的顶点下标 */
//    else
//        return ERROR; /* 若这样的顶点不存在，返回-1作为标记 */
//}
//
//LGraph Prim(MGraph Graph, LGraph MST)
//{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
//    WeightType dist[MaxVertexNum];
//    Vertex parent[MaxVertexNum], V, W;
//    int VCount;
//    Edge E;
//
//    /* 初始化。默认初始点下标是0 */
//    for (V = 0; V < Graph->Nv; V++)
//    {
//        /* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
//        dist[V] = Graph->G[0][V];
//        parent[V] = 0; /* 暂且定义所有顶点的父结点都是初始点0 */
//    }
//    TotalWeight = 0; /* 初始化权重和     */
//    VCount = 0;      /* 初始化收录的顶点数 */
//    /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
//    MST = CreateGraph(Graph->Nv);
//    E = (Edge)malloc(sizeof(struct ENode)); /* 建立空的边结点 */
//
//    /* 将初始点0收录进MST */
//    dist[0] = 0;
//    VCount++;
//    parent[0] = -1; /* 当前树根是0 */
//
//    while (1)
//    {
//        V = FindMinDist(Graph, dist);
//        /* V = 未被收录顶点中dist最小者 */
//        if (V == ERROR) /* 若这样的V不存在 */
//            break;      /* 算法结束 */
//
//        /* 将V及相应的边<parent[V], V>收录进MST */
//        E->v1 = parent[V];
//        E->v2 = V;
//        E->weight = dist[V];
//        //printf("(%d,%d) %d\n",parent[V],V,dist[V]);
//        InsertEdge(MST, E);
//        TotalWeight += dist[V];
//        dist[V] = 0;
//        VCount++;
//
//        for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
//            if (dist[W] != 0 && Graph->G[V][W] < INFINITY)
//            {
//                /* 若W是V的邻接点并且未被收录 */
//                if (Graph->G[V][W] < dist[W])
//                {
//                    /* 若收录V使得dist[W]变小 */
//                    dist[W] = Graph->G[V][W]; /* 更新dist[W] */
//                    parent[W] = V;            /* 更新树 */
//                }
//            }
//    }                       /* while结束*/
//    if (VCount < Graph->Nv) /* MST中收的顶点不到|V|个 */
//        TotalWeight = ERROR;
//
//    return MST; /* 算法执行完毕，返回最小权重和或错误标记 */
//}



int FindMinDist(MGraph Graph,int dist[])
{
    int MinDist=INFINITY;
    int MinV;
    for (int i = 0; i < Graph->Nv;i++){
        if(dist[i]!=0&&dist[i]<MinDist)
        {
            MinDist=dist[i];
            MinV = i;
        }
    }
    if(MinDist<INFINITY)
        return MinV;
    else
        return ERROR;
}

LGraph Prim(MGraph Graph, LGraph MST)
{
    int dist[MaxVertexNum],parent[MaxVertexNum];
    int VCount=0;
    Edge E;
    TotalWeight = 0;
    for (int i = 0; i < Graph->Nv;i++)
    {
        dist[i]=Graph->G[0][i];
        parent[i] = 0;
    }
    MST = CreateGraph(Graph->Nv);
    E=(Edge)malloc(sizeof(struct ENode));
    dist[0] = 0;
    parent[0] = -1;
    VCount++;
    int V;
    while(1)
    {
        V = FindMinDist(Graph, dist);
        if(V==ERROR)
            break;
        E->v1=parent[V];
        E->v2=V;
        E->weight = dist[V];
        InsertEdge(MST, E);
        VCount++;
        TotalWeight += dist[V];
        dist[V] = 0;
        for (int w = 0; w < Graph->Nv;w++)
        {
            if(dist[w]!=0&&Graph->G[V][w]<INFINITY)
            {
                if(Graph->G[V][w]<dist[w])
                {
                    dist[w]=Graph->G[V][w];
                    parent[w] = V;
                }
            }
        }
    }
    if(VCount<Graph->Nv)
        TotalWeight = ERROR;
    return MST;

}

int main()
{
    MGraph MG;
    LGraph LG;
    MG=(MGraph)malloc(sizeof(struct GNode));
    MG->Ne=0;
    cin >> MG->Nv;
    for (int i = 0; i < MG->Nv;i++){
        for (int j = 0; j < MG->Nv;j++){
            MG->G[i][j] = INFINITY;
        }
    }
    cin >> MG->Ne;
    for (int i = 0; i < MG->Ne;i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        //v1--,v2--;
        MG->G[v1][v2] = w;
        MG->G[v2][v1] = w;
    }

     LG=Prim(MG, LG);
     PtrToAdjVNode w;
    for (int i = 0; i < LG->Nv;i++)
    {
        w=LG->G[i].FirstEdge;
        while(w)
        {
            printf("%d:(%d,%d) ",i,w->data,w->weight);
            w=w->next;
        }
        cout << endl;
    }
    cout<<TotalWeight;

    return 0;
}
