#include <stdio.h>

int main(){
	int t,n,arr[26],count;
	char s[100001];
	
	scanf("%d",&t); getchar();
	
	for(int a=1;a<=t;a++){
		count=0;
		n=0;
		while(s[n-1] != '\n'){
			scanf("%c",&s[n]);
			arr[s[n]-97]++;
			n++;
		}
		
		for(int i=0;i<26;i++){
			if(arr[i] > 0){
				count++;
				arr[i]=0;
			}
		}
		
		printf("Case #%d: %d\n",a,count);
	}
    return 0;
}
    
