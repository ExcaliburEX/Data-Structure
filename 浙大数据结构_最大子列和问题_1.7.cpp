/*
实例1.1 最大子列和问题（20 分）
给定K个整数组成的序列{ N
?1
?? , N
?2
?? , ..., N
?K
??  }，“连续子列”被定义为{ N
?i
?? , N
?i+1
?? , ..., N
?j
??  }，其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

数据1：与样例等价，测试基本正确性；
数据2：102个随机整数；
数据3：103个随机整数；
数据4：104个随机整数；
数据5：105个随机整数；
输入格式:

输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

输出格式:

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:

6
-2 11 -4 13 -5 -2
输出样例:

20
*/
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
#define random(x)(rand()%x)
#define maxn 10000000
using namespace std;
//cout.sef(ios::fixed);
//cout.precision(6);
int num[maxn];
int sum1(int num[],int n){//O(N^2)
   // int begin , end = 0;
   int maxsum=0;
    int thissum=0;
    int i,j;
    for(i=0;i<n;i++){
        thissum = 0;
        for(j=i;j<n;j++){
  //          end=j;
            thissum+=num[j];
            if(thissum > maxsum)
                maxsum=thissum;
        }
    }
    return maxsum;
}


int max(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int sum2(int num[],int n){//O(NlogN)
    static int Max=0;
    n=n/2;
    num+=n;
    if(n>1){
        Max=max(sum2(num,n),sum2(num-n,n));
        int thismax=0 ,leftmax=0,rightmax=0;
        for(int i=0;i<n;i++){
            thismax+=*(num+i);
            if(rightmax<thismax)
                rightmax=thismax;
        }
        thismax =0;
        for(int i=0;i<n;i++){
            thismax+=*(num-1-i);
            if(leftmax<thismax)
                leftmax=thismax;
        }
        return Max=max(Max,leftmax+rightmax);
    }
    else
        return max(*(num-1)+*num,(max(*(num-1),*num)));
}

int sum3(int num[],int n){//O(N)
    int thismax=0,Max=0;
    for(int i=0;i<n;i++){
        thismax+=num[i];
        if(Max<thismax) Max=thismax;
        if(thismax<0) thismax=0;
        }
        return Max;
}




int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int num[], int left, int right )
{ /* 分治法求num[left]到num[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( num[left] > 0 )  return num[left];
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( num, left, center );
    MaxRightSum = DivideAndConquer( num, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += num[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += num[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int num[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( num, 0, N-1 );
}


int main(void) {
    srand((int)time(0));

    int n=maxn;
    int cnt=10;


    cout<<"divide and conquer begin:"<<endl;
     double dur;
    clock_t start,end1;
    start = clock();
    while(cnt--){
    for(int i=0;i<maxn;i++)num[i]=random(150)-90;
    /*scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }*/
    printf("%d\n",MaxSubseqSum3(num,n));
    }
    end1 = clock();
    dur = (double)(end1 - start);
    printf("Use Time:%f\n",(dur/CLOCKS_PER_SEC));



    cout<<"zai xian yan zheng:"<<endl;
    time_t start3,stop;
    start3 = time(NULL);
    cnt=10;
    while(cnt--){
    for(int i=0;i<maxn;i++)num[i]=random(150)-90;
    printf("%d\n",sum3(num,n));
    }
     stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start3));
    return 0;
}

