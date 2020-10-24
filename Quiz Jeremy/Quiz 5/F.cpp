#include <stdio.h>

int main(){
	long long int T, N, A[100000],index,selisih,faktorial,total;
	
	scanf("%lld", &T);
	
	for(int i=0;i<T;i++){
		total=0;
		scanf("%lld", &N);
		
		for(int k=0;k<100000;k++){
			A[k] = 0;
		}
		
		for(int j=0;j<N;j++){
			scanf("%lld", &index);
			A[index]++;
		}
		
		for(int l=0;l<100000;l++){
			if(A[l] >= 3){
				selisih = A[l]-3;
				faktorial = 1;
				
				for(int m=A[l];m>selisih;m--){
					faktorial *= m;
				}
				
				faktorial /= 6;
				
				total += faktorial;
			}
		}
		
		printf("Case #%d: %lld\n",i+1,total);
	}
	
    return 0;
}
    
