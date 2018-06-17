#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 100005
#define Radix 10
#define MaxDigit 4
typedef struct Node *PtrToNode;
struct Node
{
    int key;
    PtrToNode next;
};

struct HeadNode
{
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int x,int D)
{
    int d, i;
    for (i = 1; i <= D;i++)
    {
        d = x % Radix;
        x /= Radix;
    }
    return d;
}

void MSD(int A[],int L,int R,int D)
{
    int Di,i,j;
    B
    for (i = 0; i < Radix;i++)ucket B;
    PtrToNode tmp, p, List = NULL;
    if(D==0)
        return;
        B[i].head = B[i].tail = NULL;
    for (i = L; i <= R;i++)//significant->[L,R]
    {
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    p = List;
    while(p)
    {
        Di=GetDigit(p->key,D);
        tmp = p;
        p = p->next;
        /* 头插法 */
        if(B[Di].head==NULL)
            B[Di].tail = tmp;
        tmp->next = B[Di].head;//第一次时head指向为空，所以第一个节点的next会置空
        B[Di].head = tmp;
    }
    i = j = L;
    for (Di = 0; Di < Radix;Di++)
    {
        if(B[Di].head)
        {
            p = B[Di].head;
            while(p)
            {
                tmp = p;
                p = p->next;
                A[j++] = tmp->key;
                free(tmp);
            }
            MSD(A, i, j - 1, D - 1);
            i = j;
        }
    }
}

void MSDRadixSort(int A[],int N)
{
    MSD(A, 0, N - 1, MaxDigit);
}

int main()
{
    int n;
    cin >> n;
    int A[MAXN];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    MSDRadixSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}
