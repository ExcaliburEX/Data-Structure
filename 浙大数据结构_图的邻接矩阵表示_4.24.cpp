#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MaxVertexnum 100
#define INFINITY 65536
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex v1,v2;
    WeightType weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexnum][MaxVertexnum];
    DataType Data[MaxVertexnum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int Vertexnum){
    Vertex v,w;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=Vertexnum;
    Graph->Ne=0;
    for(v=0;v<Graph->Nv;v++)
        for(w=0;w<Graph->Nv;w++){
            if(v!=w)Graph->G[v][w]=INFINITY;//�Խ���Ԫ��Ϊ0
            else Graph->G[v][w]=0;
        }

    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->v1][E->v2]=E->weight;
    //Graph->G[E->v2][E->v1]=E->weight;//����ͼ
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;//������������ݽ�������
    int Nv;
    cin>>Nv;
    Graph=CreateGraph(Nv);
    cin>>Graph->Ne;
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(int i=0;i<Graph->Ne;i++){
            cin>>E->v1>>E->v2>>E->weight;
            InsertEdge(Graph,E);
        }
    }
    for(V=0;V<Graph->Nv;V++)cin>>Graph->Data[V];
    return Graph;
}

int main(){
    MGraph Graph=BuildGraph();
    //����ڽӾ���
    cout<<"�ڽӾ�������:"<<endl;
    for(int i=0;i<Graph->Nv;i++){
        for(int j=0;j<Graph->Nv;j++){
            cout<<Graph->G[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"������������:"<<endl;
    for(int i=0;i<Graph->Nv;i++){
        cout<<Graph->Data[i]<<" ";//�����������
    }
    return 0;
}

/*
5 6
0 4 6
1 0 9
1 2 3
2 0 2
2 3 5
3 4 1
1 2 3 4 5
*/

