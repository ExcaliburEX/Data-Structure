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

typedef struct HashEntry Cell;//散列表单元类型
struct HashEntry
{
    int Data;
    EntryType Info;
};

typedef struct TblNode *HashTable;//散列表类型
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
        {//奇数
            Newpos=Currentpos+(CNum+1)*(CNum+1)/4;

            if(Newpos>=H->TableSize)
                Newpos%=H->TableSize;
            //cout<<"new "<<Newpos<<endl;
        }
        else
        {
            Newpos=Currentpos-CNum*CNum/4;
            while(Newpos<0)//这里是while，只要小于0，要不断加上去
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
        cout<<"要删除的元素不存在或已经删除！"<<endl;
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
        cout<<"键值已经存在！"<<endl;
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
    cout<<"请输入相关指令："<<endl;
    while(cin>>in)
    {
        if(in=='S')
        {
        cout<<"请输入要查找的数字："<<endl;
        cin>>n;
        if(H->Cells[Find(H,n)].Info==Legitimate)
            cout<<"该元素存储在第"<<Find(H,n)<<"个位置"<<endl;
        else cout<<"未找到该元素，可能是不存在或已删除"<<endl;
        }
        else if(in=='D')
        {
        cout<<"请输入要删除的数字："<<endl;
        cin>>n;
        if(deleted(H,n))cout<<"删除成功！"<<endl;
        else cout<<"删除失败"<<endl;
        }
        else if(in=='I')
        {
            cout<<"请输入要插入的数字："<<endl;
            cin>>n;
            Insert(H,n);
        }
        cout<<"请输入相关指令："<<endl;
    }
}

