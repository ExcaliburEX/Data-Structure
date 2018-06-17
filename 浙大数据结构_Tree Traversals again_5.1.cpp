/*
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
#define Maxn 30
typedef struct Node *TreeNode;
typedef struct Node{
    int data;
    TreeNode left,right;
};
void PostorderTraversal(TreeNode tree);
TreeNode stack[Maxn];
int values[Maxn];
int num=0;
int top=-1;
int main()
{
    int n;
    string operat;
    TreeNode father,root;
    bool findroot=0,poped=0;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>operat;
        if(operat=="Push")
        {
            int value;
            cin>>value;
            TreeNode NewNode;
            NewNode=(TreeNode)malloc(sizeof(struct Node));
            NewNode->data=value;
            NewNode->left=NewNode->right=NULL;
            if(!findroot)
            {
                root=NewNode;
                stack[++top]=NewNode;
                findroot=1;
            }
            else
            {
                if(!poped)
                    father=stack[top];
                if(father->left==NULL)
                    father->left=NewNode;
                else
                    father->right=NewNode;
                stack[++top]=NewNode;
            }
            poped=0;
        }
        else
        {
            father=stack[top--];
            poped=1;
        }
    }
    PostorderTraversal(root);
    for(int i=0;i<num-1;i++)
        cout<<values[i]<<" ";
    cout<<values[num-1];
    return 0;
}

void PostorderTraversal(TreeNode root)
{
    TreeNode tree=root;
    if(tree){
       PostorderTraversal(tree->left);
       PostorderTraversal(tree->right);
        values[num++]=tree->data;
    }
*/



//µ›πÈ–¥∑®
#include<iostream>
#include<string>
void solve(int preL,int inL,int postL,int n);
using namespace std;
const int N=30;
int pre[N];
int x=0;
int y=0;
int in[N];
int post[N];
int stack[N];
int top=-1;

int main()
{
    int N;
    cin>>N;
    int num;
    for(int i=0;i<2*N;i++)
    {
        string s;
        cin>>s;
        if(s=="Push")
        {
            cin>>num;
            pre[x++]=num;
            stack[++top]=num;
        }
        else in[y++]=stack[top--];
    }
    //for(int i=0;i<N;i++)cout<<pre[i]<<" ";cout<<endl;
    //for(int i=0;i<N;i++)cout<<in[i]<<" ";cout<<endl;
    solve(0,0,0,N);
    for(int i=0;i<N-1;i++)
        cout<<post[i]<<" ";
    cout<<post[N-1];
    return 0;
}

void solve(int preL,int inL,int postL,int n)
{
    int j;
    int root;
    int L,R;
    if(n==0)return;
    if(n==1)
    {
        post[postL]=pre[preL];
        return;
    }
    root=pre[preL];
    post[postL+n-1]=root;
    for(j=0;j<n;j++)
        if(in[inL+j]==root)break;
    L=j;
    R=n-L-1;
    solve(preL+1,inL,postL,L);
    solve(preL+L+1,inL+L+1,postL+L,R);
}
