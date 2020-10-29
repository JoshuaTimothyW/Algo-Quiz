#include <stdio.h>

int main(){
	long long int T, N, index;
	scanf("%lld", &T);
	for(int a=0;a<T;a++){
		scanf("%lld", &N);
			index = N-1;
			printf("Case #%lld:\n", a+1);
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if( j<index ){
						printf(" ");
					}
					else{
						if((i+j)%2 == 1){
							printf("#");
						}
						else{
							printf("*");
						}
					}
				}
				index--;
				printf("\n");
			}
	}

    return 0;
}
    
