#include <stdio.h>

int main(){
	long long int N, K, T, A, tgl, bln,year;
	char B[101][101];	

	scanf("%lld %lld", &N, &K);
	
	for(int j=0;j<N;j++){
		scanf("%s", &B[j]); getchar();
	}
	
	scanf("%lld", &T);
	
	for(int j=0;j<T;j++){
		scanf("%lld", &A);
		
		tgl = bln = 0;
		year = N*K;
		
		if(A > year){
			A %= year;
			
			if(A == 0){
				A += year;					
			}
		}
		
		tgl = A%K;
		bln = A/K;
		
		if(tgl == 0){
			bln--;
			tgl = K;
		}
		
		printf("Case #%d: %s %lld\n",j+1,B[bln],tgl);			
	}
	
	return 0;	
}
