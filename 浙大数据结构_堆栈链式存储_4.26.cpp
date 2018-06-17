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
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return ( S->Next == NULL );
}

bool Push( Stack S, ElementType X )
{ /* 将元素X压入堆栈S */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

ElementType Pop( Stack S )
{ /* 删除并返回堆栈S的栈顶元素 */
    PtrToSNode FirstCell;
    ElementType TopElem;

    if( IsEmpty(S) ) {
        printf("堆栈空");
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
    cout<<"请输入指令，A代表push，B代表pop，P代表打印堆栈，E代表退出：\n";
    char in;
    while(cin>>in){
        if(in=='A'){
            cout<<"请输入压入的数目与具体的数值：\n";
            int n,m;
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>m;
                Push(S,m);
            }
        }
        if(in=='B'){
            cout<<"请输入pop的数目：\n";
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
        cout<<"请继续输入指令：\n";
    }
    cout<<"GoodBye";
    return 0;
}
