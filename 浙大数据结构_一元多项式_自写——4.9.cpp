#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct polynode *polynomial;
struct polynode{
    int coef;
    int expon;
    polynomial next;
};
polynomial readpoly();
void Attach(int c,int e,polynomial *pRear);
polynomial add(polynomial p1,polynomial p2);
polynomial mult(polynomial p1,polynomial p2);
void print(polynomial p);


int main(){
    polynomial p1,p2,pp,ps;
    p1=readpoly();
    p2=readpoly();

    ps=mult(p1,p2);
    print(ps);
    pp=add(p1,p2);
    print(pp);
    return 0;
}

polynomial readpoly(){
    polynomial rear,p,t;
    int c,e;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->next=NULL;
    rear=p;
    int N;
    cin>>N;
    while(N--){
        cin>>c>>e;
        Attach(c,e,&rear);
    }
    t=p;
    p=p->next;
    free(t);
    return p;
}

void Attach(int c,int e,polynomial *pRear){
    polynomial p;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->coef=c;
    p->expon=e;
    p->next=NULL;
    (*pRear)->next=p;
    *pRear=p;
}

polynomial mult(polynomial p1,polynomial p2){
    polynomial t1,t2,rear,p,t3;

    int c,e;
    if(!p1||!p2)return NULL;
     t1=p1,t2=p2;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->next=NULL;
    rear=p;
    while(t2){
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&rear);
        t2=t2->next;
    }
    t1=t1->next;
    while(t1){
        t2=p2;
        rear=p;
        while(t2){
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while(rear->next&&rear->next->expon>e)
                rear=rear->next;
            if(rear->next&&rear->next->expon==e){
                if(rear->next->coef+c){
                    rear->next->coef+=c;
                }else{
                    t3=rear->next;
                    rear->next=t3->next;
                    free(t3);
                }
            }else{
                t3=(polynomial)malloc(sizeof(struct polynode));
                t3->coef=c;
                t3->expon=e;
                t3->next=rear->next;
                rear->next=t3;
                rear=rear->next;

            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    t3=p;
    p=p->next;
    free(t3);
    return p;
}

polynomial add(polynomial p1,polynomial p2){
    polynomial p,rear,t1,t2,t3;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->next=NULL;
    rear=p;
    t1=p1,t2=p2;
    while(t1&&t2){
        if(t1->expon==t2->expon){
            if(t1->coef+t2->coef){
                Attach(t1->coef+t2->coef,t1->expon,&rear);
            }
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->expon>t2->expon){
            Attach(t1->coef,t1->expon,&rear);
            t1=t1->next;
        }
        else{
            Attach(t2->coef,t2->expon,&rear);
            t2=t2->next;
        }

    }

    while(t1){
        Attach(t1->coef,t1->expon,&rear);
        t1=t1->next;
    }
    while(t2){
        Attach(t2->coef,t2->expon,&rear);
        t2=t2->next;
    }
    t3=p;
    p=p->next;
    return p;
}


void print(polynomial p){
    int flag=0;
    if(!p){
        cout<<"0 0"<<endl;
        return;
    }


    while(p){
        if(!flag)flag=1;
        else cout<<" ";
        cout<<p->coef<<" "<<p->expon;
        p=p->next;
    }
    cout<<endl;
}
