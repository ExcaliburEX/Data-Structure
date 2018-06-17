#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define MAXTABLESIZE 100000

typedef enum
{
    Legitimate,
    Empty,
    Deleted
}EntryType;

typedef struct HashEntry Cell;//ɢ�б�Ԫ����
struct HashEntry
{
    int Data;
    EntryType Info;
};

typedef struct TblNode *HashTable;//ɢ�б�����
struct TblNode
{
    int TableSize;
    Cell *Cells;
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

HashTable CreateTable(int Size)
{
    HashTable H;
    int i;
    H=(HashTable)malloc(sizeof(struct TblNode));
    H->TableSize=NextPrime(Size);
    H->Cells=(Cell *)malloc(sizeof(Cell)*H->TableSize);
    for(i=0;i<H->TableSize;i++)
        H->Cells[i].Info=Empty;
    return H;
}

int Hash(int key,int m)
{
    return key%m;
}

int Find(HashTable H,int key)
{
    int Currentpos,Newpos;
    int CNum=0;
    Newpos=Currentpos=Hash(key,H->TableSize);
    while(H->Cells[Newpos].Info!=Empty&&H->Cells[Newpos].Data!=key)//H->Cells[Newpos].Data!=key
    {
        if((CNum+1)/2>=H->TableSize||CNum/2>=H->TableSize)break;
        if(++CNum%2)
        {//����
            Newpos=Currentpos+(CNum+1)*(CNum+1)/4;

            if(Newpos>=H->TableSize)
                Newpos%=H->TableSize;
            //cout<<"new "<<Newpos<<endl;
        }
        else
        {
            Newpos=Currentpos-CNum*CNum/4;
            while(Newpos<0)//������while��ֻҪС��0��Ҫ���ϼ���ȥ
                Newpos+=H->TableSize;
            //cout<<"new "<<Newpos<<endl;
        }
    }
    return  Newpos;
}

int deleted(HashTable H,int key)
{
    int pos=Find(H,key);
    if(H->Cells[pos].Info==Legitimate)
    {
        H->Cells[pos].Info=Deleted;
        return true;
    }
    else
    {
        cout<<"Ҫɾ����Ԫ�ز����ڻ��Ѿ�ɾ����"<<endl;
        return false;
    }
}

bool Insert(HashTable H,int key)
{
    int pos=Find(H,key);
    if(H->Cells[pos].Info!=Legitimate)
    {
        H->Cells[pos].Info=Legitimate;
        H->Cells[pos].Data=key;
        return true;
    }
    else
    {
        cout<<"��ֵ�Ѿ����ڣ�"<<endl;
        return false;
    }
}

int main()
{
    HashTable H=CreateTable(4);
    cout<<"H->TableSize:"<<H->TableSize<<endl;
    int n;
    for(int i=0;i<5;i++)
    {
        cin>>n;
        Insert(H,n);
    }
    char in;
    cout<<"���������ָ�"<<endl;
    while(cin>>in)
    {
        if(in=='S')
        {
        cout<<"������Ҫ���ҵ����֣�"<<endl;
        cin>>n;
        if(H->Cells[Find(H,n)].Info==Legitimate)
            cout<<"��Ԫ�ش洢�ڵ�"<<Find(H,n)<<"��λ��"<<endl;
        else cout<<"δ�ҵ���Ԫ�أ������ǲ����ڻ���ɾ��"<<endl;
        }
        else if(in=='D')
        {
        cout<<"������Ҫɾ�������֣�"<<endl;
        cin>>n;
        if(deleted(H,n))cout<<"ɾ���ɹ���"<<endl;
        else cout<<"ɾ��ʧ��"<<endl;
        }
        else if(in=='I')
        {
            cout<<"������Ҫ��������֣�"<<endl;
            cin>>n;
            Insert(H,n);
        }
        cout<<"���������ָ�"<<endl;
    }
}

