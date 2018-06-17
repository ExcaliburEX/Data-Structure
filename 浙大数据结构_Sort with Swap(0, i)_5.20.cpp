//#include<stdio.h>
//#define Max 100000
//
//int main()
//{
//    int A[Max],Table[Max],flag[Max],N;
//    int i,tmp,S,K;
//    S=K=0;
//    scanf("%d",&N);
//    for (i=0;i<N;i++)
//    {
//        scanf("%d",&A[i]);
//        flag[i]=0;   //标识元素访问过了没有
//    }
//    /* 指针数组，用来存放正确的序号 */
//    for (i=0;i<N;i++)
//    {
//        Table[A[i]]=i;  //即元素A[i]存放在序号i中
//    }
//
//    for (i=0;i<N;i++)
//    {
//        if (flag[i]==0)
//        {
//            if (Table[i]!=i)
//            {
//                flag[i]=1;
//                tmp=Table[i];
//               while(flag[tmp]==0)
//               {
//                    flag[tmp]=1;
//                    tmp=Table[tmp];
//               }
//               K++;
//            }
//            else if (Table[i]==i)
//            {
//                flag[i]=1;
//                S++;
//            }
//        }
//    }
//    if (A[0]==0)printf("%d",N-S+K);
//    else if (S==N)printf("0");
//    else printf("%d",N-S+K-2);
//    return 0;
//}

#include <iostream>
using namespace std;
int first = 1;
int search(int* p, int num)
{

    for (int i = first; i<num; i++)
        if (p[i] != i)
            return first=i;
    return 0;
}

void swap(int* p, int n)
{
    int temp = p[0];
    p[0] = p[n];
    p[n] = temp;
}

int main()
{
    int n;
    cin >> n;
    int *data = new int[n];
    int temp;
    for (int i = 0; i<n; i++)
    {
        cin >> temp;
        data[temp] = i;
    }
     for (int i = 0; i<n; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    int count = 0;
    while (true)
    {
        if (data[0])
            swap(data, data[0]);
        else
        {
            temp = search(data, n);
            if (!temp) break;
            swap(data, temp);
        }
        count++;
        for (int i = 0; i<n; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    cout << count << endl;
    delete[] data;
    return 0;
}
