/* 邻接表存储的图 - DFS */
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MaxVertexNum 100
bool Visited[MaxVertexNum];
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex v1,v2;
    WeightType Weight;
};

typedef PtrToENode Edge;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex Adjv;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}Adjlist[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    Adjlist G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum){
    Vertex V;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge=NULL;
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewNode;
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv=E->v2;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge=NewNode;
/*
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->Adjv=E->v1;
    NewNode->Weight=E->Weight;
    NewNode->Next=Graph->G[E->v2].FirstEdge;
    Graph->G[E->v2].FirstEdge=NewNode;*/
}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    int Nv;
    cin>>Nv;
    Graph=CreateGraph(Nv);
    cin>>Graph->Ne;
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(int i=0;i<Graph->Ne;i++){
            cin>>E->v1>>E->v2>>E->Weight;
            InsertEdge(Graph,E);
        }
    }
    for(Vertex V=0;V<Graph->Nv;V++)
        cin>>Graph->G[V].Data;
    return Graph;
}

void Visit(Vertex V){
    cout<<"正在访问结点："<<V<<endl;
}

void DFS(LGraph Graph,Vertex V,void (*Visit)(Vertex)){
        PtrToAdjVNode w;
        Visit(V);
        Visited[V]=true;
        for(w=Graph->G[V].FirstEdge;w;w=w->Next){
            if(!Visited[w->Adjv])
                DFS(Graph,w->Adjv,Visit);
        }
}



int main(){
    freopen("1.txt","r",stdin);
    LGraph Graph=BuildGraph();
   for(int i=0;i<Graph->Nv;i++)
       Visited[i]=false;

    for(int i=0;i<Graph->Nv;i++)
        if(!Visited[i])
        DFS(Graph,i,Visit);
    return 0;
}

