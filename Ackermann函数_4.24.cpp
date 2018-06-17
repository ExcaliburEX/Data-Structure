#include<iostream>
using namespace std;
typedef __int64 LL;


LL pow1(LL c,LL e){
   if(e==1)return c;
   else return c*pow1(c,e-1);
}

LL Ackermann(LL i,LL j){
    if((i==1)&&(j>=1))return pow1(2,j);
    else if((i>=2)&&(j==1))return Ackermann(i-1,2);
    else if((i>=2)&&(j>=2))return Ackermann(i-1,Ackermann(i,j-1));
}

int main(){
    LL n=Ackermann(3,3);
    cout<<n;
    return 0;
}
