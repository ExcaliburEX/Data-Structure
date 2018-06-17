#include<iostream>
using namespace std;

struct Node{
    char str[20];
    int age;
};
int main(){
    Node a[10];
    for(int i=0;i<10;i++){
        cin>>a[i].str>>a[i].age;
    }
     for(int i=0;i<10;i++){
        cout<<a[i].str<<" "<<a[i].age<<endl;
    }
    return 0;
}
