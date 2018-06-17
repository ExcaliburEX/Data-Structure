#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define Maxn 101
#define INF -65535
int N,M;
int G[Maxn][Maxn];
int indegree[Maxn];
int Ear[Maxn];
int t=INF;
int main()
{
    cin>>N>>M;
    int v,u,w;
    for(int i=0;i<M;i++)
    {
        cin>>v>>u>>w;
        G[v][u]=w;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(G[j][i])indegree[i]++;
        }
    }
    queue<int> Q;
    for(int i=0;i<N;i++)
        if(!indegree[i])Q.push(i);
    int cnt=0;
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        cnt++;
        for(int j=0;j<N;j++)
        {
            if(G[v][j]!=0)
        {
            if(--indegree[j]==0)
                    Q.push(j);
               Ear[j]=max(G[v][j]+Ear[v],Ear[j]);
                //cout<<Ear[j]<<" ";
            }
        }
    }
    if(cnt!=N)
    {
        cout<<"Impossible";
    }
    else
    {
       for(int i=0;i<N;i++)
            if(t<Ear[i])t=Ear[i];
        cout<<t;
    }
    return 0;
}
