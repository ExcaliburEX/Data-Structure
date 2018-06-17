# include <stdio.h>  
# define F 50  
int main(void)  
{  
	int cnt=0;
    unsigned long long int fib[1000];  
    int f = 0;  
    int a[101];  
    fib[0] = 0;  
    fib[1] = 1;  
    for(int i = 2; fib[i] < 1e18; i++) {  
        fib[i] = fib[i - 1] + fib[i - 2];  
        f++;  
    }  
    printf("%d\n", f);  
    unsigned long long int x = fib[F - 2];  
    unsigned long long int y = fib[F - 1];  
    for(int i = 0; i < 101; i++) {  
        a[i] = x / y;  
        x = (x % y) * 10;  
        printf("%d", a[i]);  
        if(i==0)printf(".");
        cnt++;
    }  
    printf("\n%d",cnt);
}  
