#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef struct Node *LL;
struct Node{
	int address;
	int data;
	int nextaddress;
	LL next;
};

int main(){
	LL L1,p1,q1;
	L1=(LL)malloc(sizeof(struct Node));
	L1->next=NULL;
	int firstaddress;
	int N,K;
	cin>>firstaddress>>N>>K;
	p1=L1;
	for(int i=0;i<N;i++){
		q1=(LL)malloc(sizeof(struct Node));

		cin>>q1->address>>q1->data>>q1->nextaddress;
		p1->next=q1;
		p1=q1;
	}
	p1->next=NULL;
    /* 以上步骤按照输入生成一个链表 */

	int findaddress=firstaddress;
	LL L2,p2;
	L2=(LL)malloc(sizeof(struct Node));
	L2->next=NULL;
	int count=0;
	p2=L2;
	while(findaddress!=-1){
		q1=L1;
		while(q1->next){ //只要q1->next存在就不断循环
		if(q1->next->address==findaddress){
			p2->next=q1->next;
			q1->next=q1->next->next;
			p2=p2->next;
			count++;
			findaddress=p2->nextaddress;
		}else{
			q1=q1->next;
		}
	}
	}
	p2->next=NULL;
    /* 将链表以地址进行排序 */

	LL L3,p3,q3,tail;
	L3=(LL)malloc(sizeof(struct Node));
	L3->next=NULL;
	int n=count;
	int k=K;
	p3=L3;
	p2=L2;
	while(n>=k){
		n-=k;
		for(int i=0;i<K;i++){
			p3->next=p2->next;
			p2->next=p2->next->next;//头插法插入，以k为单位
			if(!i)tail=p3->next;
			else p3->next->next=q3;
			q3=p3->next;
		}
		p3=tail;
	}
	p3->next=L2->next;//接上尾巴
	p3=L3->next;

	while(p3->next){
		printf("%05d %d %05d\n",p3->address,p3->data,p3->next->address);//不是nextaddress而是next->address
		p3=p3->next;
	}
	printf("%05d %d -1\n",p3->address,p3->data);

	return 0;
}
