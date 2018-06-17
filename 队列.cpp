
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

//ͷ�ļ�����ʮ��������������
#include<stdio.h>

Status InitQueue(SqQueue &Q)//��ʼ��
{
Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
if(!Q.base)
exit(OVERFLOW);
Q.front=Q.rear=0;
return OK;
}


void DstoryQueue(SqQueue &Q)//����
{
while ( Q.front!= Q.rear)
{
  free(&Q.base[Q.front]);
  Q.front=(Q.front+1)%MAXQSIZE;
}
}


void  ClearQueue(SqQueue &Q)//���
{  int i=Q.front;
   while (i != Q.rear)
   {
   i=0;
   i++;
   }
   Q.front=Q.rear=0;
}




Status QueueEmpty(SqQueue &Q)//�п�
{
if(Q.front==Q.rear) 
return TURE;
return FALSE;
}




Status QueueLength(SqQueue Q)//��ӳ�
{
 return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}




Status GetHead(SqQueue &Q)//ȡ��Ԫ��
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
printf("�������Ϊ��");
    while (i!=Q.rear)
     {
      printf("%5d",Q.base[i]); 
      i++;
     }    
}




void CreatQueue(SqQueue &Q)
{
  int n;
  printf("������ѭ�����еĳ��ȣ�");
  scanf_s("%d",&n);
  for (int i = 1; i <=n; i++)
  {
 printf("��%d��Ԫ��Ϊ��",i);
 scanf_s("%d",&Q.base[Q.rear]);
 Q.rear=(Q.rear+1)%MAXQSIZE;
  }
}

//������������

//#include "stdafx.h"
//#include"header1.h"




int main()
{   
SqQueue Q;
int a,n,r,x;
printf("\n-------ѭ�����в���-------\n");
printf("1����ʼ������\n2������ѭ������\n3����ն���\n4�����ٶ���\n5���п�\n6������г���\n7��ȡ��Ԫ��\n8����β����Ԫ��\n9��ɾ������Ԫ��\n10������\n");
printf("\n��������Ҫִ�еĲ�����");
r:scanf_s("%d",&n);
printf("\n\n");
switch (n)
{
case 1:InitQueue(Q); 
      printf("\n���ѡ����������������1���˳�������0\n");
  scanf_s("%d",&x);
  if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
  else
      exit(-1);
      break;
case 2: printf("׼�����Զ��в���....\n\n");
CreatQueue(Q);//����ѭ������
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1); 
break;
case 3:ClearQueue(Q); 
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
 printf("\n���������ѡ��");
 goto r;
}
else
exit(-1); break;
case 4:DstoryQueue(Q); 
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1);
break;
case 5:if (QueueEmpty(Q) == 0)
printf("���в��գ�");
else
printf("����Ϊ�գ�\n"); 
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
   printf("\n���������ѡ��");
goto r;
}
else
exit(-1); break;
case 6:  printf("���г���Ϊ:%d", QueueLength(Q));//��ӳ�
printf("\n\n");
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1); break;
case 7:printf("��Ԫ��Ϊ��%d", GetHead(Q));//ȡ��Ԫ��
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1); break;
case 8:printf("������Ҫ��ӵ�Ԫ�أ�");
scanf_s("%d", &a);
printf("\n\n��Ҫ��ӵ�Ԫ��Ϊ��%d", EnQueue(Q, a)); 
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1); break;
case 9:printf("ɾ����ͷԪ�أ�%d", DeQueue(Q));//ɾ��
  printf("\n\n���ѡ����������������1���˳�������0\n");
  scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
}
else
exit(-1); break;
case 10:QueueTraver(Q);
printf("\n\n���ѡ����������������1���˳�������0\n");
scanf_s("%d", &x);
if (x = 1)
{
printf("\n���������ѡ��");
goto r;
} 
else
exit(-1); break;
default:printf("������������룡");
goto r; 
break;
}
return 0;
}

