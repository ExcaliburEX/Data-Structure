#include<iostream>
#include<cstdio>
#include<cstdlib>
#define Size 100
using namespace std;
typedef struct node *pnode;
typedef struct node{
    int ver;
    pnode next;
}adjlist[Size];

typedef struct Gnode *G;
struct Gnode{
    int nv;
    int ne;
    adjlist g;
};

int main()
{
    G G1=(G)malloc(sizeof(struct Gnode));
    for(int i=0;i<Size;i++)
    {
        G1->g[i].next=NULL;
    }
    cin>>G1->nv>>G1->ne;
    for(int i=0;i<G1->ne;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        pnode New;
        New=(pnode)malloc(sizeof(struct node));
        New->ver=v2;
        New->next=G1->g[v1].next;
        G1->g[v1].next=New;
    }
    for(int i=0;i<G1->nv;i++)
    {
        for(pnode q=G1->g[i].next;q;q=q->next)
        {
            cout<<q->ver<<" ";
        }
        cout<<endl;
    }
    return 0;
}
