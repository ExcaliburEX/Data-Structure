
#define OK 1
#define ERROR -1
#define OVERFLOW -1
typedef int QElemType;

typedef struct QNode *QNodePtr;

struct QNode{
    QElemType data;
    QNodePtr next;
};

typedef struct{
    QNodePtr front,rear;
}*LinkQueue;



int EnQueue(LinkQueue Q,QElemType e){
    QNodePtr q=(QNodePtr)malloc(sizeof(QNode));
    if(!q)exit(OVERFLOW);
    q->data=e;
    q->next=NULL;
    Q->rear->next=q;
    Q->rear=q;
    return OK;
}

int DeQueue(LinkQueue Q,QElemType e){
    QNodePtr q;
    if(Q->front==Q->rear)return ERROR;
    q=Q->front->next;
    e=q->data;
    Q->front->next=q->next;
    if(Q->rear==q)
        Q->rear=Q->front;
    free(q);
    return e;
}
