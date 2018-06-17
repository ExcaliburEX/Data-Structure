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
SElemType *base;//ջ��
SElemType *top;//ջ��
int stacksize;//ջ��ǰ�������
}SqStack;

//�ڶ���ͷ�ļ���������������

//#include<header.h>//���������㷨
//1�������ջ
int InitStack(SqStack &S)
{   int a,i;
S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
if(!S.base)
exit(OVERFLOW);
S.top=S.base;
S.stacksize=STACK_INIT_SIZE;
printf("����׼����ʼ������......");
printf("\n\n");
printf("������ջ��Ԫ�ظ���: ");
scanf("%d",&a);  //aΪջ��Ԫ������
printf("\n");
printf("����ջ������Ԫ��\n");
printf("\n");
for (i = 1; i <= a; i++)
{
printf("�������%d��Ԫ��: ",i);
scanf("%d",&(*S.top));
     printf("\n");
S.top=S.top+1;
}
return OK;
}
//2������ջ
void DestoryStack(SqStack &S)
{
 free(S.base);
}


//3�����ջ
void  ClearStack(SqStack &S)
{
while (S.top != S.base)
{
free(--S.top);
S.top--;
}
}


//4���п�ջ
Status StackEmpty(SqStack &S)
{
if(S.top==S.base)
return TURE;
else
return ERROR;
}
//5����ջ��
Status StackLength(SqStack &S)
{  
  return S.top-S.base;
}


//6��ȡջ��
Status GetTop(SqStack S)
{   
    SElemType e;
if(S.top==S.base)
return ERROR;
e=*(S.top-1);
return e;
}
//7������
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
    


//8��ɾ��ջ��Ԫ��
Status Pop(SqStack &S,SElemType &e)
{
if(S.top==S.base)
return ERROR;
S.top=S.top-1;
e=*S.top;
return e;
}
//9������
void StackTraverse(SqStack &S)
{   SElemType *p;
    for(p=S.top-1;p>=S.base;p--)
{
printf("%5d",*p);
}


}


//��������������

//#include<stdafx.h>
//#include<header1.h>
int main()
{   
int e,n;
    SqStack S;
    InitStack(S);//��ʼ��


printf("\nջ�Ƿ�Ϊ��");
if(StackEmpty==0)//�п�
printf("\nYES");
printf("\nNO");
printf("\n");


printf("ջ��Ϊ��%d\n", StackLength(S));//ջ��
printf("\n");


printf("ջ��Ԫ��Ϊ��%d\n",GetTop(S));
printf("\n");//ȡջ��


printf("ɾ��ջ��Ԫ�أ�%d",Pop(S,e));
printf("\n\n");
printf("����ջ��Ԫ��Ϊ��");
StackTraverse(S);//����




printf("\n����������ֵ��");
scanf("%d", &e);
Push(S, e);
printf("\n");
printf("����ջ��Ԫ��Ϊ��");
StackTraverse(S);//����
printf("\n");
return 0;
}
