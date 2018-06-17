#include<iostream>
#include<cstdlib>
#include<cstdio>
#define ERROR -1
using namespace std;
typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack( )
{ /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
    return ( S->Next == NULL );
}

bool Push( Stack S, ElementType X )
{ /* ��Ԫ��Xѹ���ջS */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

ElementType Pop( Stack S )
{ /* ɾ�������ض�ջS��ջ��Ԫ�� */
    PtrToSNode FirstCell;
    ElementType TopElem;

    if( IsEmpty(S) ) {
        printf("��ջ��");
        return ERROR;
    }
    else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}


int main(){
    Stack S=CreateStack();
    cout<<"������ָ�A����push��B����pop��P�����ӡ��ջ��E�����˳���\n";
    char in;
    while(cin>>in){
        if(in=='A'){
            cout<<"������ѹ�����Ŀ��������ֵ��\n";
            int n,m;
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>m;
                Push(S,m);
            }
        }
        if(in=='B'){
            cout<<"������pop����Ŀ��\n";
            int p;
            cin>>p;
            while(p--)Pop(S);
        }
        if(in=='P'){
            Stack q;
            q=S->Next;
            while(q){
                cout<<q->Data<<" ";
                q=q->Next;
            }
            cout<<endl;
        }
        if(in=='E')break;
        cout<<"���������ָ�\n";
    }
    cout<<"GoodBye";
    return 0;
}
