#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main(){
    int M,N,K;
    cin>>M>>N>>K;
    for(int i=0;i<K;i++){
        stack<int> s;
        bool flag=true;
        int t=1;
        for(int j=0;j<N;j++){
            int num;
            cin>>num;
            if(flag){
            while(s.empty()||s.top()!=num){
                s.push(t);
                if(s.size()>M){
                    flag=false;
                    break;
                }
                t++;
            }
            if(flag&&s.size()>=1&&s.top()==num)
                s.pop();
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
