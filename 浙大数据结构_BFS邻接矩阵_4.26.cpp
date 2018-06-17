/* 邻接矩阵存储的图 - BFS */

/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/
/* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MaxSize 100
using namespace std;
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
#define MaxVertexNum 100
#define INFINITY 65536
bool Visited[MaxVertexNum];

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex v1,v2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum){
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(int i=0;i<Graph->Nv;i++){
        for(int j=0;j<Graph->Nv;j++){
            if(i==j)Graph->G[i][j]=0;
            else Graph->G[i][j]=INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->v1][E->v2]=E->Weight;
    Graph->G[E->v2][E->v1]=E->Weight;
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    int Nv;
    //cout<<"请输入顶点数：\n";
    cin>>Nv;
    Graph=CreateGraph(Nv);
   // cout<<"请输入边数：\n";
    cin>>Graph->Ne;
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        //cout<<"请输入v1,v2：\n";
        for(int i=0;i<Graph->Ne;i++){
            cin>>E->v1>>E->v2;
            InsertEdge(Graph,E);
        }
    }
    //cout<<"请输入顶点的权重：\n";
    //for(Vertex V=0;V<Graph->Nv;V++)
     //   cin>>Graph->Data[V];
    return Graph;
}

typedef struct QNode *PtrToQNode;
struct QNode{
    int data;
    PtrToQNode Next;
};
typedef PtrToQNode Position;

typedef struct QueueNode *Queue;
struct QueueNode{
    Position Front,Rear;
    int Maxsize;
};

bool IsEmpty(Queue Q){
    return (Q->Front==NULL);
}

Queue CreateQueue(int Maxsize){
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QueueNode));
    Q->Front=Q->Rear=NULL;
    Q->Maxsize=Maxsize;
    return Q;
}

bool AddQ(Queue Q,int X){
    Position q;
    q=(Position)malloc(sizeof(struct QNode));
    q->data=X;
    q->Next=NULL;
    if(Q->Front==NULL)
        Q->Front=Q->Rear=q;
    else{
        Q->Rear->Next=q;
        Q->Rear=q;
    }
    return true;
}

int DeleteQ(Queue Q){
    if(IsEmpty(Q)){
        cout<<"空";
        return -1;
    }
    Position cell;
    int elem;
    cell=Q->Front;
    elem=cell->data;
    if(Q->Front==Q->Rear)
        Q->Front=Q->Rear=NULL;
    else
        Q->Front=Q->Front->Next;
    free(cell);
    return elem;
}

void Visit(Vertex V){
    cout<<"正在访问结点："<<V<<endl;
}


bool IsEdge( MGraph Graph, Vertex V, Vertex W )
{
    return (Graph->G[V][W]<INFINITY);
    //&&(Graph->G[V][W]>0);
}


void BFS(MGraph Graph,Vertex S,void (*Visit)(Vertex)){
    Vertex v,w;
    Queue Q;
    Q=CreateQueue(MaxSize);
    //Visit(S);
    Visited[S]=true;
    AddQ(Q,S);
    while(!IsEmpty(Q)){
        v=DeleteQ(Q);
        Visit(v);
        for(w=0;w<Graph->Nv;w++){
            if(!Visited[w]&&IsEdge(Graph,v,w)){
               // Visit(w);
                Visited[w]=true;
                AddQ(Q,w);
            }
        }
    }
}

int main(){
    MGraph Graph=BuildGraph();
    for(int i=0;i<Graph->Nv;i++)
        Visited[i]=false;
    for(int i=0;i<Graph->Nv;i++){
        if(!Visited[i]){
        BFS(Graph,i,Visit);
        }
    }

    return 0;
}
