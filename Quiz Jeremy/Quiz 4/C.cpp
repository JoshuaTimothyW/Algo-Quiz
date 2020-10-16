#include <stdio.h>

int main(){
	long long int N, A, B=0;
	scanf("%d", &N);
	
	for(int i=1; i<=N; i++){
		scanf("%d", &A);
		if (B >= A){
			printf("%d ", B);
		}
		B = A;
		
	}
	printf("%d\n", A);
	
    return 0;
}
    
