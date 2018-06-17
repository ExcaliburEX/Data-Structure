#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node pNode;
typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;
/* ��ʼ��˫��ѭ������head��ͷβ��ָ���� */
void InitList(pNode **head)
{
    pNode *p;
    *head = (pNode *)malloc(sizeof(pNode));
    if ((*head) == NULL)
        exit(0);
    (*head)->next = (*head);
    (*head)->prev = (*head);
}
/* ���룬�������n��λ�ò���Ԫ�� */
pNode *InsertList(pNode **head)
{
    pNode *p, *s;
    int i = 0;
    p = (*head)->prev; //pʼ��ָ��β�ڵ�
    int n;
    printf("The input to the position of the insert:");
    scanf("%d", &n);
    s = (pNode *)malloc(sizeof(pNode));
    if (s == NULL)
        exit(0);
    printf("Input to insert element value:");
    scanf("%d", &s->data);
    if (s->data <= 0)
        return p;
    while(i < n - 1)
    {
        i++;
        p = p->next;
    }
    s->prev = p;
    s->next = p->next;
    p->next->prev = s;
    p->next = s;
    InsertList(head);
}
/* ������ӡ */
void PrintList(pNode *head)
{
    pNode *p;
    p = head->next;//��ͷ���֮��ʼѭ����ӡ
    while(p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/* �����������ͷָ�� */
void ClearList(pNode **head)
{
    pNode *p;
    p = (*head)->next;
    while(p != (*head))
    {
        p = p->next;
        free(p->prev);
    }
    (*head)->next = (*head)->prev = (*head);//ͷ�ڵ������ָ����ָ������
}
/* ������������ͷָ���ÿ� */
void DestroyList(pNode **head)
{
    pNode *p;
    p = (*head)->next;
    while(p != (*head))
    {
        p = p->next;
        free(p->prev);
    }
    free(*head);
    (*head) = NULL;
}
int main(int argc, char const *argv[])
{
    pNode *head, *last;
    InitList(&head);
    last = InsertList(&head);
    PrintList(head);
    ClearList(&head);
    printf("%p %p %p\n", head, head->next, head->prev); //��֤�Ƿ�ͷ�ڵ�ָ������
    DestroyList(&head);
    printf("%p\n",head);//��֤�Ƿ��Ѿ���ȫ����
    return 0;
}
