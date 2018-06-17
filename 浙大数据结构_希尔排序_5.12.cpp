#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef int ElementType;
int IncrementSequence_Sedgewick[30];
void IncrementSequenceBuild_Sedgewick()
{
    IncrementSequence_Sedgewick[0]=0;
    IncrementSequence_Sedgewick[1]=1;
    for(int i=1,j=2;i<=13||j<=15;)
        if(i<=13&&9*(1<<i*2)-9*(1<<i)+1<(1<<j*2)-3*(1<<j)+1)
            IncrementSequence_Sedgewick[i+j-1]=9*(1<<i*2)-9*(1<<i)+1,i++;
        else
            IncrementSequence_Sedgewick[i+j-1]=(1<<j*2)-3*(1<<j)+1,j++;
}
void ShellSort(ElementType A[], int N)
{ /* 希尔排序 - 用Sedgewick增量序列 */
    int Si, D, P, i;
    ElementType Tmp;
    /* 这里只列出一小部分增量 */

    int Sedgewick[] = {1073643521,603906049,268386305,150958081,67084289,37730305,16764929,
    9427969,4188161,2354689,1045505,587521,260609,146305,64769,36289,16001,
    8929,3905,2161,929,505,209,109,41,19,5,1,0};

    for (Si = 0; Sedgewick[Si] >= N; Si++)
        ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

    for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
        for (P = D; P < N; P++)
        { /* 插入排序*/
            Tmp = A[P];
            for (i = P; i >= D && A[i - D] > Tmp; i -= D)
                A[i] = A[i - D];
            A[i] = Tmp;
        }
}

int main()
{
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N;i++)
        cin >> a[i];
    ShellSort(a, N);
    for (int i = 0; i < N-1; i++)
        cout<<a[i]<<" ";
    cout << a[N - 1];
    return 0;

}
