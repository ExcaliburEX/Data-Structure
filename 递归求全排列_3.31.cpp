
/*
#include <stdio.h>


递归(分治法思想):
设(ri)perm(X)表示每一个全排列前加上前缀ri得到的排列.
当n=1时,perm(R)=(r) 其中r是唯一的元素,这个就是出口条件.
当n>1时,perm(R)由(r1)perm(R1),(r2)perm(R2),...(rn)perm(Rn)构成.

//此处为引用,交换函数.函数调用多,故定义为内联函数.
inline void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void Perm(int list[],int k,int m) //k表示前缀的位置,m是要排列的数目.
{
	if(k==m-1) //前缀是最后一个位置,此时打印排列数.
	{
		for(int i=0;i<m;i++)
			printf("%d ",list[i]);
		printf("\n");
	}
	else
	{
		for(int i=k;i<m;i++)
		{
			//交换前缀,使之产生下一个前缀.
			Swap(list[k],list[i]);//Ａ
			Perm(list,k+1,m);//Ｂ
			//将前缀换回来,继续做上一个的前缀排列.
			Swap(list[k],list[i]);//Ｃ
		}
	}
}

int main()
{
	int list[] = {1,2,3,4};
	Perm(list,0,4);
	return 0;
}*/
#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
    int ans[4]={1,2,3,4};  
    sort(ans,ans+4);    /* 这个sort可以不用，因为{1，2，3，4}已经排好序*/  
    do                             /*注意这步，如果是while循环，则需要提前输出*/  
    {  
        for(int i=0;i<4;++i)  
            cout<<ans[i]<<" ";  
        cout<<endl;  
    }while(next_permutation(ans,ans+4));  
    return 0;  
} 

