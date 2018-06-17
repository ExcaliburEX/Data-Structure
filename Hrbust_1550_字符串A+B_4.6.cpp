#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using  namespace std;
char a[100],b[100];
int c[100];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        cin>>a>>b;
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=0;i<len1||i<len2;i++){
            if(i<len1)c[i]+=a[len1-i-1]-'0';
            if(i<len2)c[i]+=b[len2-i-1]-'0';
            if(c[i]>=10){
                c[i+1]=c[i]/10;
                c[i]%=10;
            }
        }
        len1=max(len1,len2);
        if(c[len1]>0)cout<<c[len1];
        for(int i=len1-1;i>=0;i--){
            cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
