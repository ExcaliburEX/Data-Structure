#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<cstring>
using namespace std;
#define MAXN 64

typedef struct TreeNode *Tree;
struct TreeNode
{
    int weight;
    Tree left, right;
};

typedef struct HeapNode *Heap;
struct HeapNode
{
    struct TreeNode data[MAXN];
    int size;
};
int colden,N,w[MAXN];
char ch[MAXN];
int flag;
Tree CreateTree();
Heap CreateHeap();
void Insert(Heap H,struct TreeNode T);
Tree Delete(Heap H);
Tree CreateHuffman(Heap H);
int WPL(Tree T, int depth);
int JudgeTree(Tree T);
int judge();

int main()
{

    Tree T = CreateTree();
    Heap H = CreateHeap();
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        cin >> ch[i] >> w[i];
        H->data[H->size].left = H->data[H->size].right = NULL;
        T->weight=w[i];
        Insert(H, *T);
    }
    T = CreateHuffman(H);
    colden=WPL(T,0);
    int n;
    cin >> n;
    while(n--)
    {
        if(judge())cout<<"Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

Tree CreateTree()
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->weight = 0;
    T->left = T->right = NULL;
    return T;
}

Heap CreateHeap()
{
    Heap H=(Heap)malloc(sizeof(struct HeapNode));
    H->size = 0;
    H->data[0].weight = -1;
    return H;
}

void Insert(Heap H,struct TreeNode T)
{
    int i = ++H->size;
    for (; T.weight < H->data[i/2].weight;i/=2)
    {
        H->data[i]= H->data[i/2];
    }
    H->data[i] = T;
}

Tree Delete(Heap H)
{
    int parent, child;
    struct TreeNode Tmp = H->data[H->size--];
    Tree T = CreateTree();
    *T = H->data[1];
    for (parent = 1; 2 * parent <= H->size;parent=child)
    {
        child = 2 * parent;
        while(child!=H->size&&H->data[child].weight>H->data[child+1].weight)
            child++;
        if(Tmp.weight<H->data[child].weight)
            break;
        H->data[parent] = H->data[child];
    }
    H->data[parent] = Tmp;
    return T;
}

Tree CreateHuffman(Heap H)
{
    Tree T=CreateTree();
    while(H->size!=1)
    {
        T->left=Delete(H);
        T->right=Delete(H);
        T->weight = T->left->weight + T->right->weight;
        Insert(H, *T);
    }
    T=Delete(H);
    return T;
}

int WPL(Tree T, int depth)
{
        if(!T->left&&!T->right)
            return T->weight * depth;
        else
            return WPL(T->left, depth + 1) + WPL(T->right, depth + 1);
}

int JudgeTree(Tree T)
{
    if(T){
        if(((!T->left)&&(T->right))||((T->left)&&(!T->right)))
            flag=0;
        JudgeTree(T->left);
        JudgeTree(T->right);
        }   
}


int judge()
{
    char s1[MAXN],s2[MAXN];
    Tree T = CreateTree(), pt = NULL;
    int wgh,i,j,sig=1;
    for (i = 0; i < N;i++)
    {
        cin >> s1 >> s2;
        if(strlen(s2)>N)
            sig = 0;
        for (j = 0; s1[0] != ch[j];j++);
            wgh = w[j];
        pt = T;
        for (j = 0; s2[j];j++)
        {
            if(s2[j]=='0')
            {
                if(!pt->left)
                    pt->left = CreateTree();
                pt = pt->left;
            }
            if(s2[j]=='1')
            {
                if (!pt->right)
                    pt->right = CreateTree();
                pt = pt->right;
            }
            if(pt->weight)
                sig = 0;
            if(!s2[j+1])
            {
                if(pt->left||pt->right)
                    sig = 0;
                pt->weight = wgh;
            }
        }
    }
    if(!sig)
        return 0;
    flag = 1;
    JudgeTree(T);
    if(!flag)
        return 0;
    if(colden==WPL(T,0))
        return 1;
    else
        return 0;

}
