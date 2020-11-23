#include <stdio.h>
#include <string.h>

int is_sub(char s[21], char k[9], int i, int j){
	
	if( (i==0 && j==0) || j==0 ){
		return 1;
	}
	
	if(i == 0){
		return 0;
	}
	
	if( s[i-1] == k[j-1] ){
		return is_sub(s,k,i-1,j-1) + is_sub(s,k,i-1,j);
	}else{
		return is_sub(s,k,i-1,j);
	}
}

int main(){
	
	int t;
	char s[21], k[9];
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%s",s);
		scanf("%s",k);
		
		printf("Case #%d: %d\n",i,is_sub(s,k,strlen(s),strlen(k)));
	}
	
    return 0;
}
    
