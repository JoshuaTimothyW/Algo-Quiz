#include <stdio.h>

int main(){
	
	char str[101],temp;
	int index,start,length,t;
	
	scanf("%d",&t); getchar();
	
	for(int num=1;num<=t;num++){
		scanf("%[^\n]",str); getchar();
		
		start = index = length = 0;
		
		for(int i=0;str[i] != NULL;i++){
			length++;
		}
		
		while(index <= length){
			if(str[index] != ' ' && str[index] != NULL){
				index++;
			}else{
				if(index-start >= 4){
					for(int i=start+1,j=index-2;i<j;i++,j--){
						temp = str[i];
						str[i] = str[j];
						str[j] = temp;
					}
				}
				index++;
				start = index;
			}
		}
		
		printf("Case #%d: %s\n",num,str);
	}
	
    return 0;
}
    
