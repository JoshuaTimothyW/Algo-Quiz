#include <stdio.h>

int awal,n;

int fib(int x,int loop){
	if(loop == n) return x;
	if(x <= 100) return fib(x+3,loop+1);
	if(x > 100) return fib(x-2,loop+1);
}

int main(){
	scanf("%d",&awal);
	scanf("%d",&n);
	printf("%d\n",fib(awal,1));
	
	
	return 0;
}
