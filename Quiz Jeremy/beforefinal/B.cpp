#include <stdio.h>
#include <string.h>

struct Gift{
	char item[101];
}arr[1002];

int main(){
	
	int n,index;
	char str[101];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%s %d",str,&index);
		strcpy(arr[index].item,str);
	};
	
	for(int i=1;i<=n;i++){
		printf("Lecturer #%d: %s\n",i,arr[i].item);
	};
	
    return 0;
}
    
