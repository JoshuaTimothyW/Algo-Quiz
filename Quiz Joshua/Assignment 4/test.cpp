#include <stdio.h>
#include <string.h>

char list[200][5];

void bublesort(char list[][5],int n) { 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(strcmp(list[j],list[j+1]) > 0){
				char temp[5];
				strcpy(temp,list[j+1]);
				strcpy(list[j+1],list[j]);
				strcpy(list[j],temp);
			}
		}
	}  
} 

int main(){
	
	char list_char[][5] = {"123","132","213","231","312","321"};
	int length = sizeof(list_char)/sizeof(list_char[0]);
	
	for(int i=0;i<length;i++){
		strcpy(list[i],list_char[i]);
	}	
	
	return 0;
}
