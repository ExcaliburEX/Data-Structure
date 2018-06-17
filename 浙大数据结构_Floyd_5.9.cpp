/* 邻接矩阵存储 - 多源最短路算法 */
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef int Vertex;
typedef int WeightType;
#define INFINITY 65535
#define MaxVertexNum 100

typedef struct GNode *MGraph;
struct GNode{
    int Nv,Ne;
    int G[MaxVertexNum][MaxVertexNum];
};


MGraph BuildGraph()
{
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    int n;
    cin>>n;
    Graph->Nv=n;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++){
            if(i==j)
                Graph->G[i][j] = 0;
            else Graph->G[i][j] = INFINITY;
        }
    }

    cin >> Graph->Ne;
    for (int i = 0; i < Graph->Ne;i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Graph->G[v1][v2] = w;
       // Graph->G[v2][v1] = w;
    }
    return Graph;
}

bool Floyd(MGraph Graph,int D[][MaxVertexNum],int path[][MaxVertexNum])
{
    Vertex i,j,k;
    for (i = 0; i < Graph->Nv;i++){
        for (j = 0; j < Graph->Nv;j++){
            D[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }
    }

    for (k = 0; k < Graph->Nv;k++)
        for (i = 0; i < Graph->Nv;i++)
            for (j = 0; j < Graph->Nv;j++)
                if(D[i][k]+D[k][j]<D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    if(i==j&&D[i][j]<0)
                        return false;
                    path[i][j] = k;
                }
    return true;
}


void PrintPath(MGraph Graph,int D[][MaxVertexNum],int path[][MaxVertexNum])
{
    int k;
    for (int v = 0; v < Graph->Nv;v++)
    {
        for (int w = v + 1; w < Graph->Nv;w++)
        {
            printf("v%d-v%d weight: %d", v, w, D[v][w]);
            k = path[v][w];
            printf(" path: %d", v);
            while(k!=-1)
            {
                printf(" -> %d", k);
                k = path[k][w];
            }
            printf(" -> %d\n", w);
        }
        cout << endl;
    }
}

int main()
{
    MGraph Graph = BuildGraph();
    int D[MaxVertexNum][MaxVertexNum];
    int path[MaxVertexNum][MaxVertexNum];
    Floyd(Graph, D, path);
    PrintPath(Graph, D, path);
    return 0;
}
