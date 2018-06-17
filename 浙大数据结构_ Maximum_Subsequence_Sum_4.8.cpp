#include<iostream>
#include<cstring>
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
int a[10000];
int main(){
    int n;
    while(cin>>n){
        mem(a);
        for(int i=0;i<n;i++)cin>>a[i];
        int thissum=0,maxsum=a[0];
        int left=a[0],right=a[0];
        int tmpleft=a[0],tmpright=a[0];
        for(int i=0;i<n;i++){
            if(thissum>=0){
                thissum+=a[i];
                tmpright=a[i];
            }else{
                thissum=a[i];
                tmpleft=a[i];
                tmpright=a[i];
            }
            if(thissum>maxsum){
                maxsum=thissum;
                right=tmpright;
                left=tmpleft;
            }

        }
        if(maxsum<0){
            maxsum=0;
            left=a[0];
            right=a[n-1];
        }
        cout<<maxsum<<" "<<left<<" "<<right<<endl;
    }
    return 0;
}
