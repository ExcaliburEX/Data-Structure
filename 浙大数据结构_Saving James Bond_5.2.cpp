#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define Max_Size 100
#define radius 15.0/2
typedef struct node{
    double x;
    double y;
}Node[Max_Size];
bool visited[Max_Size];
int N;
double D;
Node P;
int FirstJump(int v);
void Save007(Node G);
int DFS(int v);
int Jump(int v,int w);
int IsSafe(int v);
int answer=0;

int main()
{
    cin>>N>>D;
    for(int i=0;i<N;i++)
    {
        cin>>P[i].x>>P[i].y;
    }
    Save007(P);
    return 0;
}

int FirstJump(int v)
{
    return (sqrt(P[v].x*P[v].x+P[v].y*P[v].y)<=D+radius);
}

void Save007(Node G)
{
    for(int i=0;i<N;i++)
    {
        if(!visited[i]&&FirstJump(i))
        {
            answer=DFS(i);
            if(answer)break;
        }
    }
    if(answer)cout<<"Yes";
    else cout<<"No";
}

int DFS(int v)
{
    visited[v]=true;
    if(IsSafe(v))answer=1;
    else
    {
        for(int i=0;i<N;i++)
        {
            if(!visited[i]&&Jump(v,i))
            {
                answer=DFS(i);
                if(answer)break;
            }
        }
    }
    return answer;
}

int Jump(int v,int w)
{
    return (sqrt((P[v].x-P[w].x)*(P[v].x-P[w].x)+(P[v].y-P[w].y)*(P[v].y-P[w].y))<=D);
}

int IsSafe(int v)
{
    return (abs(P[v].x)>=50-D||abs(P[v].y)>=50-D);
}
