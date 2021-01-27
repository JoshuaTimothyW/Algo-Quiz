#include <stdio.h>

int main(){
	
	int n,arr[101];
	
	char str[101];
	
	scanf("%d",&n);
	
	scanf("%[^\n]",str);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("%c",str[arr[i]-1]);
	}
	printf("\n");
	
    return 0;
}
    
