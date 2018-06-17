
#include<iostream>
#include<fstream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

int cmp1(char x){
    if(x=='['||x==']')return 1;
    if(x=='{'||x=='}')return 2;
    if(x=='('||x==')')return 3;
}

int main(){
    stack<char> match;
    char s[50];
    /*char filename[10]="1.txt";
    //freopen("1.txt","r",stdin);
    ifstream inFile;
    inFile.open(filename);*
    while(inFile>>s!=NULL){*/
    while(gets(s)!=NULL){
        int flag=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(match.empty()&&(s[i]==']'||s[i]=='}'||s[i]==')')){
                flag=1;
                break;
            }
            else if(s[i]=='{'||s[i]=='['||s[i]=='('){
                        match.push(s[i]);
                    }
            else if(s[i]=='}'||s[i]==']'||s[i]==')'){
                if(cmp1(match.top())==cmp1(s[i])){
                    match.pop();
                }else{
                flag=1;
                break;
                }
            }
        }
        if(match.empty()&&!flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        while(!match.empty())match.pop();
    }
    return 0;

}
