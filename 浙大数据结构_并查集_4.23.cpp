#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */
void Union( SetType S, SetName Root1, SetName Root2 )
{ /* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
}

SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
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
