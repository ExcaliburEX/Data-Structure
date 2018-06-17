#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define INFINITY 65535
typedef struct ENode *Edge;
struct ENode{
    int v1;
    int v2;
    int weight;
};

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    int adj;
    int weight;
    PtrToAdjVNode next;
};

typedef struct VNode{
    PtrToAdjVNode firstedge;
}adjlist[1000];


typedef struct LNode *LGraph;
struct LNode{
    int Nv;
    int Ne;
    adjlist A;
};
int G[1000][1000];
int N,M;
int TotalWeight;

LGraph CreateGraph(int v)
{
    LGraph LG=(LGraph)malloc(sizeof(struct LNode));
    LG->Nv=v;
    LG->Ne=0;
    for(int i=0;i<v;i++)
        LG->A[i].firstedge=NULL;
    return LG;
}

void InsertEdge(LGraph LG,Edge E)
{
    PtrToAdjVNode node;
    node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->weight = E->weight;
    node->adj = E->v1;
    node->next = LG->A[E->v2].firstedge;
    LG->A[E->v2].firstedge = node;

    node = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    node->weight = E->weight;
    node->adj = E->v2;
    node->next = LG->A[E->v1].firstedge;
    LG->A[E->v1].firstedge = node;
}

int FindMinDist(int dist[])
{
    int MinV,MinDist;
    MinDist=INFINITY;
    for(int i=0;i<N;i++)
    {
        if((dist[i]!=0)&&(dist[i]<MinDist))
        {
            MinDist=dist[i];
            MinV=i;
        }
    }
    if(MinDist<INFINITY)return MinV;
    else return -1;
}


LGraph Prim()
{
    int dist[1000];
    memset(dist,0,sizeof(dist));
    int parent[1000];
    memset(parent,0,sizeof(parent));
    LGraph MST;
    int VCount=0;
    Edge E;
    E=(Edge)malloc(sizeof(struct ENode));
    for(int i=0;i<N;i++)
    {
        dist[i]=G[0][i];
        parent[i]=0;
    }
    TotalWeight=0;
    MST=CreateGraph(N);
    dist[0]=0;
    parent[0]=-1;
    VCount++;
    int V,W;
    while(1)
    {
        V=FindMinDist(dist);
        if(V==-1)
            break;
        E->v1=parent[V];
        E->v2=V;
        E->weight=dist[V];
       // printf("%d %d\n",parent[V],V);
        InsertEdge(MST,E);
        TotalWeight+=dist[V];
        VCount++;
        dist[V]=0;
        for(W=0;W<N;W++)
        {
            if(dist[W]!=0&&G[V][W]<INFINITY)
            {
                  if(G[V][W]<dist[W])
                  {
                      dist[W]=G[V][W];
                      parent[W]=V;
                  }

            }

        }

    }
    return MST;
}


int main()
{
    int u,v,w;
    double sigma;
    double sum;
    double average;
    int cnt=1;
    while(cin>>N)
    {
        if(N==0)break;
        cin>>M;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                G[i][j]=INFINITY;
            }
        }
        for(int i=0;i<M;i++){
            cin>>u>>v>>w;
            u--,v--;
            G[u][v]=w;
            G[v][u]=w;
        }
       /* for(int i=0;i<N;i++)
        {
             for(int j=0;j<N;j++)
             {
                 cout<<G[i][j]<<" ";
             }
            cout<<endl;
        }*/


        LGraph MST=Prim();
        PtrToAdjVNode P;
        sum=0;
        average=(TotalWeight*1.0)/(N-1);
        for(int i=0;i<N;i++){
            for(P=MST->A[i].firstedge;P;P=P->next)
            {
                printf("(%d,%d) ",i,P->adj);
                sum+=pow((P->weight-average),2);
            }
            printf("\n");
        }
        printf("Totalweight:%d\n",TotalWeight);
        sigma=sum/(1.0*(N-1));
        printf("Case %d: %.2f\n",cnt,sigma);
        cnt++;
        free(MST);
    }
    return 0;
}

