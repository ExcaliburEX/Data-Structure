#include<iostream>
using namespace std;
typedef int ElementType;

//void InsertionSort(ElementType A[], int N)
//{ /* 插入排序 */
//    int P, i;
//    ElementType Tmp;
//
//    for (P = 1; P < N; P++)
//    {
//        Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
//        for (i = P; i > 0 && A[i - 1] > Tmp; i--)
//            A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移*/
//        A[i] = Tmp;          /* 放进合适的位置 */
//    }
//}
void InsertionSort(int A[],int N)
{
    int tmp,P,i;
    for(P=1;P<N;P++)
    {
        tmp=A[P];
        for(i=P;i>0&&A[i-1]>tmp;i--)
            A[i]=A[i-1];
        A[i]=tmp;
    }
}
//玲珑骰子安红豆，入骨相知君知否
int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
        cin>>A[i];
    InsertionSort(A,N);
    for(int i=0;i<N-1;i++)
        cout<<A[i]<<" ";
    cout<<A[N-1];
    return 0;

}
