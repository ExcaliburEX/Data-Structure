#include<iostream>
#include<stack>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
using namespace std;
stack<double> s;
char a[50];
int main(){
    int n;
    while(gets(a)){
        while(!s.empty()){
            s.pop();
        }
        int len=strlen(a);
        double sum=0;
        int wei=1;
        int flag=0;
        for(int i=len-1;i>=0;i--){
            if(a[i]>='0'&&a[i]<='9'){
                sum+=(a[i]-'0')*wei;
                wei*=10;
            }
            else if(a[i]=='.'){
                sum=sum/(1.0*wei);
                wei=1;
            }
            else if((a[i]=='+'||a[i]=='-')&&sum!=0){
                if(a[i]=='+'){
                    s.push(sum);
                    sum=0;
                    wei=1;
                    i--;
                    continue;
                }else {
                    sum=-sum;
                    s.push(sum);
                    sum=0;
                    wei=1;
                    i--;
                    continue;
                }
            }
            else if(a[i]==' '){
                s.push(sum);
                sum=0;
                wei=1;
                continue;
            }
            else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
                double e=s.top();
                s.pop();
                double b=s.top();
                s.pop();
                double tmp=0.0;
                if(a[i]=='+')tmp=e+b;
                else if(a[i]=='-')tmp=e-b;
                else if(a[i]=='*')tmp=e*b;
                else {
                    if(b==0){
                        flag=1;
                        break;
                    }
                    tmp=e/b;
                }
                s.push(tmp);
                i--;
            }
        }
        cout.setf(ios::fixed);
        if(flag==0)cout<<fixed<<setprecision(1)<<s.top()<<endl;
        else cout<<"ERROR"<<endl;

    }

}
