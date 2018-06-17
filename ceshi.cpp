#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

using namespace std;

#define MaxVertexNum 101

int visit[1001];

int NumOfEdge;

typedef int Vertex;

typedef int WeightType;

typedef struct GNode{

    int NumOfVertex;

    int NumOfEdge;

    WeightType G[MaxVertexNum][MaxVertexNum];

}MGNode,*MGraph;

typedef struct ENode{

    Vertex V1, V2;

}MENode,*Edge;

/********************************************

插入

********************************************/

void InsertEdge(MGraph Graph,Edge E){

    Graph->G[E->V1][E->V2] = 1;

    Graph->G[E->V2][E->V1] = 1;

}

/********************************************

初始化图

********************************************/

MGraph CreatGraph(Vertex Vertex_Num){

    MGraph Graph;

    Graph = new MGNode;

    if(Graph == NULL){

        cout<<"Creat Error"<<endl;

        exit(0);

    }

    Graph->NumOfVertex = Vertex_Num;

    Graph->NumOfEdge = 0;

    memset(Graph->G,0,sizeof(GNode));

    return Graph;

}

/********************************************

创建图

********************************************/

MGraph BuildGraph(){

    MGraph Graph;

    int  NumOfVertex;

    cin>>NumOfVertex;

    /*此处可能有BUG*/



    cin>>NumOfEdge;

    Graph = CreatGraph(NumOfVertex);

    if(NumOfEdge){

        for(int i = 0;i<NumOfEdge;i++){

            Edge E;

            E = new MENode;

            cin>>E->V1>>E->V2;

            InsertEdge(Graph,E);

        }

    }

    return Graph;

}

void DFS(MGraph Graph,Vertex i){

    visit[i] = 1;

    cout<<i<<" ";

///此处判断是不是单个结点

    for(int j = 0; j<Graph->NumOfVertex; j++){

        if(Graph->G[i][j]&&!visit[j]){

            DFS(Graph,j);

        }

    }

}

void ListComponentsWithDFS(MGraph Graph)

{

    for (int i = 0; i < Graph->NumOfVertex; i++)

        if (!visit[i])

        {

            printf("{ ");

            DFS(Graph,i);

            printf("}\n");

        }

}

void BFS(MGraph Graph,Vertex i){

    int queue[1010];

    int first = -1;

    int last = -1;

    queue[++last] = i;

    visit[i] = 1;

    while(first<last){

        int j = queue[++first];

        cout<<j<<" ";

        for(int m = 0;m<Graph->NumOfVertex;m++){

            if(Graph->G[j][m]&&!visit[m]){

                queue[++last] = m;

                 visit[m] = 1;

            }

        }



    }

}

void ListComponentsWithBFS(MGraph Graph)

{

    for (int i = 0; i < Graph->NumOfVertex; i++)

        if (!visit[i])

        {

            printf("{ ");

            BFS(Graph,i);

            printf("}\n");

        }

}



int main(){

    MGraph Graph;

    Graph = BuildGraph();

    ListComponentsWithDFS(Graph);

    for(int i = 0;i<MaxVertexNum;i++){

        visit[i] = 0;

    }

    ListComponentsWithBFS(Graph);

    return 0;

}
