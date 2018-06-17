#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
    int data;
    int height;
    Position left;
    Position right;
};

int GetHeight(AVLTree T)
{
    int HL,HR,MaxH;
    if(T)
    {
        HL=GetHeight(T->left);
        HR=GetHeight(T->right);
        MaxH=max(HL,HR);
        return MaxH+1;
    }
    else return 0;
}

AVLTree SingleLeftRotation(AVLTree T)
{
    AVLTree S=T->left;
    T->left=S->right;
    S->right=T;
    T->height=max(GetHeight(T->left),GetHeight(T->right))+1;
    S->height=max(GetHeight(S->left),T->height)+1;
    return S;
}

AVLTree SingleRightRotation(AVLTree T)
{
    AVLTree S=T->right;
    T->right=S->left;
    S->left=T;
    T->height=max(GetHeight(T->left),GetHeight(T->right))+1;
    S->height=max(GetHeight(S->right),T->height)+1;
    return S;
}

AVLTree DoubleLeftRightRotation(AVLTree T)
{
    T->left=SingleRightRotation(T->left);
    return SingleLeftRotation(T);
}

AVLTree DoubleRightLeftRotation(AVLTree T)
{
    T->right=SingleLeftRotation(T->right);
    return SingleRightRotation(T);
}

AVLTree InsertAVLTree(AVLTree T,int x)
{
    if(!T)
    {
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->data=x;
        T->height=0;
        T->left=T->right=NULL;
    }
    else if(x<T->data)
    {
        T->left=InsertAVLTree(T->left,x);
        if(GetHeight(T->left)-GetHeight(T->right)==2)
        {
            if(x<T->left->data) T=SingleLeftRotation(T);
            else T=DoubleLeftRightRotation(T);
        }
    }
    else if(x>T->data)
    {
        T->right=InsertAVLTree(T->right,x);
        if(GetHeight(T->left)-GetHeight(T->right)==-2)
        {
            if(x>T->right->data) T=SingleRightRotation(T);
            else T=DoubleRightLeftRotation(T);
        }

    }
    T->height=max(GetHeight(T->left),GetHeight(T->right))+1;
    return T;
}

int main()
{
    AVLTree T=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        T=InsertAVLTree(T,num);
    }
    cout<<T->data;
    return 0;
}

