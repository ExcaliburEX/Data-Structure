/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1,Tree R2);

int main(){
    Tree R1,R2;
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(Isomorphic(R1,R2))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

Tree BuildTree(struct TreeNode T[]){
    ElementType cl,cr;
    int check[100];
    int Root=Null;
    int N;
    cin>>N;
    if(N){
        memset(check,0,sizeof(check));
        for(int i=0;i<N;i++){
            cin>>T[i].Element>>cl>>cr;
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else T[i].Left=Null;
            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else T[i].Right=Null;
        }
        int i;
        for(i=0;i<N;i++)
            if(!check[i])break;
            Root=i;
    }
    return Root;
}

int Isomorphic(Tree R1,Tree R2){
    if((R1==Null)&&(R2==Null))return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))return 0;
    if(T1[R1].Element!=T2[R2].Element)return 0;

    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);

    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}*/







#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define Tree int
#define Null -1
#define Maxn 10
#define mem(a) memset(a,0,sizeof(a))
struct TreeNode{
    char data;
    Tree left;
    Tree right;
}T1[Maxn],T2[Maxn];

Tree BuildTree(struct TreeNode T[]);
int isomorphic(Tree R1,Tree R2);

int main(){
    Tree R1,R2;
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(isomorphic(R1,R2))cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}

Tree BuildTree(struct TreeNode T[]){
    char l,r;
    int N;
    int check[Maxn];
    int Root=Null;
    cin>>N;
    if(N){
        mem(check);
        for(int i=0;i<N;i++){
            cin>>T[i].data>>l>>r;
            if(l!='-'){
                T[i].left=l-'0';
                check[T[i].left]=1;
            }else T[i].left=Null;
            if(r!='-'){
                T[i].right=r-'0';
                check[T[i].right]=1;
            }else T[i].right=Null;
        }
        int i;
        for(i=0;i<N;i++)
            if(!check[i])break;
        Root=i;
    }
    return Root;
}

int isomorphic(Tree R1,Tree R2){
    if(R1==Null&&R2==Null)return 1;
    if((R1!=Null&&R2==Null)||(R1==Null&&R2!=Null))return 0;
    if(T1[R1].data!=T2[R2].data)return 0;
    if(T1[R1].left==Null&&T2[R2].left==Null)
        return isomorphic(T1[R1].right,T2[R2].right);
    if((T1[R1].left!=Null)&&(T2[R2].left!=Null)&&(T1[T1[R1].left].data==T2[T2[R2].left].data))
        return isomorphic(T1[R1].left,T2[R2].left)&&isomorphic(T1[R1].right,T2[R2].right);
    else return isomorphic(T1[R1].right,T2[R2].left)&&isomorphic(T1[R1].left,T2[R2].right);
}























