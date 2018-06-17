#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

typedef struct LNode *Position;
typedef Position List;
struct LNode
{
    char account[11],password[17];
    Position Next;
};

typedef struct TBLNode *HashTable;
struct TBLNode
{
    int TableSize;
    List Heads;
};

int NextPrime(int N)
{
    if(N==1)return 2;
    int i,p=(N%2)?N+2:N+1;
    while(1)
    {
        for(i=(int)sqrt(p);i>2;i--)
            if(p%i==0)break;
        if(i==2)break;
        else p+=2;
    }
    return p;
}

HashTable CreateTable(int Size)
{
    HashTable H;
    H=(HashTable)malloc(sizeof(struct TBLNode));
    H->TableSize=NextPrime(Size);
    H->Heads=(List)malloc(sizeof(struct LNode)*H->TableSize);
    for(int i=0;i<H->TableSize;i++)
    {
        H->Heads[i].account[0]='\0';
        H->Heads[i].password[0]='\0';
        H->Heads[i].Next=NULL;
    }
    return H;
}

int Hash(int key,int m)
{
    return key%m;
}

Position Find(char key[],HashTable H)
{
    Position P;
    int pos=Hash(atoi(key+3),H->TableSize);
    P=H->Heads[pos].Next;
    while(P&&strcmp(P->account,key))
        P=P->Next;
    return P;
}

int FindAccount(char key[],HashTable H)
{
    Position P;
    int pos=Hash(atoi(key+3),H->TableSize);
    P=H->Heads[pos].Next;
    while(P)
    {
        if(strcmp(key,P->account)==0)
            return 1;
        P=P->Next;
    }
    return 0;
}

void Insert(char key1[],char key2[],HashTable H)
{
    int pos;
    Position P,Tmp;
    P=Find(key1,H);
    pos=Hash(atoi(key1+3),H->TableSize);
    if(P==NULL){
    Tmp=(List)malloc(sizeof(struct LNode));
    strcpy(Tmp->account,key1);
    strcpy(Tmp->password,key2);
    Tmp->Next=H->Heads[pos].Next;
    H->Heads[pos].Next=Tmp;
    }
}

int CheckPassword(Position P,char password[])
{
    if(strcmp(P->password,password)==0)return 1;
    else return 0;
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
    int n;
    cin>>n;
    HashTable H=CreateTable(n);
    char c,s1[11]={},s2[17]={};
    for(int i=0;i<n;i++)
    {
        cin>>c>>s1>>s2;
        if(c=='N')
        {
            if(FindAccount(s1,H)!=1)
            {
                Insert(s1,s2,H);
                cout<<"New: OK\n";
            }else
                cout<<"ERROR: Exist\n";
        }
        if(c=='L')
        {
            if(FindAccount(s1,H)==1)
            {
                if(CheckPassword(Find(s1,H),s2))
                    cout<<"Login: OK\n";
                else
                    cout<<"ERROR: Wrong PW\n";
            }
            else
                cout<<"ERROR: Not Exist\n";
        }
    }
    DestroyTable(H);
    return 0;
}
