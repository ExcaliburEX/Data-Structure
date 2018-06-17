/*
基础数据结构——单链表（1）
Time Limit: 1000 MS Memory Limit: 10240 K
Total Submit: 1007(345 users) Total Accepted: 367(307 users) Rating: Special Judge: No
Description
输入n个整数，先按照数据输入的顺序建立一个带头结点的单链表，再输入一个数据m,将单链表中的值为m的结点全部删除。分别输出建立的初始单链表和完成删除后的单链表。

Input
第一行输入数据个数n；

第二行依次输入n个整数；

第三行输入欲删除数据m。

Output
第一行输出原始单链表的长度；

第二行依次输出原始单链表的数据；

第三行输出完成删除后的单链表长度；

第四行依次输出完成删除后的单链表数据。

Sample Input
10

56 25 12 33 66 54 7 12 33 12

12

Sample Output
10

56 25 12 33 66 54 7 12 33 12

7

56 25 33 66 54 7 33





#include<stdio.h>//真·链表
#include<stdlib.h>//定义头文件以用于创建新的内存存储新链表
struct number//定义结构体，其中结构体指针用于链表存储下一个结构体首地址
{
    int num;
    struct number *next;
};
int main()
{
    int i,n,a;
    struct number *p1,*head,*p2;//head头指针为链表开始，存储的是地址而不存储第一个元素，p1,p2用于承接新旧两个读取中的链表
    while(scanf("%d",&n)!=EOF)
    {
        p1=NULL;//初始化
        head=NULL;
        p2=NULL;
        for(i=0; i<n; i++)//输入n个数
        {
            scanf("%d",&a);//输入部分
            if(head==NULL)//判断头指针是否为空，即可判断是否是第一个数，此时应存储于head头指针指向的结构体中
            {
                p1=(struct number *)malloc(sizeof(struct number));//创建新的number型结构体内存空间
                head=p1;
                p2=head;//将头指针放到p2中存储
            }
            p1=(struct number *)malloc(sizeof(struct number));
            p2->next=p1;//传递承接，新创建并输入的数放置到p1中
            p1->num=a;
            p1->next=NULL;//并将p1，o2相连
            p2=p1;//传递p1变为2中存储为上一个元素
        }

        int del;
        scanf("%d",&del);
        printf("%d\n",n);
        p2=head->next;
        while(p2!=NULL)//原样输出链表
        {
            printf("%d",p2->num);
            if(p2->next!=NULL)
            {
                printf(" ");
            }
            p2=p2->next;
        }
        printf("\n");


        p2=head->next;//计数部分

	    while(p2!=NULL)
        {
            if(p2->num==del)
            {
                n--;
            }
            p2=p2->next;
        }
        printf("%d\n",n);



        p2=head;//p2指向头指针，并且，p2为上一个元素
        while(p2->next!=NULL)//del删除部分，删去符合条件的元素
        {
            p1=p2->next;//p1为当前读取元素
            if(p1->num==del)//若当前元素符合删除条件,分两种情况，一个为被删除元素为第一个元素时，一个为正常情况
            {
                if(p1==head->next)//当为第一个元素时，讲头指针的next从被删除元素指向下一个元素
                {
                    head->next=p1->next;//此处改变头指针head的指向，头指针依然没变，因此得以在第一步中，p1获取到的是p2，也就是head中，更新后的指向值
                }
                else
                {
                    p2->next=p1->next;//否则上一个元素的next指向被删除元素的next
                 //   p1=p1->next;//p1指向下一个元素，但此时p1，p2指向同一个元素
                }
            }
            else//正常情况
            {
                p2=p1;
                //p1=p1->next;
            }
        }



        p2=head;//输出部分，输出删除后的链表
        while(p2->next!=NULL)
        {
            p2=p2->next;
            printf("%d",p2->num);
            if(p2->next!=NULL)
            {
                printf(" ");
            }
        }

        printf("\n");
        p2=head;
        while(p2!=NULL)//释放所有节点
        {
            p1=p2->next;
            free(p2);//释放的是当前遍历的上一个节点
            p2=p1;
        }

    }
    return 0;
}
*/









#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct number{
    int num;
    struct number *next;
};
int main(){
    int n,a;
    struct number *p1,*p2,*head;
    while(cin>>n){
        p1=NULL;
        p2=NULL;
        head=NULL;
        for(int i=0;i<n;i++){
            cin>>a;
            if(head==NULL){
                p1=(struct number *)malloc(sizeof(struct number));
                head=p1;
                p2=head;
            }
            p1=(struct number *)malloc(sizeof(struct number));
            p2->next=p1;
            p1->num=a;
            p1->next=NULL;
            p2=p1;
        }

        int del;
        cin>>del;
        cout<<n<<endl;
        p2=head->next;
        while(p2!=NULL){
            cout<<p2->num;
            if(p2->next)cout<<" ";
            p2=p2->next;
        }
        cout<<endl;

        p2=head->next;
        while(p2!=NULL){
            if(p2->num==del){
                n--;
            }
            p2=p2->next;
        }
        cout<<n<<endl;

        p2=head;
        while(p2->next!=NULL){
            p1=p2->next;
            if(p1->num==del){
                if(p1==head->next)head->next=p1->next;
                else p2->next=p1->next;
            }else p2=p1;
        }

        p2=head->next;
        while(p2!=NULL){
            cout<<p2->num;
            if(p2->next)cout<<" ";
            p2=p2->next;
        }
        cout<<endl;

        p2=head;
        while(p2){
            p1=p2->next;
            free(p2);
            p2=p1;
        }
    }
    return 0;
}
