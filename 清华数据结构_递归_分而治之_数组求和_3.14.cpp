

sum(int A[],int lo,int hi){ //区间范围A[lo,hi]
	if(lo==hi)return A[lo];
	int mi = (lo + hi) >> 1;
	return sum(A, lo, mi) + sum(A, mi+1, hi); 
	
}//入口形式为sum(A, 0, n-1) 
