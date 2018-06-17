#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
int NextPrime ( int N ) {
    if(N==1)return 2;
    int i,p=(N%2)?N+2:N+1;
    while(1)
    {
        for(i=(int)sqrt(p);i>2;i--)
            if(p%i==0)break;
        if(i==2)break;
        else p+=2;
    }
    return p;
}
int main () {
    int M,N,tmp,pos,n,k;
    cin>>M>>N;
    int Size;
    Size=NextPrime(M);
    vector<int> v(Size);
    for(int i=0;i<Size;i++)
        v[i]=0;
    for(int i=0;i<N;i++)
    {
        cin>>n;
        pos=n%Size;
        k=0;
        tmp=pos;
        while(k<Size)//k>=Size后将进入无限循环
        {
            if(v[pos]==0)
            {
                v[pos]=n;
                cout<<pos;
                break;
            }
            else
            {
                k++;
                pos=tmp+k*k;
                pos%=Size;
            }
        }
        if(k==Size)cout<<"-";
        if(i!=N-1)cout<<" ";
    }
    return 0;
}
