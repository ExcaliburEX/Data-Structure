#include<iostream>
#include<cstdlib>
#include<cstdio>
//����ͷ���
using namespace std;
typedef int ElementType;
#define OVERFLOW -1
#define ERROR -1
typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    int MaxSize;           /* ����������� */
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
        printf("���п�");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
            Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
        return  FrontElem;
    }
}

int main(){
    int Size;
    cout<<"��������е�������\n";
    cin>>Size;
    Queue Q=CreateQueue(Size);
    cout<<"A������ӣ�B������ӣ�P��ӡ���У�E�˳�\n";
    char in;
    while(cin>>in){
        if(in=='A'){
            cout<<"���������Ŀ�Լ�����\n";
            int num,digit;
            cin>>num;
            for(int i=0;i<num;i++){
                cin>>digit;
                AddQ(Q,digit);
            }

        }
        if(in=='B'){
            cout<<"��������ӵĸ���\n";
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
        cout<<"���������ָ�\n";

    }
    cout<<"GoodBye";
    return 0;
}
