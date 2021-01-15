#include <stdio.h>

int recursion(int x){
	if(x == 0){
		return 0;
	}
	
	return recursion(x-1)+1;
}

int main(){
	
	int n;
	
	scanf("%d",&n);
	printf("%d\n",recursion(n));
	
    return 0;
}
    
