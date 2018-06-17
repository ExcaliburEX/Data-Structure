/* 邻接表存储 - 拓扑排序算法 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
typedef int Vertex;
#define MaxVertexNum 100
#define INFINITY 65535
int TopOrder[MaxVertexNum];
typedef struct ENode *Edge;
struct ENode
{
    int v1, v2;
    int weight;
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
    //node->weight = E->weight;
    node->data = E->v2;
    node->next = LG->G[E->v1].FirstEdge;
    LG->G[E->v1].FirstEdge = node;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int Nv;
    cin >> Nv;
    Graph = CreateGraph(Nv);
    cin >> Graph->Ne;
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (int i = 0; i < Graph->Ne; i++)
        {
            cin >> E->v1 >> E->v2;
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

bool TopSort(LGraph Graph, Vertex TopOrder[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
    int Indegree[MaxVertexNum], cnt;
    Vertex V;
    PtrToAdjVNode W;
    //Queue Q = CreateQueue(Graph->Nv);
    queue<int> Q;
    stack<int> S;

    /* 初始化Indegree[] */
    for (V = 0; V < Graph->Nv; V++)
        Indegree[V] = 0;

    /* 遍历图，得到Indegree[] */
    for (V = 0; V < Graph->Nv; V++)
        for (W = Graph->G[V].FirstEdge; W; W = W->next)
            Indegree[W->data]++; /* 对有向边<V, W->AdjV>累计终点的入度 */

    /* 将所有入度为0的顶点入列 */
    for (V = 0; V < Graph->Nv; V++)
        if (Indegree[V] == 0)
            S.push(V);
            //Q.push(V);
           // AddQ(Q, V);

    /* 下面进入拓扑排序 */
    cnt = 0;
    while (!S.empty())
    {
        V = S.top();      /* 弹出一个入度为0的顶点 */
        S.pop();
        TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */
        /* 对V的每个邻接点W->AdjV */
        for (W = Graph->G[V].FirstEdge; W; W = W->next)
            if (--Indegree[W->data] == 0) /* 若删除V使得W->AdjV入度为0 */
                S.push(W->data);          /* 则该顶点入列 */
    }                                     /* while结束*/

    if (cnt != Graph->Nv)
        return false; /* 说明图中有回路, 返回不成功标志 */
    else
        return true;
}

int main()
{
    LGraph LG = BuildGraph();
    TopSort(LG, TopOrder);
    for (int i = 0; i < LG->Nv;i++)
        cout << TopOrder[i]<<" ";
      return 0;
}
