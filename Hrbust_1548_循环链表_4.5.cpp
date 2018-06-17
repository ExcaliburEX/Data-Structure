/*#include<stdio.h>
int main()
{
    int n,m,i,t,u,a[10000];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        a[i]=i+1;
    for(u=0;u<n-1;u++){
        i=(i+m-1)%(n-u);
        for(t=i;t<n-u;t++)
        a[t]=a[t+1];
    }
    printf("%d\n",a[0]);
    return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    struct Node *next;
};
int main(){
    Node *head,*q,*p,*tail;
    int i;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    tail=head;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->num=i;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
   tail->next=head->next;

   for(i=1,p=head;;i++,head->next=p){
    if(n==1)break;
    if(i%m==0){
        q=p->next;
        p->next=q->next;
        free(q);
        n--;
    }
    else p=p->next;
   }

   printf("%d",p->num);
   return 0;
}
