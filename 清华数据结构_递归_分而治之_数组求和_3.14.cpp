

sum(int A[],int lo,int hi){ //���䷶ΧA[lo,hi]
	if(lo==hi)return A[lo];
	int mi = (lo + hi) >> 1;
	return sum(A, lo, mi) + sum(A, mi+1, hi); 
	
}//�����ʽΪsum(A, 0, n-1) 
