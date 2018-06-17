#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXTABLESIZE 1000000
#define KEYLENGTH 11
#define MAXD 5
using namespace std;
typedef char ElementType[KEYLENGTH+1];
typedef struct LNode *Ptr;
struct LNode
{
    ElementType data;
    Ptr Next;
    int count;
};
typedef Ptr Position;
typedef Ptr List;

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

HashTable CreatTable(int Size)
{
    HashTable H;
    H=(HashTable)malloc(sizeof(struct TBLNode));
    H->TableSize=NextPrime(Size);
    H->Heads=(List)malloc(sizeof(struct LNode)*H->TableSize);
    for(int i=0;i<H->TableSize;i++)
    {
        H->Heads[i].data[0]='\0';
        H->Heads[i].Next=NULL;
        H->Heads[i].count=0;
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
    int pos=Hash(atoi(key+KEYLENGTH-MAXD),H->TableSize);
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
        pos=Hash(atoi(key+KEYLENGTH-MAXD),H->TableSize);
        strcpy(NewCell->data,key);
        NewCell->count=1;
        NewCell->Next=H->Heads[pos].Next;
        H->Heads[pos].Next=NewCell;
        return true;
    }
    else
    {
        P->count++;
        return false;
    }
}
void ScanAndOutput(HashTable H)
{
    int Maxcnt,Pcnt;
    Maxcnt=Pcnt=0;
    ElementType MinPhone;
    List Ptr;
    MinPhone[0]='\0';
    for(int i=0;i<H->TableSize;i++)
    {
        Ptr=H->Heads[i].Next;
        while(Ptr)
        {
            if(Ptr->count>Maxcnt)
            {
                Maxcnt=Ptr->count;
                strcpy(MinPhone,Ptr->data);
                Pcnt=1;
            }
            else if(Ptr->count==Maxcnt)
            {
                Pcnt++;
                if(strcmp(MinPhone,Ptr->data)>0)
                {
                    strcpy(MinPhone,Ptr->data);
                }
            }
            Ptr=Ptr->Next;
        }
    }
    printf("%s %d",MinPhone,Maxcnt);
    if(Pcnt>1)printf(" %d",Pcnt);
    printf("\n");
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
    int N;
    ElementType key;
    cin>>N;
    HashTable H=CreatTable(2*N);
    for(int i=0;i<N;i++)
    {
       // scanf("%s",key);
        cin>>key;
        Insert(H,key);
        cin>>key;
        //scanf("%s",key);
        Insert(H,key);
    }
    ScanAndOutput(H);
    DestroyTable(H);
    return 0;
}

