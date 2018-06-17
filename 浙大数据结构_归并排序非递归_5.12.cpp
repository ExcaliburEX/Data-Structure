/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */

/* length = 当前有序子列的长度*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef int ElementType;

void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
{
    int NumElements=RightEnd-L+1;
    int Tmp=L;
    int LeftEnd=R-1;
    while(L<=LeftEnd&&R<=RightEnd)
    {
        if(A[L]<A[R])
            TmpA[Tmp++]=A[L++];
        else TmpA[Tmp++]=A[R++];
    }
    while(L<=LeftEnd)
        TmpA[Tmp++]=A[L++];
    while(R<=RightEnd)
        TmpA[Tmp++]=A[R++];
}



//void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
//{ /* 两两归并相邻有序子列 */
//    int i, j;
//
//    for (i = 0; i <= N - 2 * length; i += 2 * length)
//        Merge(A, TmpA, i, i + length, i + 2 * length - 1);
//    if (i + length < N) /* 归并最后2个子列*/
//        Merge(A, TmpA, i, i + length, N - 1);
//    else /* 最后只剩1个子列*/
//        for (j = i; j < N; j++)
//            TmpA[j] = A[j];
//}
//
//void Merge_Sort(ElementType A[], int N)
//{
//    int length;
//    ElementType *TmpA;
//
//    length = 1; /* 初始化子序列长度*/
//    TmpA = (ElementType *)malloc(N * sizeof(ElementType));
//    if (TmpA != NULL)
//    {
//        while (length < N)
//        {
//            Merge_pass(A, TmpA, N, length);
//            length *= 2;
//            Merge_pass(TmpA, A, N, length);
//            length *= 2;
//        }
//        free(TmpA);
//    }
//    else
//        printf("空间不足");
//}

void Merge_pass(int A[],int TmpA[],int N,int length)
{
    int i,j;
    for(i=0;i<=N-2*length;i+=2*length)
        Merge(A,TmpA,i,i+length,i+2*length-1);
    if(i+length<N)
        Merge(A,TmpA,i,i+length,N-1);
    else
        for(j=i;j<N;j++)
            TmpA[j]=A[j];
}

void Merge_Sort(int A[],int N)
{
    int length=1;
    int * TmpA=(int *)malloc(sizeof(int)*N);
    if(TmpA!=NULL)
    {
        while(length<N)
        {
            Merge_pass(A,TmpA,N,length);
            length*=2;
            Merge_pass(TmpA,A,N,length);
            length*=2;
        }
        free(TmpA);
    }
    else
        cout<<"ERROR";
}
int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    Merge_Sort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
    return 0;

}
