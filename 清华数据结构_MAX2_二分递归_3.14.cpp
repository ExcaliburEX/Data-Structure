//求最大值与次大值 

void max2(int A[],int lo,int hi,int &x1,int &x2){
	if(lo+2==hi){
		if(A[lo]>A[lo+1])
			if(A[lo+1]>A[hi])
		return ;
	}// T(2)=1
	if(lo+3==hi){
		/*...*/
		return ;
	}//T(3)<=3
	int mi=(lo+hi)/2;//divide
	int x1L,x2L;
	max2(A,lo,mi,x1L,x2L);
	int x1R,x2R;
	max2(A,mi,hi,x1R,x2R);
	if(A[x1L]>A[x1R]){
		x1=x1L;
		x2=(A[x2L]>A[x1R])?x2L:x1R;
	}else{
		x1=x1R;
		x2=(A[x1L]>A[x2R])?x1L:x2R;
	}//1 + 1=2
}//T(n)=2*T(n/2)+2<=5n/3-2
