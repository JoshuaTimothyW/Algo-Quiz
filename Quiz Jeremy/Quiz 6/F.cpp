#include <stdio.h>

int main(){
	unsigned long long int M, N, total_kolom = 0, total=1;
	
	scanf("%llu %llu", &M, &N);
	
	unsigned long long int T[M][N];
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%llu", &T[i][j]);
		}
	}
	
	for(int i=0;i<N;i++){
		total_kolom = 0;
		for(int j=0;j<M;j++){
			total_kolom =  ( total_kolom+T[j][i] )%1000000007;
		}
		
		total = ( total*total_kolom )%1000000007;
	}
	
	printf("%llu\n", total);

    return 0;
}
    
