#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
#define MaxVertexNum 100
#define INFINITY 65535
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
        cin>>Graph->Data[V];
    return Graph;
}


void visit(Vertex V){
    cout<<"正在访问结点："<<V<<endl;
}

bool IsEdge(MGraph Graph,Vertex V,Vertex W){
    return ((Graph->G[V][W]<INFINITY)&&(Graph->G[V][W]>0));
}

void DFS(MGraph Graph,Vertex V){
    Visited[V]=true;
    visit(V);
    for(int j=0;j<Graph->Nv;j++){
        if(IsEdge(Graph,V,j)&&!Visited[j])
            DFS(Graph,j);
    }
}


int main(){
    MGraph Graph=BuildGraph();
    for(int i=0;i<Graph->Nv;i++)
        Visited[i]=false;
    for(int i=0;i<Graph->Nv;i++){
        if(!Visited[i])
            DFS(Graph,i);
    }

    return 0;
}

