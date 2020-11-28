#include <stdio.h>
#include <string.h>

int main(){
	
	int t, n;

	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
	
		char dst[1000],src[1000],temp[1000];
		
		scanf("%d %s %s",&n,src,dst); getchar();
		
		for(int j=2;j<=n;j++){
			strcpy(temp,dst);
			strcat(dst,src);
			strcpy(src,temp);
		}
		
		printf("Case #%d: %s\n",i,dst);
	}
	
    return 0;
}
    
