

typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};

BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST ){ /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X );   /*�ݹ����������*/
        else  if( X > BST->Data )
            BST->Right = Insert( BST->Right, X ); /*�ݹ����������*/
        /* else X�Ѿ����ڣ�ʲô������ */
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position Tmp;

    if( !BST )
        printf("Ҫɾ����Ԫ��δ�ҵ�");
    else {
        if( X < BST->Data )
            BST->Left = Delete( BST->Left, X );   /* ���������ݹ�ɾ�� */
        else if( X > BST->Data )
            BST->Right = Delete( BST->Right, X ); /* ���������ݹ�ɾ�� */
        else { /* BST����Ҫɾ���Ľ�� */
            /* �����ɾ����������������ӽ�� */
            if( BST->Left && BST->Right ) {
                /* ��������������С��Ԫ�����ɾ����� */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* ����������ɾ����СԪ�� */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* ��ɾ�������һ�������ӽ�� */
                Tmp = BST;
                if( !BST->Left )       /* ֻ���Һ��ӻ����ӽ�� */
                    BST = BST->Right;
                else                   /* ֻ������ */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}

Position Find(ElementType X,BinTree BST){
    if(!BST)return NULL;
    if(X>BST->Data)return Find(X,BST->Right);
    else if(X<BST->Data)return Find(X,BST->Left);
    else return BST;
}

//�ǵݹ����
Position IterFind(ElementType X,BinTree BST){
    while(BST){
        if(X>BST->Data)BST=BST->Right;
        else if(X<BST->Data)BST=BST->Left;
        else return BST;
    }
    return NULL;
}

Position FindMin(Bintree BST){
    if(!BST)return NULL;
    else if(!BST->Left)return BST;
    else return FindMin(BST->Left);
}

Position FindMax(BinTree BST){
    if(BST)while(BST->Right)BST=BST->Right;
    return BST;
}
