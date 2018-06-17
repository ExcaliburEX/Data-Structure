#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define OK 1
#define FALSE -1
#define TURE 1
#define ERROR -1
#define OVERFLOW       -1
#define INFEASIBLE        -1
#define STACK_INIT_SIZE    100  
#define STACKINCREMENT     10 
typedef int SElemType;
typedef int Status;
typedef struct {
SElemType *base;//栈底
SElemType *top;//栈顶
int stacksize;//栈当前最大容量
}SqStack;

//第二个头文件：基本操作函数

//#include<header.h>//基本操作算法
//1、构造空栈
int InitStack(SqStack &S)
{   int a,i;
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base)
exit(OVERFLOW);
S.top=S.base;
S.stacksize=STACK_INIT_SIZE;
printf("正在准备初始化输入......");
printf("\n\n");
printf("请输入栈中元素个数: ");
scanf("%d",&a);  //a为栈中元数个数
printf("\n");
printf("请向栈中输入元素\n");
printf("\n");
for (i = 1; i <= a; i++)
{
printf("请输入第%d个元素: ",i);
scanf("%d",&(*S.top));
     printf("\n");
S.top=S.top+1;
}
return OK;
}
//2、销毁栈
void DestoryStack(SqStack &S)
{
 free(S.base);
}


//3、清空栈
void  ClearStack(SqStack &S)
{
while (S.top != S.base)
{
free(--S.top);
S.top--;
}
}


//4、判空栈
Status StackEmpty(SqStack &S)
{
if(S.top==S.base)
return TURE;
else
return ERROR;
}
//5、求栈长
Status StackLength(SqStack &S)
{  
  return S.top-S.base;
}


//6、取栈顶
Status GetTop(SqStack S)
{   
    SElemType e;
if(S.top==S.base)
return ERROR;
e=*(S.top-1);
return e;
}
//7、插入
Status Push(SqStack &S, SElemType &e)
{
if (S.top - S.base >= S.stacksize)
{
S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
if(!S.base)
exit(OVERFLOW);
S.top=S.base+S.stacksize;
S.stacksize+=STACKINCREMENT;
}
*S.top=e;
S.top++;
return OK;
}
    


//8、删除栈顶元素
Status Pop(SqStack &S,SElemType &e)
{
if(S.top==S.base)
return ERROR;
S.top=S.top-1;
e=*S.top;
return e;
}
//9、遍历
void StackTraverse(SqStack &S)
{   SElemType *p;
    for(p=S.top-1;p>=S.base;p--)
{
printf("%5d",*p);
}


}


//主函数：测试用

//#include<stdafx.h>
//#include<header1.h>
int main()
{   
int e,n;
    SqStack S;
    InitStack(S);//初始化


printf("\n栈是否为空");
if(StackEmpty==0)//判空
printf("\nYES");
printf("\nNO");
printf("\n");


printf("栈长为：%d\n", StackLength(S));//栈长
printf("\n");


printf("栈顶元素为：%d\n",GetTop(S));
printf("\n");//取栈顶


printf("删除栈顶元素：%d",Pop(S,e));
printf("\n\n");
printf("现在栈中元素为：");
StackTraverse(S);//遍历




printf("\n请输入插入的值：");
scanf("%d", &e);
Push(S, e);
printf("\n");
printf("现在栈中元素为：");
StackTraverse(S);//遍历
printf("\n");
return 0;
}
