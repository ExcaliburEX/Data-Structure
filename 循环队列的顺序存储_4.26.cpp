#define MAXSIZE 100
#define OK 1
#define ERROR -1
typedef int QElemType;
struct SqQueue{
    QElemType data[MAXSIZE];
    int front;
    int rear;
};
typedef struct SqQueue *Queue;

int InitQueue(Queue Q){
    Q->front=0;
    Q->rear=0;
    return OK;
}

int QueueLength(Queue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(Queue Q,QElemType e){
    if((Q->rear+1)%MAXSIZE == Q->front)return ERROR;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}

int DeQueue(Queue Q,QElemType e){
    if(Q->front == Q->rear )return ERROR;
    e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return e;
}
