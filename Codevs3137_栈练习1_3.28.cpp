#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main(){
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a;
        if(a==1){
            cin>>b;
            s.push(b);
        }
        else if(a==2)
		s.pop();
	else {
	cout<<s.top()<<endl;
	}
    }
    if(s.size())cout<<s.top();
    else cout<<"impossible!";
    return 0;
}
