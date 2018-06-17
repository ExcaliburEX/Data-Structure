/* 邻接表存储 - Kruskal最小生成树算法 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<algorithm>
using namespace std;
typedef int Vertex;
typedef int WeightType;
#define ERROR -1
#define MaxVertexNum 100
#define INFINITY 65535

typedef struct ENode *Edge;
struct ENode
{
    int v1, v2;
    int weight;
};
typedef struct GNode *MGraph;
struct GNode
{
    int Nv;
    int Ne;
    int G[MaxVertexNum][MaxVertexNum];
};

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    int data;
    PtrToAdjVNode next;
    int weight;
};

typedef struct VNode
{
    PtrToAdjVNode FirstEdge;
} adjlist[MaxVertexNum];

typedef struct LNode *LGraph;
struct LNode
{
    int Nv;
    int Ne;
    adjlist G;
};
long long  TotalWeight;
LGraph CreateGraph(int vertexnum)
{
    LGraph LG = (LGraph)malloc(sizeof(struct LNode));
    LG->Nv = vertexnum;
    LG->Ne = 0;
    for (int i = 0; i < LG->Nv; i++)
        LG->G[i].FirstEdge = NULL;
    return LG;
}

void InsertEdge(LGraph LG, Edge E)
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
/*-------------------- 顶点并查集定义 --------------------*/
typedef Vertex ElementType;                /* 默认元素可以用非负整数表示 */
typedef Vertex SetName;                    /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MaxVertexNum]; /* 假设集合元素下标从0开始 */
//
//void InitializeVSet(SetType S, int N)
//{ /* 初始化并查集 */
//    ElementType X;
//
//    for (X = 0; X < N; X++)
//        S[X] = -1;
//}
//
//void Union(SetType S, SetName Root1, SetName Root2)
//{ /* 这里默认Root1和Root2是不同集合的根结点 */
//    /* 保证小集合并入大集合 */
//    if (S[Root2] < S[Root1])
//    {                         /* 如果集合2比较大 */
//        S[Root2] += S[Root1]; /* 集合1并入集合2  */
//        S[Root1] = Root2;
//    }
//    else
//    {                         /* 如果集合1比较大 */
//        S[Root1] += S[Root2]; /* 集合2并入集合1  */
//        S[Root2] = Root1;
//    }
//}
//
//SetName Find(SetType S, ElementType X)
//{                 /* 默认集合元素全部初始化为-1 */
//    if (S[X] < 0) /* 找到集合的根 */
//        return X;
//    else
//        return S[X] = Find(S, S[X]); /* 路径压缩 */
//}
//
//bool CheckCycle(SetType VSet, Vertex V1, Vertex V2)
//{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
//    Vertex Root1, Root2;
//
//    Root1 = Find(VSet, V1); /* 得到V1所属的连通集名称 */
//    Root2 = Find(VSet, V2); /* 得到V2所属的连通集名称 */
//
//    if (Root1 == Root2) /* 若V1和V2已经连通，则该边不能要 */
//        return false;
//    else
//    { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
//        Union(VSet, Root1, Root2);
//        return true;
//    }
//}
///*-------------------- 并查集定义结束 --------------------*/
//
///*-------------------- 边的最小堆定义 --------------------*/
//void PercDown(Edge ESet, int p, int N)
//{   /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
//    /* 将N个元素的边数组中以ESet[p]为根的子堆调整为关于Weight的最小堆 */
//    int Parent, Child;
//    struct ENode X;
//
//    X = ESet[p]; /* 取出根结点存放的值 */
//    for (Parent = p; (Parent * 2 + 1) < N; Parent = Child)
//    {
//        Child = Parent * 2 + 1;
//        if ((Child != N - 1) && (ESet[Child].weight > ESet[Child + 1].weight))
//            Child++; /* Child指向左右子结点的较小者 */
//        if (X.weight <= ESet[Child].weight)
//            break; /* 找到了合适位置 */
//        else       /* 下滤X */
//            ESet[Parent] = ESet[Child];
//    }
//    ESet[Parent] = X;
//}
//
//void InitializeESet(LGraph Graph, Edge ESet)
//{ /* 将图的边存入数组ESet，并且初始化为最小堆 */
//    Vertex V;
//    PtrToAdjVNode W;
//    int ECount;
//
//    /* 将图的边存入数组ESet */
//    ECount = 0;
//    for (V = 0; V < Graph->Nv; V++)
//        for (W = Graph->G[V].FirstEdge; W; W = W->next)
//            if (V < W->data)
//            { /* 避免重复录入无向图的边，只收V1<V2的边 */
//                ESet[ECount].v1 = V;
//                ESet[ECount].v2= W->data;
//                ESet[ECount++].weight = W->weight;
//            }
//    /* 初始化为最小堆 */
//    for (ECount = Graph->Ne / 2; ECount >= 0; ECount--)
//        PercDown(ESet, ECount, Graph->Ne);
//}
//
//int GetEdge(Edge ESet, int CurrentSize)
//{ /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */
//
//    /* 将最小边与当前堆的最后一个位置的边交换 */
//    swap(ESet[0], ESet[CurrentSize - 1]);
//    /* 将剩下的边继续调整成最小堆 */
//    PercDown(ESet, 0, CurrentSize - 1);
//
//    return CurrentSize - 1; /* 返回最小边所在位置 */
//}
///*-------------------- 最小堆定义结束 --------------------*/
//
//LGraph Kruskal(LGraph Graph, LGraph MST)
//{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
//    int ECount, NextEdge;
//    SetType VSet; /* 顶点数组 */
//    Edge ESet;    /* 边数组 */
//
//    InitializeVSet(VSet, Graph->Nv); /* 初始化顶点并查集 */
//    ESet = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
//    InitializeESet(Graph, ESet); /* 初始化边的最小堆 */
//    /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
//    MST = CreateGraph(Graph->Nv);
//    TotalWeight = 0; /* 初始化权重和     */
//    ECount = 0;      /* 初始化收录的边数 */
//
//    NextEdge = Graph->Ne; /* 原始边集的规模 */
//    while (ECount < Graph->Nv - 1)
//    {                                       /* 当收集的边不足以构成树时 */
//        NextEdge = GetEdge(ESet, NextEdge); /* 从边集中得到最小边的位置 */
//        cout<<NextEdge<<" "<<ECount<<endl;
//        if (NextEdge < 0)                   /* 边集已空 */
//            break;
//        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
//        if (CheckCycle(VSet, ESet[NextEdge].v1, ESet[NextEdge].v2) == true)
//        {
//            /* 将该边插入MST */
//            InsertEdge(MST, ESet + NextEdge);
//            TotalWeight += ESet[NextEdge].weight; /* 累计权重 */
//            ECount++;                             /* 生成树中边数加1 */
//        }
//    }
//    if (ECount < Graph->Nv - 1)
//        TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */
//
//    return MST;
//}


void InitializeVSet(SetType S,int N)
{
    for (int i = 0; i < N;i++)
        S[i] = -1;
}

void Union(SetType S,SetName Root1,SetName Root2)
{
    if(S[Root1]<S[Root2])
    {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }

    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }

}

SetName Find(SetType S,SetName X)
{
    if(S[X]<0)
        return X;
    else
        return S[X] = Find(S, S[X]);
}

bool CheckCycle(SetType VSet,Vertex V1,Vertex V2)
{
    SetName Root1,Root2;
    Root1 = Find(VSet, V1);
    Root2 = Find(VSet, V2);
    if(Root1==Root2)
        return false;
    else
    {
        Union(VSet, Root1, Root2);
        return true;
    }
}

void PercDown(Edge ESet,int p,int N)
{
    int parent, child;
    struct ENode X;
    X = ESet[p];
    for (parent = p; (parent * 2 + 1) < N; parent = child)
    {
        child = parent * 2 + 1;
        while ((child != N - 1)&&(ESet[child].weight>ESet[child+1].weight))
            child++;
        if(X.weight<=ESet[child].weight)
            break;
        else
            ESet[parent] = ESet[child];
    }
    ESet[parent] = X;
}

void InitializeESet(LGraph Graph,Edge ESet)
{
    int ECount = 0;
    for (Vertex V = 0; V < Graph->Nv;V++)
        for (PtrToAdjVNode W = Graph->G[V].FirstEdge; W;W=W->next)
            if(V<W->data)
            {
                ESet[ECount].v1 = V;
                ESet[ECount].v2 = W->data;
                ESet[ECount++].weight = W->weight;
            }
    for (ECount = Graph->Ne / 2; ECount >= 0;ECount--)
        PercDown(ESet, ECount, Graph->Ne);
}

int GetEdge(Edge ESet,int CurrentSize)
{
    swap(ESet[0],ESet[CurrentSize-1]);
    PercDown(ESet,0,CurrentSize-1);
    return CurrentSize - 1;
}

LGraph Kruskal(LGraph Graph,LGraph MST)
{
    int ECount, NextEdge;
    SetType VSet;
    Edge ESet;
    InitializeVSet(VSet, Graph->Nv);
    ESet = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
    InitializeESet(Graph, ESet);
    MST = CreateGraph(Graph->Nv);
    TotalWeight = 0;
    ECount = 0;
    NextEdge = Graph->Ne;
    while(ECount<Graph->Nv-1)
    {
        NextEdge = GetEdge(ESet, NextEdge);
        if(NextEdge<0)
            break;
        if(CheckCycle(VSet,ESet[NextEdge].v1,ESet[NextEdge].v2)==true)
        {
            InsertEdge(MST, ESet + NextEdge);
            TotalWeight += ESet[NextEdge].weight;
            ECount++;
        }
    }
    if(ECount<Graph->Nv-1)
        TotalWeight = -1;
    return MST;
}

int main()
{
    LGraph LG1;
    LGraph LG;
    Edge E;
    int nv;
    cin >> nv;
    LG1 = CreateGraph(nv);
    cin >> LG1->Ne;
    E = (Edge)malloc(sizeof(struct ENode));
    for (int i = 0; i < LG1->Ne;i++)
    {
        cin>>E->v1>>E->v2>>E->weight;
        InsertEdge(LG1, E);
    }

    LG = Kruskal(LG1, LG);
    /*PtrToAdjVNode w;
    for (int i = 0; i < LG->Nv; i++)
    {
        w = LG->G[i].FirstEdge;
        while (w)
        {
            printf("%d:(%d,%d) ", i, w->data, w->weight);
            w = w->next;
        }
        cout << endl;
    }*/
    cout << TotalWeight;
    return 0;
}

