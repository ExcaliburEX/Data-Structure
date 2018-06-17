#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
typedef char ElemType;
typedef struct Snode //���ṹ
{
    ElemType data;
    int parent;
} PNode;

typedef struct //���ṹ
{
    PNode tnode[MAX_SIZE];
    int n; //������
} Ptree;

void InitPNode(Ptree &tree)
{
    int i, j;
    char ch;
    printf("�����������:\n");
    scanf("%d", &(tree.n));

    printf("�����������ֵ��˫�����:\n");
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
    printf("������Ҫ��ѯ�Ľ������\n");
    scanf("%d", &i);
    printf(" %c �ĸ��׽�����Ϊ %d\n", tree.tnode[i].data, tree.tnode[i].parent);
}

int main()
{
    Ptree tree;
    InitPNode(tree);
    while (1) //����
        FindParent(tree);
    return 0;
}
