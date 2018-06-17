#include<stdio.h>
#include<iostream>
/*
#ifndef _OJ_
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
#endif
*/
using namespace std;

__int64 fib(int n){
	__int64 f,g;
	f=1,g=0;
	while(0<n--){
		g=g+f;
		f=g-f;
	}
	return g;
}


int main(){
	int n;
    cin>>n;
	cout<<fib(n);
	return 0;
}
