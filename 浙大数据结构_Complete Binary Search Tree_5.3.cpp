/*#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
void solve(int ALeft,int ARight,int TRoot,int A[],int T[]);
int GetLeftLength(int n);
int power(int x,int y);
int main()
{
    int N;
    cin>>N;
    int A[N];
    int T[N];
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    sort(A,A+N);
    solve(0,N-1,0,A,T);
    for(int i=0;i<N-1;i++)cout<<T[i]<<" ";
    cout<<T[N-1];
    return 0;
}

void solve(int ALeft,int ARight,int TRoot,int A[],int T[])
{
    int n;
    n=ARight-ALeft+1;
    if(n==0)return ;
    int L,LeftRoot,RightRoot;
    L=GetLeftLength(n);
    T[TRoot]=A[ALeft+L];
    LeftRoot=TRoot*2+1;//下标从0开始
    RightRoot=LeftRoot+1;
    solve(ALeft,ALeft+L-1,LeftRoot,A,T);
    solve(ALeft+L+1,ARight,RightRoot,A,T);
}

int GetLeftLength(int n)
{
    int H,x,L1;
    H=floor(log(n+1)/log(2));
    x=n+1-power(2,H);
    x=min(x,power(2,H-1));
    L1=power(2,H-1)-1+x;
    return L1;

}
int power(int x,int y)
{
    int c=1;
    while(y--)
        c*=x;
    return c;
}*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int index = 1;
void solve(int t);
vector<int> v;
vector<int> T;
int N;
int main()
{
    cin>>N;
    v.resize(N+1);
    T.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    solve(1);
   // vector<int>::iterator it;
   // for(it=v.begin();it!=v.end();it++)cout<<*it<<" ";
    for(int i=1;i<=N-1;i++)cout<<T[i]<<" ";
   cout<<T[N];
    return 0;
}

void solve(int t)
{
    if(t>N)return;
    solve(t*2);
    T[t]=v[index++];
    cout<<"T["<<t<<"]="<<T[t]<<endl;
    solve(t*2+1);
}



