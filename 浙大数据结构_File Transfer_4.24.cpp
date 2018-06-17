#include<iostream>
#include<cstdio>
#define Maxsize 10000
using namespace std;
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[Maxsize];


/*TSSN实现
SetName Find(SetType S,ElementType X){
    for(;S[X]>0;X=S[X]);
    return X;
}
void Union(SetType S,SetName Root1,SetName Root2){
    S[Root2]=Root1;
}
*/

/* 按秩归并 */
SetName Find(SetType S,ElementType X){//路径压缩
    if(S[X]<0)return X;
    else return S[X]=Find(S,S[X]);
}

void Union(SetType S,SetName Root1,SetName Root2){//按规模归并
    if(S[Root2]<S[Root1]){
        S[Root2]+=S[Root1];
        S[Root1]=Root2;
    }
    else {
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }

}
/*
void Union(SetType S,SetType Root1,SetType Root2){//按高度归并
    if(S[Root2]<S[Root1]){
        S[Root1]=Root2;
    }
    else {
        if(S[Root1]==S[Root2])Root1--;
        S[Root2]=Root1;
    }

}
*/
void Initialization(SetType S,int n){
    for(int i=0;i<n;i++)S[i]=-1;
}
void Input_connection(SetType S){
    ElementType u,v;
    SetName Root1,Root2;
    cin>>u>>v;
    Root1=Find(S,u-1);
    Root2=Find(S,v-1);
    if(Root1!=Root2)
        Union(S,Root1,Root2);
}

void Check_connection(SetType S){
    ElementType u,v;
    SetName Root1,Root2;
    cin>>u>>v;
    Root1=Find(S,u-1);
    Root2=Find(S,v-1);
    if(Root1==Root2)cout<<"yes\n";
    else cout<<"no\n";
}

void Check_network(SetType S,int n){
    int counter=0;
    for(int i=0;i<n;i++){
        if(S[i]<0)counter++;
    }
    if(counter==1)cout<<"The network is connected.\n";
    else
        cout<<"There are "<<counter<<" components.\n";
}

int main(){
    SetType S;
    int n;
    char in;
    cin>>n;
    Initialization(S,n);
    do{
        cin>>in;
        switch(in){
        case 'I':Input_connection(S);break;
        case 'C':Check_connection(S);break;
        case 'S':Check_network(S,n);break;
        }
    }while(in!='S');
    return 0;

}
