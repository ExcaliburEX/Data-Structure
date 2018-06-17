//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//using namespace std;
//typedef struct HNode *Heap;
//typedef int Elementype;
//#define MAXDATA 1000
//#define ERROR -1
//struct HNode{
//    Elementype *data;
//    int Size;
//    int Capacity;
//};
//typedef Heap Maxheap;
//typedef Heap Minheap;
//
//bool isFull(Maxheap H){
//    return (H->Size==H->Capacity);
//}
//
//bool isEmpty(Maxheap H){
//    return H->Size==0;
//}
//Maxheap H;
//Maxheap CreateHeap(int MAXSIZE){
//    Maxheap H=(Maxheap)malloc(sizeof(struct HNode));
//    H->data=(Elementype *)malloc((MAXSIZE+1)*sizeof(Elementype));
//    H->Size=0;
//    H->Capacity=MAXSIZE;
//    H->data[0]=MAXDATA;
//    return H;
//}
//
//bool Insert(Maxheap H,Elementype X){
//    int i;
//    if(isFull(H))return false;
//    for(i=++H->Size;H->data[i/2]<X;i/=2)
//        H->data[i]=H->data[i/2];
//    H->data[i]=X;
//    return true;
//}
//
//Elementype DeleteMax(Maxheap H){
//    if(isEmpty(H))return ERROR;
//    int parent,child;
//    Elementype Maxitem,X;
//    Maxitem=H->data[1];
//    X=H->data[H->Size--];
//    for(parent=1;parent*2<=H->Size;parent=child){
//        child=parent*2;
//        if((child!=H->Size)&&(H->data[child]<H->data[child+1]))child++;
//        if(X>=H->data[child])break;
//        else H->data[parent]=H->data[child];
//    }
//    H->data[parent]=X;
//    return Maxitem;
//}
//
//void Precdown(Maxheap H,int p){
//    int parent,child;
//    Elementype X;
//    X=H->data[p];
//    for(parent=p;parent*2<=H->Size;parent=child){
//        child=parent*2;
//        if((child!=H->Size)&&(H->data[child]<H->data[child+1]))child++;
//        if(X>=H->data[child])break;
//        else H->data[parent]=H->data[child];
//    }
//        H->data[parent]=X;
//}
//
//void BuildHeap(Maxheap H){
//    for(int i=H->Size/2;i>0;i--)
//        Precdown(H,i);
//}
//
//int main(){
//
//    H=CreateHeap(20);
//    /*
//    int test[11]={4,3,12,10,11,13,7,30,17,26,0};
//    for(int i=0;i<11;i++){
//        Insert(H,test[i]);
//    }
//    */
//    H->Size=8;
//    for(int i=1;i<8;i++){
//        cin>>H->data[i];
//    }
//    BuildHeap(H);
//
//    for(int i=0;i<H->Size;i++)cout<<H->data[i]<<" ";
//    cout<<endl;
//    DeleteMax(H);
//    for(int i=0;i<H->Size;i++)cout<<H->data[i]<<" ";
//    return 0;
//}
//
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}*Tree;
Tree createTree(int *pre,int *ino,int n){
    Tree root=NULL;
    int i=0;
    int pl=0,pr=0;
    int il=0,ir=0;
    int lpre[30],rpre[30];
    int lino[30],rino[30];
    if(n==0){
        return NULL;
    }
    root=(Tree)malloc (sizeof(struct node));
    if(root==NULL){
        return NULL;
    }
    memset(root,0,sizeof(struct node));
    root->data=pre[n-1];
    for(i=0;i<n;i++){
        if((i<=il)&&(ino[i]!=pre[n-1])){
            lino[il++]=ino[i];
        }else if(ino[i]!=pre[n-1]){
            rino[ir++]=ino[i];
        }
    }
    int key=0;
    int he=ir;
    for(i=n-2;i>=0;i--){
        if(++key<(ir+1)){
            rpre[--he]=pre[i];
        }else{
            lpre[i]=pre[i];
        }
    }
    root->right=createTree(rpre,rino,ir);
    root->left=createTree(lpre,lino,il);


    return root;
}

void firstFind(Tree b){
     Tree s[30],p;
     p=b;
    int top=-1;
    while(p||top!=-1){
        if(p){
            printf(" %d",p->data);
            s[++top]=p;
            p=p->left;
        }else{
        p=s[top--];
        p=p->right;
        }


    }


}
int main(){
    int preNode[30];
    int inNode[30];
    Tree root;
    int count=0,count2=0,count3=0;
    scanf("%d",&count);
    count3=count2=count;
    int i=0;
    while(count--){
        scanf("%d",&preNode[i++]);
    }
    i=0;
    while(count2--){
        scanf("%d",&inNode[i++]);
    }
    root=createTree(preNode,inNode,count3);
    printf("Preorder:");
   firstFind(root);


    return 0;


}


