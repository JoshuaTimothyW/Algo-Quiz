#include <stdio.h>

int main(){
	long long int T, X, A[100][100], V[100];
	scanf("%lld", &T);
	
	for(int i=1;i<=T;i++){
		
		scanf("%lld", &X);
		
		for(int j=0;j<X;j++){
			
			for(int k=0;k<X;k++){
		
				scanf("%lld", &A[k][j]);				
				
				V[k] += A[k][j];	
			}			
		}
		
		printf("Case #%lld:",i);
		for(int j=0;j<X;j++){
			printf(" %lld",V[j]);
			V[j] = 0;
		}
		printf("\n");
	}
    return 0;
}
    
