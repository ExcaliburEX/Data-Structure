/*
ʵ��1.1 ������к����⣨20 �֣�
����K��������ɵ�����{ N
?1
?? , N
?2
?? , ..., N
?K
??  }�����������С�������Ϊ{ N
?i
?? , N
?i+1
?? , ..., N
?j
??  }������ 1��i��j��K����������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ������������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20����Ҫ�����д���򣬼�������������е�������к͡�

����ּ�ڲ��Ը��ֲ�ͬ���㷨�ڸ�����������µı��֡�������������ص����£�

����1���������ȼۣ����Ի�����ȷ�ԣ�
����2��102�����������
����3��103�����������
����4��104�����������
����5��105�����������
�����ʽ:

�����1�и���������K (��100000)����2�и���K������������Կո�ָ���

�����ʽ:

��һ�������������к͡��������������������Ϊ�����������0��

��������:

6
-2 11 -4 13 -5 -2
�������:

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
{ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int num[], int left, int right )
{ /* ���η���num[left]��num[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( num[left] > 0 )  return num[left];
        else return 0;
    }

    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( num, left, center );
    MaxRightSum = DivideAndConquer( num, center+1, right );

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += num[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += num[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */

    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int num[], int N )
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
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

