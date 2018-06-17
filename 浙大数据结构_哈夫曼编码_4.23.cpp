#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef int Elementype;
typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    int weight;
    HuffmanTree Left,Right;
};
#define MINDATA -1000
#define ERROR -1
typedef struct HNode *Minheap;
struct HNode{
    Elementype *data;
    int Size;
    int Capacity;
};

bool isFull(Minheap H){
    return (H->Size==H->Capacity);
}

bool isEmpty(Minheap H){
    return H->Size==0;
}

Minheap CreateHeap(int MAXSIZE){
    Minheap H=(Minheap)malloc(sizeof(struct HNode));
    H->data=(Elementype *)malloc((MAXSIZE+1)*sizeof(Elementype));
    H->Size=0;
    H->Capacity=MAXSIZE;
    H->data[0]=MINDATA;
    return H;
}

void Precdown(Minheap H,int p){
    int parent,child;
    Elementype X;
    X=H->data[p];
    for(parent=p;parent*2<=H->Size;parent=child){
        child=parent*2;
        if((child!=H->Size)&&(H->data[child]>H->data[child+1]))child++;
        if(X<=H->data[child])break;
        else H->data[parent]=H->data[child];
    }
        H->data[parent]=X;
}

void BuildHeap(Minheap H){
    for(int i=H->Size/2;i>0;i--)
        Precdown(H,i);
}

Elementype DeleteMin(Minheap H){
    if(isEmpty(H))return ERROR;
    int parent,child;
    Elementype Minitem,X;
    Minitem=H->data[1];
    X=H->data[H->Size--];
    for(parent=1;parent*2<=H->Size;parent=child){
        child=parent*2;
        if((child!=H->Size)&&(H->data[child]>H->data[child+1]))child++;
        if(X<=H->data[child])break;
        else H->data[parent]=H->data[child];
    }
    H->data[parent]=X;
    return Minitem;
}

bool Insert(Minheap *H,Elementype X){
    int i;
    if(isFull(*H))return false;
    for( i=++(*H)->Size;(*H)->data[i/2]>X;i/=2)
        (*H)->data[i]=(*H)->data[i/2];
    (*H)->data[i]=X;
    return true;
}

HuffmanTree Huffman(Minheap H){
    int i;
    HuffmanTree T;
    BuildHeap(H);
    for(i=1;i<H->Size;i++){
        T=(HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left=DeleteMin(H);
        T->Right=DeleteMin(H);
        T->weight=T->Left->weight+T->Right->weight;
        Insert(&H,T->weight);
    }
    T->weight=DeleteMin(H);
    return T;
}

void PreOrderReversal(HuffmanTree T){
    if(T){
        cout<<T->weight;
        PreOrderReversal(T->Left);
        PreOrderReversal(T->Right);
    }
}

int main(){
    Minheap H=CreateHeap(6);
    for(int i=1;i<6;i++){
        cin>>H->data[i];
    }
    HuffmanTree T=Huffman(H);
    PreOrderReversal(T);
    return 0;
}
