#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_SIZE int(33*1e4)


int N;
int count;
int level;
int last;
int tail;
bool visited[MAX_SIZE];
typedef struct ENode *Edge;
struct ENode{
    int v1,v2;
};
typedef struct AdjVNode *PAdjVNode;
struct AdjVNode{
    int adj;
    PAdjVNode next;
};

typedef struct VNode{
    PAdjVNode firstedge;
}Adjlist[MAX_SIZE];


typedef struct GNode *LGraph;
struct GNode{
    Adjlist adjlist;
    int nv;
    int ne;
};
int BFS(LGraph G,int v);
void InitVisited();

LGraph CreateGraph(int vt)
{
    LGraph G=(LGraph)malloc(sizeof(struct GNode));
    G->nv=vt;
    G->ne=0;
    for(int i=1;i<=G->nv;i++)
        G->adjlist[i].firstedge=NULL;
    return G;
}

LGraph InsertEdge(LGraph G,Edge E)
{
    PAdjVNode New;
    New=(PAdjVNode)malloc(sizeof(struct AdjVNode));
    New->adj=E->v2;
    New->next=G->adjlist[E->v1].firstedge;
    G->adjlist[E->v1].firstedge=New;

    New=(PAdjVNode)malloc(sizeof(struct AdjVNode));
    New->adj=E->v1;
    New->next=G->adjlist[E->v2].firstedge;
    G->adjlist[E->v2].firstedge=New;
}

LGraph BuildGraph()
{
    LGraph G;
    Edge E;
    cin>>N;
    G=CreateGraph(N);
    cin>>G->ne;
    E=(Edge)malloc(sizeof(struct ENode));
    for(int i=1;i<=G->ne;i++)
    {
        cin>>E->v1>>E->v2;
        InsertEdge(G,E);
    }
    return G;
}



void SDS(LGraph G)
{
   for(int i=1;i<=G->nv;i++)
    {
        count=BFS(G,i);
        InitVisited();
        //cout<<"\n";
        printf("%d: %4.2f%%\n",i,((1.0*count)/N)*100);
    }
}

void InitVisited()
{
    for(int i=1;i<=N;i++)
        visited[i]=false;
}

int BFS(LGraph G,int v)
{
    visited[v]=true;
    count=1;
    level=0;//难点在于记录层数
    last=v;
    queue<int> Q;
    Q.push(v);
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        PAdjVNode q;
       // cout<<v<<" ";
        for(q=G->adjlist[v].firstedge;q;q=q->next)
        {
            if(!visited[q->adj])
            {
                visited[q->adj]=true;
                count++;
                Q.push(q->adj);
                tail=q->adj;
            }
        }

        if(v==last)
        {
            level++;
            last=tail;
        }
        if(level==6)break;
    }
    return count;
}

int main()
{
    LGraph G;
    G=BuildGraph();
    /*
    for(int i=1;i<=G->nv;i++)
    {
        for(PAdjVNode q=G->adjlist[i].firstedge;q;q=q->next)
        {
            cout<<q->adj<<" ";
        }
        cout<<endl;
    }
    */
    SDS(G);
    return 0;
}
