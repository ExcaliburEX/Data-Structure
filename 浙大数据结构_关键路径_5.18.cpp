#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;//声明名称空间为std
#define MAXN 105
#define INFINITY 65535
int N,M;
int G[MAXN][MAXN];
int Earliest[MAXN],Latest[MAXN];
int D[MAXN][MAXN];
int idx,ETC;
int getmax(int *arr)
{
    int max=0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            idx=i;
        }
    }
    return max;
}

int Top_Earliest()
{
    int v,cnt=0,Indegree[MAXN]={0};
    queue<int> Q;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(G[i][j]!=INFINITY)
                Indegree[j]++;
    for(int i=0;i<N;i++)
        if(Indegree[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        cnt++;
        for(int j=0;j<N;j++)
            if(G[v][j]<INFINITY)
            {
                if(G[v][j]+Earliest[v]>Earliest[j])
                    Earliest[j]=G[v][j]+Earliest[v];
                if(--Indegree[j]==0)
                    Q.push(j);
            }
    }
    ETC=getmax(Earliest);
    if(cnt!=N)return 0;
    else return 1;
}

void Top_Latest()
{
    int v,OutDegree[MAXN]={0};
    queue<int> Q;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(G[i][j]!=INFINITY)
                OutDegree[i]++;
    for(int i=0;i<N;i++)
        if(OutDegree[i]==0)
            Q.push(i);
    for(int i=0;i<N;i++)
        Latest[i]=INFINITY;
    Latest[idx]=ETC;
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        for(int j=0;j<N;j++)
            if(G[j][v]<INFINITY)
            {
                if(Latest[v]-G[j][v]<=Latest[j])
                {
                    Latest[j]=Latest[v]-G[j][v];
                    D[j][v]=Latest[v]-Earliest[j]-G[j][v];
                }
               if(--OutDegree[j]==0)
                    Q.push(j);
            }
    }
}

void PrintKeyRoute()
{
    for(int i=0;i<N;i++)
        for(int j=N-1;j>=0;j--)
            if(D[i][j]==0)
                cout<<i+1<<"->"<<j+1<<endl;
}

int main()
{
    int u,v,w;
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            D[i][j]=G[i][j]=INFINITY;
    for(int i=0;i<M;i++)
    {
        cin>>u>>v>>w;
        u--,v--;
        G[u][v]=w;
    }
    if(!Top_Earliest())
        cout<<"0\n";
    else
    {
        cout<<ETC<<endl;
        Top_Latest();
        PrintKeyRoute();
    }
    return 0;
}
