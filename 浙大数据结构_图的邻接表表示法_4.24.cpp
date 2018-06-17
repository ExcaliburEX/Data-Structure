#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char Datatype;

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
    Datatype Data;
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
void  InsertEdge(LGraph Graph,Edge E){
        PtrToAdjVNode NewNode;
        NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->Adjv=E->v2;
        NewNode->Weight=E->Weight;
        NewNode->Next=Graph->G[E->v1].FirstEdge;
        Graph->G[E->v1].FirstEdge=NewNode;
        /* 若是无向图需要再进行插入*/

        NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        NewNode->Adjv=E->v1;
        NewNode->Weight=E->Weight;
        NewNode->Next=Graph->G[E->v2].FirstEdge;
        Graph->G[E->v2].FirstEdge=NewNode;


}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    int Nv;
    cout<<"Please input the number of Vertex:\n";
    cin>>Nv;
    Graph=CreateGraph(Nv);
    cout<<"Please input the number of Edge:\n";
    cin>>Graph->Ne;
    if(Graph->Ne!=0){
    cout<<"Please input the v1 v2 and Weight:\n";
        E=(Edge)malloc(sizeof(struct ENode));
        for(int i=0;i<Graph->Ne;i++){
            cin>>E->v1>>E->v2>>E->Weight;
            InsertEdge(Graph,E);
        }
    }
    cout<<"Please input the weight of Vertex:\n";
    for(Vertex V=0;V<Graph->Nv;V++)
        cin>>Graph->G[V].Data;
    return Graph;
}
int main(){
    freopen("1.txt","r",stdin);
    LGraph Graph=BuildGraph();
    cout<<"Now we can see the Adjacency List:\n";
    for(int i=0;i<Graph->Nv;i++){
        cout<<"节点"<<i<<":";
        while(Graph->G[i].FirstEdge){
            cout<<"["<<Graph->G[i].FirstEdge->Adjv<<","<<Graph->G[i].FirstEdge->Weight<<"]"<<" ";
            Graph->G[i].FirstEdge=Graph->G[i].FirstEdge->Next;
            cout<<"->";
        }
        cout<<"#";
        cout<<endl;
    }
    return 0;
}
