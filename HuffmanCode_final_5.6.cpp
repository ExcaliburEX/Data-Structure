#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXBIT 1000
#define MAXLEAF 100
#define MAXVALUE 1000
#define MAXNODE MAXLEAF * 2 - 1

typedef struct CodeNode
{
    int bit[MAXBIT];
    int start;
}HCode[MAXNODE];

typedef struct TreeNode
{
    int weight;
    int left;
    int right;
    int parent;
    char value;
}HTree[MAXNODE];

void CreateHuffTree(HTree HuffTree, int n);
void PrintCode(HTree HuffTree,HCode HuffCode,int n);
void Decoding(HTree HuffTree,int n);

int main()
{
    HCode HuffCode;
    HTree HuffTree;
    int n;
    cin >> n;
    CreateHuffTree(HuffTree, n);
    PrintCode(HuffTree,HuffCode,n);
     Decoding(HuffTree, n);
    return 0;
    /*

5
A 1
B 2
C 3
D 4
E 5
010011001011
    */
}

void CreateHuffTree(HTree HuffTree, int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        HuffTree[i].weight = 0;
        HuffTree[i].value = '0';
        HuffTree[i].left = -1;
        HuffTree[i].right = -1;
        HuffTree[i].parent = -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> HuffTree[i].value >> HuffTree[i].weight;
    }
    int m1, m2, x1, x2;
    for (int i = 0; i < n - 1; i++)
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (int j = 0; j < n + i; j++)
        {
            if((HuffTree[j].weight<m1)&&(HuffTree[j].parent==-1))
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffTree[j].weight;
                x1 = j;
            }
            else if ((HuffTree[j].weight < m2) && (HuffTree[j].parent == -1))
            {
                m2 = HuffTree[j].weight;
                x2 = j;
            }
        }

        HuffTree[x1].parent = n + i;
        HuffTree[x2].parent=n+i;
        HuffTree[n + i].weight = HuffTree[x1].weight + HuffTree[x2].weight;
        HuffTree[n+i].left=x1;
        HuffTree[n + i].right = x2;
    }
}

void PrintCode(HTree HuffTree,HCode HuffCode,int n)
{
    int tmp[MAXBIT];
    int c, p,start;
    for(int i = 0;i < n;i++)
    {
        start = n - 1;
        c = i;
        p = HuffTree[c].parent;
       while(p!=-1)
       {
           if(HuffTree[p].left==c)
               tmp[start] = 0;
            else
                tmp[start] = 1;
            start--;
            c = p;
            p = HuffTree[c].parent;
       }
       for (int j = start + 1; j < n;j++)
       {
           HuffCode[i].bit[j] = tmp[j];
       }
       HuffCode[i].start = start;
    }

    for (int i = 0; i < n;i++)
    {
        printf("%c\t", HuffTree[i].value);
        for (int j = HuffCode[i].start+ 1; j < n;j++)
        {
            printf("%d", HuffCode[i].bit[j]);
        }
        printf("\t%d\n", HuffTree[i].weight);
    }
}

void Decoding(HTree HuffTree,int n)
{
    cout << "input a string to decode:\n";
    char string[MAXBIT];
    char num[MAXBIT];
    cin >> string;
    int len = strlen(string);
    for (int i = 0; i < len;i++)
    {
        if(string[i]=='1')
            num[i] = '1';
        else
            num[i] = '0';
    }
    int i = 0;
    int m = 2 * n - 1;
    int tmp;
    while(i<len)
    {
        tmp = m - 1;
        while((HuffTree[tmp].left!=-1)&&(HuffTree[tmp].right!=-1))
        {
            if(num[i]=='0')
                tmp = HuffTree[tmp].left;
            else
                tmp = HuffTree[tmp].right;
            i++;
        }
        cout << HuffTree[tmp].value;
    }
}

