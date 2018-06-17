//#include<iostream>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#define MAXN 100  //������������ֵ
//#define MAXM 100  //�ߵĸ��������ֵ
//using namespace std;
//
//struct edge  //��
//{
//    int u, v, w; //�ߵĶ��㡢Ȩֵ
//}edges[MAXM]; //�ߵ�����
//
//int parent[MAXN];  //parent[i]Ϊ���� i ���ڼ��϶�Ӧ�����еĸ����
//int n, m;  //����������ߵĸ���
//int i, j;  //ѭ������
//void UFset( )  //��ʼ��
//{
//    for( i=0; i<=n; i++ )
//        parent[i] = -1;
//}
//int Find( int x ) //���Ҳ����ؽڵ� x �������ϵĸ����
//{
//    int s; //����λ��
//    for( s=x; parent[s]>=0; s=parent[s] );
//    while( s!=x ) //�Ż������Dѹ��·����ʹ�����Ĳ��Ҳ������١�
//    {
//        int tmp = parent[x];
//        parent[x] = s;
//        x = tmp;
//    }
//    return s;
//}
//
////��������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ����������������Ԫ�ض���ͨ
//void Union( int R1, int R2 )
//{
//    int r1 = Find(R1), r2 = Find(R2); //r1 Ϊ R1 �ĸ���㣬r2 Ϊ R2 �ĸ����
//    int tmp = parent[r1] + parent[r2]; //�������Ͻ�����֮��(����)
//    //��� R2 ������������ > R1 ������������(ע�� parent[r1]�Ǹ���)
//    if( parent[r1] > parent[r2] ) //�Ż������D�D��Ȩ����
//    {
//        parent[r1] = r2;
//        parent[r2] = tmp;
//    }
//    else
//    {
//        parent[r2] = r1;
//        parent[r1] = tmp;
//    }
//}
//bool cmp( edge a, edge b ) //ʵ�ִ�С��������ıȽϺ���
//{
//    return a.w <= b.w;
//}
//void Kruskal( )
//{
//    int sumweight = 0;  //��������Ȩֵ
//    int num = 0;  //��ѡ�õıߵ���Ŀ
//    int u, v;  //ѡ�ñߵ���������
//    UFset(); //��ʼ�� parent[]����
//    for( i=0; i<m; i++ )
//    {
//        u = edges[i].u; v = edges[i].v;
//        if( Find(u) != Find(v) )
//        {
//            printf( "%d %d %d\n", u, v, edges[i].w );
//            sumweight += edges[i].w; num++;
//            Union( u, v );
//        }
//        if( num>=n-1 ) break;
//    }
//    printf( "weight of MST is %d\n", sumweight );
//}
//int main( )
//{
//    int u, v, w; //�ߵ������յ㼰Ȩֵ
//    //scanf( "%d%d", &n, &m ); //���붥����� n
//    cin>>n>>m;
//    for( int i=0; i<m; i++ )
//    {
//    //scanf( "%d%d%d", &u, &v, &w ); //����ߵ������յ�
//    cin>>u>>v>>w;
//    edges[i].u = u; edges[i].v = v; edges[i].w = w;
//    }
//    sort(edges,edges+m,cmp);
//    Kruskal();
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//#define MaxVertexNum 3005
//typedef long long ll;
//struct ENode{
//    int u,v;
//    ll w;
//}edge[MaxVertexNum];
//ll S[MaxVertexNum];
//ll n,m;
//int u,v;
//ll w;
//void InitializeSet()
//{
//    for(int i=0;i<=m;i++)
//        S[i]=-1;
//}
//
//ll Find(ll X)
//{
//    if(S[X]<0)
//        return X;
//    else
//        return S[X] = Find(S[X]);
//}
//
//void Union(ll Root1,ll Root2)
//{
//    ll R1=Find(Root1);
//    ll R2=Find(Root2);
//    if(S[R1]<S[R2])
//    {
//        S[R1]+=S[R2];
//        S[R2]=R1;
//    }
//    else
//    {
//        S[R2]+=S[R1];
//        S[R1]=R2;
//    }
//}
//
//bool cmp(ENode a,ENode b)
//{
//    return a.w<=b.w;
//}
//
//
//void Kruskal()
//{
//    ll SumWeight=0;
//    ll num=0;
//    InitializeSet();
//    for(int i=0;i<m;i++)
//    {
//        u=edge[i].u;
//        v=edge[i].v;
//        if(Find(u)!=Find(v))
//        {
//        //printf("%d %d %d\n",u,v,edge[i].w);
//            Union(u,v);
//            num++;
//            SumWeight+=edge[i].w;
//        }
//        if(num>n-1)break;
//    }
//    if(num!=n-1)printf("-1");
//    else printf("%d",SumWeight);
//}
//
//
//int main()
//{
//    cin>>n>>m;
//    for(int i=0;i<m;i++)
//    {
//        cin>>u>>v>>w;
//        u--,v--;
//        edge[i].u=u;
//        edge[i].v=v;
//        edge[i].w=w;
//    }
//    sort(edge,edge+m,cmp);
//    Kruskal();
//    return 0;
//}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MaxVertexNum 100000
typedef long long ll;
struct ENode{
    ll u,v;
    ll w;
}edge[MaxVertexNum];
ll S[MaxVertexNum];
ll Find(int X)
{
    if(S[X]<0)
        return X;
    else
        return S[X] = Find(S[X]);
}

bool cmp(ENode a,ENode b)
{
    return a.w<b.w;
}


void Kruskal(ll n,ll m)
{
    sort(edge+1,edge+m+1,cmp);
    ll SumWeight=0;
    ll num=0;
    for(int i=1;i<=m;i++)
    {
        int a=Find(edge[i].u);
        int b=Find(edge[i].v);
        if(a!=b)
        {
        //printf("%d %d %d\n",u,v,edge[i].w);
            S[a]=b;
            num++;
            SumWeight+=edge[i].w;
        }
        if(num==n-1)break;
    }
    printf("%lld",SumWeight);
}
void read()
{
    ll n,m,u,v,w;
    //scanf("%lld%lld%lld",&n,&m);
    cin>>n>>m;
    memset(S,-1,sizeof(S));
    for(int i=1;i<=m;i++)
    {
       //scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
       cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    Kruskal(n,m);
}

int main()
{
read();
}




