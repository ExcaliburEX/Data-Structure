typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};



void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
        printf("%d ", BT->Data); /* ��������Ϊ���� */
        InorderTraversal( BT->Right );
    }
}

void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}

void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}

void LevelorderTraversal ( BinTree BT )
{
    Queue Q;
    BinTree T;

    if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */

    Q = CreatQueue(); /* �����ն���Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}


//����������е�Ҷ�ӽ��
void PreOrderPrintLeave(BinTree BT){
    if(BT){
        if(!BT->Left&&!BT->Right)
            print("%d",BT->Data);
        PreOrderPrintLeave(BT->Left);
        PreOrderPrintLeave(BT->Right);
    }
}
//��������ĸ߶�
int PostOrderGetHeight(BinTree BT){
    int HL,HR,MaxH;
    if(BT){
    HL=PostOrderGetHeight(BT->Left);
    HR=PostOrderGetHeight(BT->Right);
    MaxH=(HL>HR)?HL:HR;
    return (MaxH+1);
    }
    else retur 0;
}
