//针对邻接矩阵的Prim算法
#include <cstdio>
#include <string.h>
#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 105;
bool vis[MAXN];
int lowc[MAXN];
int adj[MAXN];
int Prim(int cost[][MAXN], int n) //点是1~n
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    memset(adj,0,sizeof adj);
    vis[0] = true;
    for (int i = 1; i <n; i++)
        lowc[i] = cost[0][i];
    for (int i = 1; i <n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 1; j <n; j++)
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (minc == INF)
            return -1; //原图不连通
        printf("%d:(%d,%d)\n",i,adj[p],p);
        ans += minc;
        vis[p] = true;
        for (int j = 1; j <n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
                adj[j]=p;
            }

    }
    return ans;
}
int main()
{
    int n, m; //n条边，m个顶点
    int maps[105][105];
    cin>>n>>m;
        memset(maps, INF, sizeof(maps));
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
           // u--,v--;
            maps[u][v] = w;
            maps[v][u] = w;
        }
        int ans = Prim(maps, n);
        printf("%d\n", ans);
}
/*
5 10
1 2 6
1 3 3
1 4 4
1 5 5
2 3 7
2 4 7
2 5 8
3 4 6
3 5 9
4 5 2
*/
