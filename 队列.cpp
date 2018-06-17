
#include<stdlib.h>
#include<stdio.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR -1
#define TURE 1
#define FALSE 0
#define OVERFLOW -1


typedef int QElemType;
typedef int Status;
typedef struct {
QElemType *base;
int front;
int rear;
}SqQueue

//头文件二：十个基本操作函数
#include<stdio.h>

Status InitQueue(SqQueue &Q)//初始化
{
Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
if(!Q.base)
exit(OVERFLOW);
Q.front=Q.rear=0;
return OK;
}


void DstoryQueue(SqQueue &Q)//销毁
{
while ( Q.front!= Q.rear)
{
  free(&Q.base[Q.front]);
  Q.front=(Q.front+1)%MAXQSIZE;
}
}


void  ClearQueue(SqQueue &Q)//清空
{  int i=Q.front;
   while (i != Q.rear)
   {
   i=0;
   i++;
   }
   Q.front=Q.rear=0;
}




Status QueueEmpty(SqQueue &Q)//判空
{
if(Q.front==Q.rear) 
return TURE;
return FALSE;
}




Status QueueLength(SqQueue Q)//求队长
{
 return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}




Status GetHead(SqQueue &Q)//取首元素
{  QElemType e;
 if(Q.front==Q.rear)
   return ERROR;
 return e=Q.base[Q.front];
}




Status EnQueue(SqQueue &Q,QElemType e)
{
   if((Q.rear+1)%MAXQSIZE==Q.front)
     return ERROR;
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAXQSIZE;
   return Q.base[Q.rear-1];
}




Status DeQueue(SqQueue &Q)
{   
    QElemType e;
    if(Q.front==Q.rear)
     return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return e;
}




void QueueTraver(SqQueue &Q)
{   
    int i=Q.front;
printf("遍历结果为：");
    while (i!=Q.rear)
     {
      printf("%5d",Q.base[i]); 
      i++;
     }    
}




void CreatQueue(SqQueue &Q)
{
  int n;
  printf("请输入循环队列的长度：");
  scanf_s("%d",&n);
  for (int i = 1; i <=n; i++)
  {
 printf("第%d个元素为：",i);
 scanf_s("%d",&Q.base[Q.rear]);
 Q.rear=(Q.rear+1)%MAXQSIZE;
  }
}

//主函数：测试

//#include "stdafx.h"
//#include"header1.h"




int main()
{   
SqQueue Q;
int a,n,r,x;
printf("\n-------循环队列操作-------\n");
printf("1、初始化队列\n2、创建循环队列\n3、清空队列\n4、销毁队列\n5、判空\n6、求队列长度\n7、取首元素\n8、队尾增加元素\n9、删除队首元素\n10、遍历\n");
printf("\n请输入你要执行的操作：");
r:scanf_s("%d",&n);
printf("\n\n");
switch (n)
{
case 1:InitQueue(Q); 
      printf("\n如果选择其他操作请输入1，退出请输入0\n");
  scanf_s("%d",&x);
  if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
  else
      exit(-1);
      break;
case 2: printf("准备测试队列操作....\n\n");
CreatQueue(Q);//创建循环队列
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); 
break;
case 3:ClearQueue(Q); 
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
 printf("\n请输入你的选择：");
 goto r;
}
else
exit(-1); break;
case 4:DstoryQueue(Q); 
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1);
break;
case 5:if (QueueEmpty(Q) == 0)
printf("队列不空！");
else
printf("队列为空！\n"); 
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
   printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); break;
case 6:  printf("队列长度为:%d", QueueLength(Q));//求队长
printf("\n\n");
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); break;
case 7:printf("首元素为：%d", GetHead(Q));//取首元素
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); break;
case 8:printf("请输入要添加的元素：");
scanf_s("%d", &a);
printf("\n\n你要添加的元素为：%d", EnQueue(Q, a)); 
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); break;
case 9:printf("删除队头元素：%d", DeQueue(Q));//删除
  printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
  scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
}
else
exit(-1); break;
case 10:QueueTraver(Q);
printf("\n\n如果选择其他操作请输入1，退出请输入0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n请输入你的选择：");
goto r;
} 
else
exit(-1); break;
default:printf("请检查后重新输入！");
goto r; 
break;
}
return 0;
}

