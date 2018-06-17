#include<iostream>
#include<stack>

using namespace std;
stack<int>s;


int main(){
    int n;

    while(cin>>n){
        int a,n0=n;
        while(s.size())s.pop();
        while(n){
            a=n%2;

            s.push(a);
            n/=2;
        }
        cout<<n0<<"的二进制为：";
        while(!s.empty()){

            cout<<s.top();
            s.pop();

        }

        cout<<endl;
    }
    return 0;
}
