#include<iostream>
#include<set>
#include<string.h>
using namespace std;
int a[10000];
int main(){
    int n,tmp,k=0,i=0,cnt=0;
    set<int> s;
   while(cin>>n){
        memset(a,0,sizeof(a));
            s.clear();
            k=0;
            i=0;
            cnt=0;
    while(n--){
        cin>>tmp;
        s.insert(tmp);
        k++;
        if(s.size()==k){
            a[i++]=tmp;
            cnt++;
        }else k--;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<a[i];
        if(i!=cnt-1)cout<<" ";
    }
    cout<<endl;
   }
    return 0;
}
