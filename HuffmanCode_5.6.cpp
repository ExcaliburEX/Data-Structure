#include <cstring>
#include <iostream>
#include<cstdio>
#include<cstdlib>
#define MAXBIT 1000
#define MAXVALUE 10000
#define MAXLEAF 300
#define MAXNODE MAXLEAF * 2 - 1
using namespace std;

typedef struct
{
    int bit[MAXBIT];
    int start;
} HCode;

typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    char value;
} HTree;

char letter[MAXBIT];
int record[MAXBIT];
int coded[MAXBIT];

void CreateHuffmanTree(HTree HuffmanTree[MAXNODE], int n)
{

    cout<<"there are "<<n<<" kinds of letter"<<endl;
    int i, j, m1, m2, x1, x2;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        HuffmanTree[i].weight = 0;
        HuffmanTree[i].parent = -1;
        HuffmanTree[i].lchild = -1;
        HuffmanTree[i].rchild = -1;
        HuffmanTree[i].value = i;
    }
    //cout << "please input letter and the number:\n";

    /*int s;
    for (i = 0; i < n; i++)
    {
      cin>>s >>HuffmanTree[i].weight;
      HuffmanTree[i].value=letter[s];
    }
    */

    int k=0;
    for (i = 0; i < n; i++)
    {
      while(record[k]==0)k++;
      HuffmanTree[i].weight=record[k];
      HuffmanTree[i].value=letter[k];
      k++;
    }
    for (i = 0; i < n - 1; i++)//n-1是因为两两结合会少一次
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++)
        {
            if (HuffmanTree[j].weight < m1 && HuffmanTree[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffmanTree[j].weight;
                x1 = j;
            }
            else if (HuffmanTree[j].weight < m2 && HuffmanTree[j].parent == -1)
            {
                m2 = HuffmanTree[j].weight;
                x2 = j;
            }
        }
        HuffmanTree[x1].parent = n + i;
        HuffmanTree[x2].parent = n + i;
        HuffmanTree[n + i].weight = HuffmanTree[x1].weight + HuffmanTree[x2].weight;
        HuffmanTree[n + i].lchild = x1;
        HuffmanTree[n + i].rchild = x2;
        /*
        printf("x1.weight and x2.weight in round %d: %d, %d\n", i + 1, HuffmanTree[x1].weight, HuffmanTree[x2].weight);printf("\n"); /* 用于测试 */
        }
}

void Decoding(HTree Buf[],int number)
{
    /* 事实上是从树根到树叶的遍历 */
    //cout << "please input string to decode:\n";
    char string[1000];
    freopen("coded.txt","r",stdin);
    cin >> string;
    freopen("coded.txt","a",stdout);
    int len = strlen(string);
    char num[1024];
    for(int i = 0;i < len;i++)
    {
        if(string[i]=='0')
            num[i]='0';
        else
        {
            num[i] = '1';
        }
    }

    int tmp;
    int m = 2 * number - 1;
    int i=0;

    while(i<len)
    {
        tmp = m - 1;
        while((Buf[tmp].lchild!=-1)&&(Buf[tmp].rchild!=-1))
        {
            if(num[i]=='0')
                tmp = Buf[tmp].lchild;
            else
                tmp = Buf[tmp].rchild;
            i++;
        }

         cout << Buf[tmp].value;
    }
}

void PrintCode(HTree HuffmanTree[],HCode HuffmanCode[],int n)
{
    freopen("codedletter.txt","w",stdout);
    HCode cd;
    int c, p;
    for (int i = 0; i < n; i++)
    {
        cd.start = n - 1;
        c = i;
        p = HuffmanTree[c].parent;
        while (p != -1)
        {
            if (HuffmanTree[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;
            c = p;
            p = HuffmanTree[c].parent;
        }

        for (int j = cd.start + 1; j < n; j++)
        {
            HuffmanCode[i].bit[j] = cd.bit[j];
        }
        HuffmanCode[i].start = cd.start;
    }

    for (int i = 0; i < n; i++)
    {
        cout << HuffmanTree[i].value << "'s HuffmanCode is:";
        for (int j = HuffmanCode[i].start + 1; j < n; j++)
            cout << HuffmanCode[i].bit[j];
            cout << " frequency is:" << HuffmanTree[i].weight;
        cout << endl;
    }
}


void LetterCreate(char letter[])
{

    int len = 60;
    letter[0] = ' ';
    for(int i = 1;i < len;i++)
    {
        letter[i] = 'A' + (i - 1);
    }
    letter[60]='A'-19;//.
    letter[61]='A'-21;//,
    letter[62]='A'-32;// !
    letter[63]='\n';// \n
    letter[64]='A'-2;//?
    letter[65]='A'-31;//"
    letter[66]='A'-26;//'
    for(int i=67;i<77;i++)
        letter[i]='0'+(i-67);

}

void LetterToCode(HTree HuffmanTree[], HCode HuffmanCode[],char code[],int n)
{
    int k = 0,cnt=0;
    for (int i = 0; i < strlen(code);i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(code[i]==HuffmanTree[j].value)
            {
                for (int t = HuffmanCode[j].start + 1; t < n; t++)
                {
                    coded[k++]= HuffmanCode[j].bit[t];
                    cnt++;
                }
            }
        }
    }
    freopen("coded.txt","w",stdout);
    for (int i = 0; i < cnt; i++)
    {
        cout << coded[i];
    }
    cout<<endl;
}

int main()
{
    HTree HuffmanTree[MAXNODE];
    HCode HuffmanCode[MAXLEAF];
    LetterCreate(letter);
    int n=0;
    cout<<"file had changed:\n";
    char Tmpcode[1000];
    char code[1000];
    FILE * fin;
    fin=fopen("bianma.txt","r");

     while (fgets(Tmpcode,100,fin))
     {

        strcat(code,Tmpcode);
        //char tmp;
       // tmp='\n';
      // code[strlen(code)]=tmp;
       //code[strlen(code)+1]='\0';
     }
     fclose(fin);
    // printf("%s", code);
     for (int i = 0; i < strlen(code); i++)
     {
         for (int j = 0; j < MAXBIT; j++)
         {
             if (code[i] == letter[j])
             {
                 record[j]++;
                 break;
             }
         }
        }
    for(int i=0;i<MAXBIT;i++)
    {
        if(record[i]!=0)
           n++;
    }
    CreateHuffmanTree(HuffmanTree,n);
    PrintCode(HuffmanTree, HuffmanCode, n);
   // fflush(stdin);
    LetterToCode(HuffmanTree,HuffmanCode,code,n);
    Decoding(HuffmanTree, n);
    return 0;
}

/*
5
A 1
B 2
C 3
D 4
E 5
010011001011
*/
