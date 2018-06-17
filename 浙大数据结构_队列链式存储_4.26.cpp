#include<iostream>
#include<cstdlib>
#include<cstdio>
//不带头结点
using namespace std;
typedef int ElementType;
#define OVERFLOW -1
#define ERROR -1
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}

Queue CreateQueue(int Maxsize){
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->Front=Q->Rear=NULL;
    Q->MaxSize=Maxsize;
    return Q;
}

bool AddQ(Queue Q,ElementType X){
    Position q=(Position)malloc(sizeof(struct Node));
    if(!q)exit(OVERFLOW);
    q->Data=X;
    q->Next=NULL;
    if(Q->Front==NULL)
        Q->Front=Q->Rear=q;
    else{
        Q->Rear->Next=q;
        Q->Rear=q;
    }
    return true;
}

ElementType DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementType FrontElem;

    if  ( IsEmpty(Q) ) {
        printf("队列空");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}

int main(){
    int Size;
    cout<<"请输入队列的容量：\n";
    cin>>Size;
    Queue Q=CreateQueue(Size);
    cout<<"A代表入队，B代表出队，P打印队列，E退出\n";
    char in;
    while(cin>>in){
        if(in=='A'){
            cout<<"请输入的数目以及数字\n";
            int num,digit;
            cin>>num;
            for(int i=0;i<num;i++){
                cin>>digit;
                AddQ(Q,digit);
            }

        }
        if(in=='B'){
            cout<<"请输入出队的个数\n";
            int numofde;
            cin>>numofde;
            for(int i=0;i<numofde;i++)
                DeleteQ(Q);
        }
        if(in=='P'){
            Position s=Q->Front;
            while(s){
                cout<<s->Data<<" ";
                s=s->Next;
            }
            cout<<endl;
        }
        if(in=='E')break;
        cout<<"请继续输入指令：\n";

    }
    cout<<"GoodBye";
    return 0;
}
