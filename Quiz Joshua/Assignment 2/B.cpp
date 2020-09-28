#include <stdio.h>

int main(){
	
	int T, N[10], max, count;
	char string[10][100000], curr;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		scanf("%s",string[i]);
	}
	
	for(int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		max = 0;
		count = 1;
		
		for(int j=0;j<N[i];j++){
			if(j < N[i]-1 && string[i][j] == string[i][j+1]){
				count++;
			}else{
				if(count > max){
					max = count;
					curr = string[i][j];
				}
				
				count = 1;
			}
		}
		
		printf("%c %d\n",curr,max);
	}
	
	return 0;
}
