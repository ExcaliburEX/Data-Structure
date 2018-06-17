#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 105
int a1[MAXN],a2[MAXN],b[MAXN],TmpA[MAXN];
int N;
int IsSort(int *a,int *b,int N)
{
    int i;
    for (i=0;i<N;i++)
    {
        if (a[i]!=b[i])return 0;
    }
    return 1;
}

void InsertionSort(int A[],int P)
{
    int i,tmp;
    tmp=A[P];
    for(i=P;i>0&&A[i-1]>tmp;i--)
        A[i]=A[i-1];
    A[i]=tmp;
}

void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
{
    int LeftEnd,NumElements,Tmp,i;
    LeftEnd=R-1;
    NumElements=RightEnd-L+1;
    Tmp=L;
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(A[L]<=A[R])TmpA[Tmp++]=A[L++];
        else TmpA[Tmp++]=A[R++];
    }
    while(L<=LeftEnd)TmpA[Tmp++]=A[L++];
    while(R<=RightEnd)TmpA[Tmp++]=A[R++];
    for(i=0;i<NumElements;i++,RightEnd--)
        A[RightEnd]=TmpA[RightEnd];

}

void  MSort(int A[],int TmpA[],int length,int N)
{
    int i,j;
    for(i=0;i<=N-2*length;i+=2*length)
        Merge(A,TmpA,i,i+length,i+2*length-1);
    if(i+length<N)Merge(A,TmpA,i,i+length,N-1);
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

    int length=1;
    while(length<N)
    {
        MSort(a2,TmpA,length,N);
        length*=2;
        if(IsSort(a2,b,N))
        {
            cout<<"Merge Sort"<<endl;
            MSort(a2,TmpA,length,N);
            Print(a2);
            return 0;
        }
    }
}
