/* 快速排序 */
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
typedef int ElementType;


int Random(int start, int end){
    int dis = end - start;
    return rand() % dis + start;
}
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a=*b;
    *b = tmp;
}

void InsertionSort(int A[],int N)
{
    int i,P,tmp;
    for (P = 1; P < N;P++)
    {
        tmp = A[P];
        for (i = P ; i > 0 && A[i - 1] > tmp;i--)
                    A[i] = A[i - 1];
        A[i] = tmp;
    }
}

//
//ElementType Median3(ElementType A[], int Left, int Right)
//{
//    int Center = (Left + Right) / 2;
//    if (A[Left] > A[Center])
//        Swap(&A[Left], &A[Center]);
//    if (A[Left] > A[Right])
//        Swap(&A[Left], &A[Right]);
//    if (A[Center] > A[Right])
//        Swap(&A[Center], &A[Right]);
//    /* 此时A[Left] <= A[Center] <= A[Right] */
//    Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
//    /* 只需要考虑A[Left+1] … A[Right-2] */
//    return A[Right - 1]; /* 返回基准Pivot */
//}
//
//int RandomPivot(int A[],int Left,int Right)
//{
//    int s=A[Random(Left,Right)];
//    Swap(&s,&A[Right]);
//    return s;
//}
//
//void Qsort(ElementType A[], int Left, int Right)
//{ /* 核心递归函数 */
//    int Pivot, Cutoff, Low, High;
//    Cutoff=50;
//    if (Cutoff <= Right - Left)
//    {                                    /* 如果序列元素充分多，进入快排 */
//        Pivot = Median3(A,Left,Right); /* 选基准 */
//        Low = Left;
//        High = Right - 1;
//        while (1)
//        { /*将序列中比基准小的移到基准左边，大的移到右边*/
//            while (A[++Low] < Pivot)
//                ;
//            while (A[--High] > Pivot)
//                ;
//            if (Low < High)
//                Swap(&A[Low], &A[High]);
//            else
//                break;
//        }
//        Swap(&A[Low], &A[Right-1]); /* 将基准换到正确的位置 */
//        Qsort(A, Left, Low - 1);      /* 递归解决左边 */
//        Qsort(A, Low + 1, Right);     /* 递归解决右边 */
//    }
//    else
//        InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
//}
int Median3(int A[],int Left,int Right)
{
    int center=(Left+Right)/2;
    if(A[Left]>A[center])swap(A[Left],A[center]);
    if(A[Left]>A[Right])swap(A[Left],A[Right]);
    if(A[center]>A[Right])swap(A[center],A[Right]);
    swap(A[center],A[Right-1]);
    return A[Right-1];
}

void Qsort(int A[],int Left,int Right)
{
    int Pivot,cutoff,low,high;
    cutoff=50;
    if(cutoff<=Right-Left)
    {
        low=Left;
        high=Right-1;
        Pivot=Median3(A,Left,Right);
        while(1)
        {
            while(A[++low]<Pivot);
            while(A[--high]>Pivot);
            if(low<high)
                swap(A[low],A[high]);
            else
                break;
        }
        swap(A[low],A[Right-1]);
        Qsort(A,Left,low-1);
        Qsort(A,low+1,Right);
    }
    else
    {
        InsertionSort(A+Left,Right-Left+1);
    }
}
void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
    Qsort(A, 0, N - 1);
}

int main()
{
    srand((unsigned)time(NULL));
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    QuickSort(A, N);
    for (int i = 0; i < N - 1; i++)
        cout << A[i] << " ";
    cout << A[N - 1];
    return 0;
}
