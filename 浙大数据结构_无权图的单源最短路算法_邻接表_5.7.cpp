/* 邻接表存储 - 无权图的单源最短路算法 */
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stack>
using namespace std;
#define MaxVertexNum 100
typedef int Vertex;
typedef int Weight;
typedef char DataType;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    int AdjV;
    int weight;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
    int data;
}Adjlist[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    Adjlist G;
};
typedef PtrToGNode LGraph;


typedef struct Node *PtrToNode;
struct  Node
{
    int data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode *Queue;
struct QNode{
    Position Front, Rear;
    int MaxSize;
};

bool IsEmpty(Queue Q)
{
    return (Q->Front == NULL);
}

Queue CreateQueue(int Size)
{
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->Front = Q->Rear = NULL;
    Q->MaxSize = Size;
    return Q;
}

bool AddQ(Queue Q,int x)
{
    Position q=(Position)malloc(sizeof(struct Node));
    q->data = x;
    q->Next = NULL;
    if(!Q->Front)
        Q->Front = Q->Rear = q;
    else
    {
        Q->Rear->Next = q;
        Q->Rear = q;
    }
    return true;
}

int DeleteQ(Queue Q)
{
    Position p;
    int FData;
    if(IsEmpty(Q))
    {
        cout << "队列已经空！";
        return false;
    }
    else
    {
        p = Q->Front;
        if(Q->Front==Q->Rear)
            Q->Rear = Q->Front = NULL;
        else
            Q->Front = Q->Front->Next;
        FData = p->data;
        free(p);
        return FData;
    }
}


LGraph CreateGraph(int Vertex)
{
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = Vertex;
    Graph->Ne = 0;
    for (int i = 0; i < Graph->Nv;i++)
        Graph->G[i].FirstEdge = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph,int v1,int v2)
{
    PtrToAdjVNode node;
    node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->AdjV = v2;
    //node->weight = w;
    node->Next = Graph->G[v1].FirstEdge;
    Graph->G[v1].FirstEdge = node;

   /* node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->AdjV = v1;
    node->weight = w;
    node->Next = Graph->G[v2].FirstEdge;
    Graph->G[v2].FirstEdge = node;
    */
}


LGraph BuildGraph()
{
    LGraph Graph;
    int Nv;
    cin >> Nv;
    Graph=CreateGraph(Nv);
    cin >> Graph->Ne;
    if(Graph->Ne!=0)
    {
        for (int i = 0; i < Graph->Ne;i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2;
            InsertEdge(Graph, v1, v2);
        }
    }
    return Graph;
}

/* dist[]和path[]全部初始化为-1 */


void Unweighted(LGraph Graph,int dist[],int path[],int S)
{
    Queue Q;
    PtrToAdjVNode w;
    int V;
    Q = CreateQueue(Graph->Nv);
    dist[S] = 0;//important!
    AddQ(Q, S);
    while(!IsEmpty(Q))
    {
        V = DeleteQ(Q);
        for (w = Graph->G[V].FirstEdge; w;w=w->Next)
            if(dist[w->AdjV]==-1)
            {
                dist[w->AdjV]=dist[V]+1;
                path[w->AdjV] = V;
                AddQ(Q, w->AdjV);
            }
    }
}


int main()
{
    LGraph Graph = BuildGraph();
    int dist[MaxVertexNum];
    int path[MaxVertexNum];
    for (int i = 0; i < Graph->Nv;i++)
    {
        dist[i] = -1;
        path[i] = -1;
    }
    Unweighted(Graph, dist, path, 3);
    for (int i = 0; i < Graph->Nv;i++)
        cout << dist[i] << " ";
        cout<<endl;
    for (int i = 0; i < Graph->Nv;i++)
        cout << path[i] << " ";
        cout<<endl;
    stack<int> s;
    int k=Graph->Nv-1;
    while(path[k]!=-1)
    {
        s.push(k);
        k=path[k];
    }
    while(!s.empty()){
        cout << s.top()<<" ";
        s.pop();
    }
    return 0;
}
