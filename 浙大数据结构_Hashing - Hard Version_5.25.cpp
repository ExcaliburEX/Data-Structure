#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 10005
#define MINDATA -999999999
using namespace std;
typedef long long LL;
LL heap[MAXN];
int G[MAXN][MAXN];
int size=0;
LL hash1[MAXN];
int in[MAXN];
int N;

void Insert(LL m)
{
    int i;
    i=++size;
    for(;heap[i/2]>m;i/=2)
        heap[i]=heap[i/2];
    heap[i]=m;
}

LL Delete()
{
    int parent,child;
    LL item,tmp;
    item=heap[1];
    tmp=heap[size--];
    for(parent=1;parent*2<=size;parent=child)
    {
        child=parent*2;
        if((child!=size)&&(heap[child]>heap[child+1]))
            child++;
        if(tmp<=heap[child])break;
        heap[parent]=heap[child];
    }
    heap[parent]=tmp;
    return item;
}
void TopSort(int ans[])
{
    for(int i=0;i<N;i++)
    {
        if(in[i]==0)
            Insert(hash1[i]);
    }
    int count=0;
    while(size)
    {
        LL v=Delete();
        ans[count++]=v;
        v=v%N;
        for(int i=0;i<N;i++)
            if(G[v][i])
                if(--in[i]==0)
                    Insert(hash1[i]);
    }
}

int main()
{
    heap[0]=MINDATA;
    int cnt=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>hash1[i];
        if(hash1[i]>=0)
        {
            in[i]=(i-hash1[i]%N+N)%N;
            cnt++;
        }
        else in[i]=-1;
        for(int j=0;j<N;j++)
            G[i][j]=0;
    }
    for(int i=0;i<N;i++)
    {
        if(hash1[i]<0)
            continue;
        int k=hash1[i]%N;
        for(int t=0;t<in[i];t++)
        {
            G[k][i]=1;
            k=(k+1)%N;
        }
    }
    int ans[N];
    TopSort(ans);
    for(int i=0;i<cnt;i++)
    {
        if(i!=0)
            cout<<" ";
        cout<<ans[i];
    }
    return 0;
}

