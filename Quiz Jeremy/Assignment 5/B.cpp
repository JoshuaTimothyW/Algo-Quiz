#include <stdio.h>

int main(){
	long long int X, Y, M[101][101], T, a, b, c;
	scanf("%lld %lld", &X, &Y);
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			scanf("%lld", &M[i][j]);			
		}
	}
	
	scanf("%lld", &T);
	for(int k=0;k<T;k++){
		scanf("%lld %lld %lld", &a, &b, &c);
		M[a-1][b-1] = c;
	}
	
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(j == 0){
				printf("%lld", M[i][j]);
			}else{
				printf(" %lld", M[i][j]);
			}
		}
		printf("\n");
	}

    return 0;
}
    
