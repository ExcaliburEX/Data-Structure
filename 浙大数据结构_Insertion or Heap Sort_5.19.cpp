#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 105
using namespace std;
int N;
int a1[MAXN],a2[MAXN],b[MAXN];
int IsSort(int *a,int *b,int N)
{
    for(int i=0;i<N;i++)
    {
        if(a[i]!=b[i])return 0;
    }
    return 1;
}

void InsertionSort(int A[],int P)
{
    int Tmp=A[P],i;
    for(i=P;i>0&&A[i-1]>Tmp;i--)
        A[i]=A[i-1];
    A[i]=Tmp;
}

void PercDown(int A[],int p,int N)
{
    int child,parent;
    int x=A[p];
    for(parent=p;(parent*2+1)<N;parent=child)
    {
        child=parent*2+1;
        if((child!=N-1)&&(A[child]<A[child+1]))child++;
        if(x>=A[child])break;
        else A[parent]=A[child];
    }
    A[parent]=x;
}

void Print(int *a)
{
    for(int i=0;i<N-1;i++)
        cout<<a[i]<<" ";
    cout<<a[N-1];
}

int main()
{
    int i,v;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>v;
        a1[i]=a2[i]=v;
    }
    for(i=0;i<N;i++)
        cin>>b[i];
    for(i=1;i<N;i++)
    {
        InsertionSort(a1,i);
        if(IsSort(a1,b,N))
        {
            cout<<"Insertion Sort"<<endl;
            InsertionSort(a1,i+1);
            Print(a1);
            return 0;
        }
    }
    for(i=N/2-1;i>=0;i--)
        PercDown(a2,i,N);
    for(i=N-1;i>0;i--)
    {
        swap(a2[0],a2[i]);
        PercDown(a2,0,i);
        if(IsSort(a2,b,N))
        {
            cout<<"Heap Sort"<<endl;
            swap(a2[0],a2[--i]);
            PercDown(a2,0,i);
            Print(a2);
            return 0;
        }
    }
}
