#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[51],yearold;

    for(int i=0;i<51;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&yearold);
        ++a[yearold];
    }


    for(int i=0;i<51;i++){
        if(a[i])printf("%d:%d\n",i,a[i]);
    }
    return 0;
}
