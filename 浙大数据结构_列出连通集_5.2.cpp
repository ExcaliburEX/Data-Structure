#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 10

bool visited[MAX_SIZE];
int G[MAX_SIZE][MAX_SIZE];
int n;
void ListOfComponentswithDFS();
void ListOfComponentswithBFS();
void BFS(int V);
void DFS(int V);
void InitVisit();

int main()
{
    int e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        G[v1][v2]=G[v2][v1]=1;
    }


    ListOfComponentswithBFS();
    InitVisit();
    ListOfComponentswithDFS();
    return 0;
}

void ListOfComponentswithDFS()
{
    for(int V=0;V<n;V++)
    {
        if(!visited[V])
        {
            cout<<"{ ";
            DFS(V);
            cout<<"}\n";
        }
    }
}

void ListOfComponentswithBFS()
{
    for(int V=0;V<n;V++)
    {
        if(!visited[V])
        {
            cout<<"{ ";
            BFS(V);
            cout<<"}\n";
        }
    }
}

void BFS(int V)
{
    visited[V]=true;
    cout<<V<<" ";
    for(int w=0;w<n;w++)
    {
        if(G[V][w]&&!visited[w])
        {
            BFS(w);
        }
    }
}

void DFS(int V)
{
    queue<int> Q;
    Q.push(V);
    visited[V]=true;
    while(!Q.empty())
    {
        int q=Q.front();
        Q.pop();
        cout<<q<<" ";
        for(int i=0;i<n;i++)
        {
            if(G[q][i]&&!visited[i])
            {
                Q.push(i);
                visited[i]=true;
            }
        }
    }
}

void InitVisit()
{
    for(int i=0;i<MAX_SIZE;i++)
        visited[i]=false;
}



















/*
void BFS(int V)
{
    const int MAX_SIZE = 100;
    int Queue[MAX_SIZE];
    int first = -1, last = -1;

    Queue[++last] = V;      //入队
    Visited[V] = true;
    while (first < last)    //当队不为空时
    {
        int F = Queue[++first];     //出队
        printf("%d ", F);
        for (int i = 0; i < n; i++)
        {
            if (G[F][i] && !Visited[i])
            {
                Queue[++last] = i;      //入队
                Visited[i] = true;
            }
        }
    }
}
*/

