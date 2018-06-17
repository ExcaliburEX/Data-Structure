#include<iostream>
#include<cmath>
#include<cstdio>
using   namespace std;
#define lambda 2.5
int JC(int n)//�׳˺���
{
    int k=1;
    for(int i=1;i<=n;i++)k*=i;
    return k;
}

double P(int n)//���ɸ��ʺ���
{
    double p = (pow(lambda, n) / JC(n)) * exp(-lambda);
    printf("P(%d):%.16lf  ", n,p);
    return p;
}

int main()
{
    double ans=0.0;

    for (int i = 0; i <= 10;i++){
        ans += P(i);
        printf("P(Sum):%.16lf\n", ans);
    }
    printf("������10���Ŷӳ��ȸ��ʣ�1-P(Sum):%.3e", 1 - ans);
    return 0;
}
