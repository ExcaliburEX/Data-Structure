#include<iostream>
#include<cstring>
using namespace std;

void getnext(char *T,int next[]){
    int j=-1,i=0;// jǰ׺,i��׺
    next[0]=-1;
    int len=strlen(T);
    while(i<len-1){
        if(j==-1||T[i]==T[j]){
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
    while(cin>>a>>b){
        int pos=kmp(a,b);
        cout<<"found at:"<<pos;
        int len3=strlen(b);
        cout<<endl<<"The string is:";
        while(len3--)cout<<a[pos++];//ģʽƥ���������㷨������������ʶ�𸱴��ظ��Ĳ��֣���������ظ����ֲ��࣬��ô��ʲô������
        cout<<endl;
    }
    return 0;
}
