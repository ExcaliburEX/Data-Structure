#define MAXN 1000                  /* �������Ԫ�ظ��� */
typedef int ElementType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef int SetName;               /* Ĭ���ø������±���Ϊ�������� */
typedef ElementType SetType[MAXN]; /* ���輯��Ԫ���±��0��ʼ */
void Union( SetType S, SetName Root1, SetName Root2 )
{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
    /* ��֤С���ϲ���󼯺� */
    if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
        S[Root2] += S[Root1];     /* ����1���뼯��2  */
        S[Root1] = Root2;
    }
    else {                         /* �������1�Ƚϴ� */
        S[Root1] += S[Root2];     /* ����2���뼯��1  */
        S[Root2] = Root1;
    }
}

SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
    if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}

typedef struct{
    Elementype data;
    int parent;
}SetType[MAXN];

int Find(SetType S[],Elementype X){
    int i;
    for(i=0;i<MAXN&&S[i].data!=X;i++);
    if(i>=MAXN)return -1;
    for(;S[i].parent>=0;i=S[i].parent);
    return i;
}

void Union(SetType S[],Elementype X1,Elementype X2){
    int Root1,Root2;
    Root1=Find(S,X1);
    Root2=Find(S,X2);
    if(Root1!=Root2)S[Root2].parent=Root1;
}
