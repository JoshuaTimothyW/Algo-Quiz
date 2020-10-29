#include <stdio.h>

int main(){
	long long int N, total=1;
	scanf("%lld", &N);
	for(int i=1;i<=N;i++){
		total*=2;
	}
	total-=1;
	printf("%lld\n", total);
    return 0;
}
    
