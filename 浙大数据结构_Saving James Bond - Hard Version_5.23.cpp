#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAXN 300
#define MINLEN 42.5
struct Node
{
    double x,y;
}P[MAXN];
int n,m;
bool visited[MAXN]={false};
int path[MAXN]={-1};
bool isSafe(int n)
{
    if(abs(P[n].x)+m>=50||abs(P[n].y)+m>=50)
        return true;
     return false;
}

bool jump(int a,int b)
{
    double p1=pow(P[a].x-P[b].x,2);
    double p2=pow(P[a].y-P[b].y,2);
    double r=m*m;
    if(p1+p2<=r)
        return true;
    return false;
}

double firstjump(int n)
{
    double p1=pow(P[n].x,2);
    double p2=pow(P[n].y,2);
    double r=(m+7.5)*(m+7.5);
    if(p1+p2<=r)
        return p1+p2;
    return 0;
}

bool cmp(int a,int b)
{
    return firstjump(a)<firstjump(b);
}

void BFS()
{
    int b[MAXN];
    queue<int> Q;
    for(int i=0;i<n;i++)
        b[i]=i;
    sort(b,b+n,cmp);
    int last;
    for(int i=0;i<n;i++)
    {
        if(firstjump(b[i]))
        {
            Q.push(b[i]);
            visited[b[i]]=true;
            last=b[i];
        }
    }
    int step=2;
    int tail;
    while(!Q.empty())
    {
        int q=Q.front();
        Q.pop();
        if(isSafe(q))
        {
            int k=1;
            stack<int> S;
            cout<<step<<endl;
            while(k<step)
            {
                S.push(q);
                q=path[q];
                k++;
            }
            while(!S.empty())
            {
                q=S.top();
                S.pop();
                cout<<P[q].x<<" "<<P[q].y<<endl;
            }
            return;
        }


        for(int i=0;i<n;i++)
        {
            if(!visited[i]&&jump(q,i))
            {
                Q.push(i);
                path[i]=q;
                visited[i]=true;
                tail=i;
            }
        }
        if(q==last)
        {
            step++;
            last=tail;
        }
    }
    if(Q.empty())
    {
        cout<<"0"<<endl;
    }
}

int main()
{
    freopen("5.23.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>P[i].x>>P[i].y;
    if(m>=MINLEN)
    {
        cout<<"1"<<endl;
        return 0;
    }
    BFS();
    return 0;
}


