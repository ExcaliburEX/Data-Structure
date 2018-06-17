//#include "Array.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct{
    int *array;
    int size;
}Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a,int index);
void array_set(Array *a,int index,int value);
int arrat_get(const Array *a,int index);
void array_inflate(Array *a,int more_size);
const int BLOCK_SIZE=20;

Array array_create(int init_size)
{
    Array a;
    a.size=init_size;
    a.array=(int*)malloc(sizeof(int)*init_size);
    return a;
}
void array_free(Array *a)
{
    free(a->array);
    a->array=NULL;
    a->size=0;

}
//封装
int array_size(const Array *a)
{
    return a->size;
}

int arrat_get(const Array *a,int index)
{
    return a->array[index];
}

void array_set(Array *a,int index,int value)
{
    a->array[index]=value;
}

int* array_at(Array *a,int index)
{
    if(index>=a->size){
        array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}
void array_inflate(Array *a,int more_size)
{
    int *p=(int*)malloc(sizeof(int)*(a->size+more_size));
    /*int i;
    for(i=0;i<a->size;i++){
        p[i]=a->array[i];
    }*/
    memcpy((void*)p,(void*)a->array,a->size*sizeof(int));
    free(a->array);
    a->array=p;
    a->size+=more_size;
}

int main()
{
    Array a=array_create(5);

    printf("Now the array size is:%d\n",array_size(&a));
    *array_at(&a,0)=10;
    printf("the %d element is %d:\n",0,*array_at(&a,0));
    int number;
    int cnt=0;
   printf("please input number,-1 to end:\n");
    while(number!=-1){
        scanf("%d",&number);
        if(number!=-1)
            *array_at(&a,cnt++)=number;
    }
     printf("Now the array size is:%d\n",array_size(&a));
      int i;
      for(i=0;i<a.size;i++){
        printf("%d ",a.array[i]);
      }
    array_free(&a);
    return 0;
}
