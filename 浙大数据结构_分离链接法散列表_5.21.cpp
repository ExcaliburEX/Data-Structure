#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
using namespace std;
#define KEYLENGTH 15
#define MAXTABLESIZE 1000000
typedef char ElementType[KEYLENGTH+1];

typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TBLNode *HashTable;
struct TBLNode
{
    int TableSize;
    List Heads;
};

int NextPrime(int N)
{
    int i,p=(N%2)?N+2:N+1;
    while(p<=MAXTABLESIZE)
    {
        for(i=(int)sqrt(p);i>2;i--)
            if(p%i==0)break;
        if(i==2)break;
        else p+=2;
    }
    return p;
}
HashTable CreateTable(int TableSize)
{
    HashTable H;
    H=(HashTable)malloc(sizeof(struct TBLNode));
    H->TableSize=NextPrime(TableSize);
    H->Heads=(List)malloc(sizeof(struct LNode)*H->TableSize);
    for(int i=0;i<H->TableSize;i++)
    {
        H->Heads[i].data[0]='\0';//事实上第一个节点什么也不存
        H->Heads[i].Next=NULL;
    }
    return H;
}

int Hash(int key,int m)
{
    return key%m;
}
Position Find(HashTable H,ElementType key)
{
    Position P;
    int pos;
    pos=Hash(atoi(key),H->TableSize);
    P=H->Heads[pos].Next;
    while(P&&strcmp(P->data,key))
        P=P->Next;
    return P;
}

bool Insert(HashTable H,ElementType key)
{
    Position P,NewCell;
    int pos;
    P=Find(H,key);
    if(!P)
    {
        NewCell=(Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->data,key);
        pos=Hash(atoi(key),H->TableSize);
        NewCell->Next=H->Heads[pos].Next;
        H->Heads[pos].Next=NewCell;
        return true;
    }
    else
    {
        cout<<"existed!\n";
        return false;
    }

}

void DestroyTable(HashTable H)
{
    Position P,Tmp;
    for(int i=0;i<H->TableSize;i++)
    {
        P=H->Heads[i].Next;
        while(P)
        {
            Tmp=P->Next;
            free(P);
            P=Tmp;
        }
    }
    free(H->Heads);
    free(H);
}


int main()
{
    HashTable H=CreateTable(10);
    ElementType n;
    Position P;
    cout<<"H->TableSize: "<<H->TableSize<<endl;
    while(1)
    {
        cout<<"Please input number to Insert: ";
        for(int i=0;i<5;i++)
        {
            cin>>n;
            Insert(H,n);
        }
        for(int i=0;i<5;i++)
        {
            cout<<i<<":";
            P=H->Heads[i].Next;
            while(P)
            {
                cout<<P->data<<" ";
                P=P->Next;
            }
            cout<<endl;
        }
    }
    DestroyTable(H);
    return 0;
}
