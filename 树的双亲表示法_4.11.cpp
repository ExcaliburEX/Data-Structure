#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
typedef char ElemType;
typedef struct Snode //结点结构
{
    ElemType data;
    int parent;
} PNode;

typedef struct //树结构
{
    PNode tnode[MAX_SIZE];
    int n; //结点个数
} Ptree;

void InitPNode(Ptree &tree)
{
    int i, j;
    char ch;
    printf("请输入结点个数:\n");
    scanf("%d", &(tree.n));

    printf("请输入结点的序及值其双亲序号:\n");
    for (i = 1; i < tree.n; i++)
    {
        fflush(stdin);
        scanf("%c,%d", &ch, &j);
        tree.tnode[i].data = ch;
        tree.tnode[i].parent = j;
    }
    tree.tnode[0].parent = -1;
}

void FindParent(Ptree &tree)
{
    int i;
    printf("请输入要查询的结点的序号\n");
    scanf("%d", &i);
    printf(" %c 的父亲结点序号为 %d\n", tree.tnode[i].data, tree.tnode[i].parent);
}

int main()
{
    Ptree tree;
    InitPNode(tree);
    while (1) //测试
        FindParent(tree);
    return 0;
}
