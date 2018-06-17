#include<iostream>
#include<cstdio>
#include<cstdlib>
#define OVERFLOW -1
#include<stack>
#include<queue>
using namespace std;



typedef struct BiTNode *BiTree;
struct BiTNode{
    char data;
    BiTree left;
    BiTree right;
};

void PreOrderTraverse(BiTree T){
    if(T==NULL)return;
    //cout<<T->data;
    PreOrderTraverse(T->left);
    //cout<<T->data;
    PreOrderTraverse(T->right);
    cout<<T->data;
}
void CreateBiTree(BiTree *T){
    char ch;
    cin>>ch;
    if(ch=='#')*T=NULL;
    else {
        *T=(BiTree)malloc(sizeof(struct BiTNode));
        if(!*T)exit(OVERFLOW);
        (*T)->data=ch;
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}

void InOrderTraversal(BiTree BT){
    BiTree T=BT;
    stack<BiTree> s;

    while(T||!s.empty()){
        while(T){
            s.push(T);
            T=T->left;
        }
        if(!s.empty()){
            cout<<s.top();
            s.pop();
            T=T->right;
        }
    }
}

void LevelOrderTraversal(BiTree BT){
    queue<char> Q;
    BiTree T;
    if(!BT)return ;
    Q.push(BT->data);
    while(!Q.empty()){
        cout<<Q.front();
        Q.pop();
        if(T->left)Q.push(T->data);
        if(T->right)Q.push(T->data);
    }
}//队列实现层序遍历

int main(){
    BiTree T;
    CreateBiTree(&T);
    //PreOrderTraverse(T);
    InOrderTraversal(T);
    return 0;
    //ABDH#K###E##CFI###G#J##

}
