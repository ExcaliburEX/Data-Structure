#include<iostream>
#include<cstdio>
#include <cstdlib>
#define MAXN 100005
using namespace std;
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

void LSDRadixSort(int A[],int N)
{
    int Di, D, i;
    Bucket B;
    PtrToNode List = NULL, p,tmp;
    for (i = 0; i < Radix;i++)
        B[i].head = B[i].tail = NULL;
    for (i = 0; i < N;i++)
    {//逆序插入
        tmp=(PtrToNode)malloc(sizeof(struct Node));
        tmp->key=A[i];
        tmp->next = List;
        List = tmp;
    }
    for (D = 1; D <=MaxDigit;D++)
    {
        p=List;
        while(p)
        {
            Di=GetDigit(p->key,D);
            tmp = p;
            p = p->next;
            tmp->next = NULL;
            if(B[Di].head==NULL)
            {
                B[Di].head = B[Di].tail = tmp;
            }
            else
            {
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }

        List = NULL;
        for (Di = Radix - 1; Di >= 0;Di--)
        {
            PtrToNode q;
            cout<<Di<<":";
            for(q=B[Di].head;q;q=q->next)
                cout<<q->key<<" ";
            cout<<endl;
            if(B[Di].head)
            {
                B[Di].tail->next = List;
                List=B[Di].head;
                B[Di].head = B[Di].tail = NULL;
            }
        }
        cout<<endl;
    }

    for (i = 0; i < N;i++)
    {
        tmp = List;
        List = List->next;
        A[i]=tmp->key;
        free(tmp);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[MAXN];
    for (int i = 0; i < n;i++)
        cin>>A[i];
    LSDRadixSort(A, n);
    for (int i = 0; i < n;i++)
    cout<<A[i]<<" ";
    return 0;
}
