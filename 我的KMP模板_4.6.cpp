#include<iostream>
#include<cstring>
using namespace std;
void getnext(char *T,int next[]){
    int j=-1,i=0;
    int lenT=strlen(T);
    next[0]=-1;
    while(i<lenT-1){
        if(j=-1||T[i]==T[j]){
            i++;j++;
            if(T[i]!=T[j])next[i]=j;
            else next[i]=next[j];
        }else j=next[j];
    }
}
int kmp(char *S,char *T){
    int i=0,j=0;
    int len1=strlen(S);
    int len2=strlen(T);
    int next[255];
    getnext(T,next);
    while(i<len1&&j<len2){
        if(j==-1||S[i]==T[j]){
            i++;j++;
        }else j=next[j];
    }
    if(j==len2)return i-j;
    else return -1;
}
int main(){
    char a[255],b[255];
    cin>>a>>b;
    int pos=kmp(a,b);
    int pos1=pos;
    int L=strlen(b);
    cout<<"The string is:";
    while(L--)cout<<a[pos++];
    cout<<endl<<"found at "<<pos1;
    return 0;
}
