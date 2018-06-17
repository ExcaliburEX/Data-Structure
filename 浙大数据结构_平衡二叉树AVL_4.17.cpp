#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct AVLNode *Position;
typedef Position AVLTree;

struct AVLNode{
    int Data;
    int Height;
    Position Left;
    Position Right;
};
int GetHeight(AVLTree A){
    int HL,HR,MAXH;
    if(A){
        HL=GetHeight(A->Left);
        HR=GetHeight(A->Right);
        MAXH=max(HL,HR);
        return MAXH+1;
    }
    else return 0;
}


AVLTree SingleLeftRotation(AVLTree T){
    AVLTree S=T->Left;
    T->Left=S->Right;
    S->Right=T;
    T->Height=max(GetHeight(T->Left),GetHeight(T->Right))+1;
    S->Height=max(GetHeight(S->Left),T->Height)+1;
    return S;
}

AVLTree SingleRightRotation(AVLTree T){
    AVLTree S=T->Right;
    T->Right=S->Left;
    S->Left=T;
    T->Height=max(GetHeight(T->Left),GetHeight(T->Right))+1;
    S->Height=max(T->Height,GetHeight(T->Right))+1;
    return S;
}

AVLTree DoubleLeftRightRotation(AVLTree T){
    T->Left=SingleRightRotation(T->Left);
    return SingleLeftRotation(T);
}

AVLTree DoubleRightLeftRotation(AVLTree T){
    T->Right=SingleLeftRotation(T->Right);
    return SingleRightRotation(T);
}

AVLTree Insert(AVLTree T,int x){
    if(!T){
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->Data=x;
        T->Height=0;
        T->Left=T->Right=NULL;
    }
    else if(x<T->Data){
        T->Left=Insert(T->Left,x);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2){
            if(x<T->Left->Data)T=SingleLeftRotation(T);
            else T=DoubleLeftRightRotation(T);
        }
    }
    else if(x>T->Data){
        T->Right=Insert(T->Right,x);
        if(GetHeight(T->Left)-GetHeight(T->Right)==-2){
            if(x>T->Right->Data) T=SingleRightRotation(T);
            else T=DoubleRightLeftRotation(T);
        }
    }

    T->Height=max(GetHeight(T->Left),GetHeight(T->Right))+1;
    return T;
}

void PreOrderTreversal(AVLTree T){
    if(T){
        cout<<T->Data<<" ";
        PreOrderTreversal(T->Left);
        PreOrderTreversal(T->Right);
    }
}

int main(){
    int a[8]={9,8,7,2,3,5,6,4};
    AVLTree T=NULL;
    for(int i=0;i<10;i++)T=Insert(T,a[i]);
    cout<<T->Data;
    PreOrderTreversal(T);
    return 0;
}
