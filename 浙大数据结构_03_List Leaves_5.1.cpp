#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
#define Maxn 10
typedef struct __Node *Node;
struct __Node{
    int index;
    int left;
    int right;
};

int isRoot[Maxn];
int n;

Node NodeCreate(){
    Node node;
    node=(Node)malloc(sizeof(struct __Node)*Maxn);
    cin>>n;
    char left,right;
    for(int i=0;i<n;i++){
        node[i].index=i;
        cin>>left>>right;
        if(left!='-')
            node[i].left=left-'0';
        else node[i].left=-1;
        if(right!='-')
            node[i].right=right-'0';
        else node[i].right=-1;
    }
    return node;
}

int FindRoot(Node node){
    int root=0;
    for(int i=0;i<n;i++){
        if(node[i].left!=-1)
            isRoot[node[i].left]=1;
        if(node[i].right!=-1)
            isRoot[node[i].right]=1;
    }

    for(int i=0;i<n;i++){
        if(isRoot[i]==0){
            root=i;
            break;
        }
    }
    return root;
}

void LevelorderTraversal(Node node,int root){
    queue<Node> q;
    int flag=0;
    q.push(&node[root]);
    while(!q.empty()){
        Node curnode=q.front();
        q.pop();
        if(curnode->left!=-1)
            q.push(&node[curnode->left]);
        if(curnode->right!=-1)
            q.push(&node[curnode->right]);
        if(curnode->left==-1&&curnode->right==-1){
            if(!flag){
                cout<<curnode->index;
                flag=1;
            }
            else cout<<" "<<curnode->index;
        }
    }
}


int main(){
    Node node=NodeCreate();
    int root=FindRoot(node);
    LevelorderTraversal(node,root);
    return 0;
}
