#include <stdio.h>

int main(){
	
	int T, N;
	int A[101][101];
	int row[101], col[101];
	
	scanf("%d", &T); 
	
	for(int a=0; a<T; a++){
		scanf("%d", &N);
		
		for(int i=0;i<N;i++){
			row[i] = -127;
			col[i] = -127;
		}
		
		for(int i=0; i<N;i++){
			for(int j=0; j<N; j++){
				scanf("%d", &A[i][j]);
				getchar();
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(row[i]<A[i][j]) row[i] = A[i][j];
				if(col[i]<A[j][i]) col[i] = A[j][i];
			}
		}
		
		printf("Case #%d:\n", a+1);
		printf("Row :");
		for(int i=0; i<N; i++){
			printf(" %d", row[i]);
		}
		printf("\nCol :");
		for(int i=0; i<N;i++){
			printf(" %d", col[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}
