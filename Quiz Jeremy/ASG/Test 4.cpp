#include <stdio.h>

int main(){
	
	char str[1000];
	int vocal, non,index,ascii[27];
	
	vocal = non = 0;
	
	scanf("%s",str);
	
	for(int i=0;i<27;i++){
		ascii[i] = 0;
	}
	
	for(int i=0;str[i]!=NULL;i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		}
		if(str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'e' || str[i] == 'o'){
			
			index = str[i]-'a';
			
			if( ascii[index] == 0 ){
				ascii[index] = 1;
				printf("%c",str[i]);
			}
			
			vocal++;
		}
	}
	printf(" ");
		
	for(int i=0;str[i]!=NULL;i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		}
		if(str[i] != 'a' && str[i] != 'i' && str[i] != 'u' && str[i] != 'e' && str[i] != 'o'){
			
			index = str[i]-'a';
			
			if( ascii[index] == 0 ){
				ascii[index] = 1;
				printf("%c",str[i]);
			}
			
			non++;
		}
		
	}
	printf(" ");
	printf("%d %d\n",vocal,non);
		
    return 0;
}
    
