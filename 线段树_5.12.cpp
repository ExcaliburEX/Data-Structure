#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define maxN 1000
typedef long long ll;
struct node
{
    int Left, Right;
    node *Leftchild, *Rightchild;
};

struct Tree
{

    int l, r;
    long long sum;

} tr[maxN << 2];
int a[maxN << 2];
void Build_Tree(int x, int y, int i)
{

    tr[i].l = x;
    tr[i].r = y;

    if (x == y)
        tr[i].sum = a[x]; //找到叶子节点，赋值

    else
    {
        ll mid = (tr[i].l,tr[i].r) >> 1;

        Build_Tree(x, mid, i << 1); //左子树

        Build_Tree(mid + 1, y, i << 1 | 1); //右子树

        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum; //回溯维护区间和
    }
}

void Update_Tree(int q, int val, int i)
{
    if (tr[i].l == q && tr[i].r == q) //找到需要修改的叶子节点
    {
        tr[i].sum = val; //更新当前结点
    }
    else //当前结点是非叶子结点
    {
        long long mid = (tr[i].l,tr[i].r) >> 1; //取中间

        if (q <= mid) //目标节点在左儿子中
        {
            Update_Tree(q, val, i << 1);
        }
        else if (q > mid) //目标节点在右儿子中
        {
            Update_Tree(q, val, i << 1 | 1);
        }
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum; //回溯
    }
}

long long Query_Tree(int q, int w, int i)
{
    if (q <= tr[i].l && w >= tr[i].r)
        return tr[i].sum; //当前结点的区间完全被目标区间包含
    else
    {
        long long mid = (tr[i].l,tr[i].r) >> 1;
        if (q > mid) //完全在左儿子
        {
            return Query_Tree(q, w, i << 1 | 1);
        }
        else if (w <= mid) //完全在右儿子
        {
            return Query_Tree(q, w, i << 1);
        }
        else //目标区间在左右都有分布
        {
            return Query_Tree(q, w, i << 1) + Query_Tree(q, w, i << 1 | 1);
        }
    }
}

int main()
{
    int N, M, q, val, l, r;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    Build_Tree(1, N, 1);
    cin >> M;
    while (M--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            scanf("%d%d", &q, &val);
            Update_Tree(q, val, 1);
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", Query_Tree(l, r, 1));
        }
    }
    return 0;
}
