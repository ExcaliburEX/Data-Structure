#include<cstdio>
#include<cstdlib>
typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node * head;
    Node * tail;
}List;


void print(List *pList);
void add(List* pList,int number);


int main(){
    List list;
    list.head=list.tail=NULL;
    int number;
    printf("输入数字，-1结束：\n");
    do{
        scanf("%d",&number);
        if(number!=-1){
            add(&list,number);
        }
    }while(number!=-1);
    print(&list);
    printf("寻找：\n");
    scanf("%d",&number);
    Node *p;
    int isFound=0;
    for(p=list.head;p;p=p->next){
        if(p->value==number){
            printf("找到了\n");
            isFound=1;
            break;
        }
    }
    if(!isFound)printf("没找到\n");
    printf("删除：\n");
    Node *q;
    for(q=NULL,p=list.head;p;q=p,p=p->next){
        if(p->value==number){
            if(q){
                q->next=p->next;
            }else{
                list.head=p->next;
            }
            free(p);
            break;
        }
    }
     print(&list);
    for(p=list.head;p;p=q){
        q=p->next;
        free(p);
    }
        list.head=NULL;
     if(list.head)print(&list);
     else printf("链表已空！");
    return 0;
}

void add(List* pList,int number){
        Node *p=(Node*)malloc(sizeof(Node));
        p->value=number;
        p->next=NULL;
       /* Node* last=pList->head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            pList->head=p;
        }*/
        //一个头指针的情况
        if(pList->head==NULL){
            pList->head=p;
            pList->tail=p;
        }else{
            pList->tail->next=p;
            pList->tail=p;
        }
}

void print(List *pList)
{
    Node *p;
    for(p=pList->head;p;p=p->next)
        printf("%d ",p->value);
    printf("\n");
}
