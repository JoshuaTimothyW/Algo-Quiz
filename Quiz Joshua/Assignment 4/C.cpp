#include <stdio.h> 
#include <string.h> 
  
char list[7000][10];
int count=0;
  
void swap(char* x, char* y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void bublesort(char list[][10],int n) { 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(strcmp(list[j],list[j+1]) > 0){
				char temp[10];
				strcpy(temp,list[j+1]);
				strcpy(list[j+1],list[j]);
				strcpy(list[j],temp);
			}
		}
	}  
} 

void display(){
	for(int i=0;i<count;i++){
		printf("%s\n",list[i]);
	}
} 
  
void permute(char* a, int l, int r) 
{ 
    if (l == r) {
    	strcpy(list[count],a); 
    	count++;
    }else { 
        for (int i = l; i <= r; i++) { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r); 
            swap((a + l), (a + i));
        } 
    } 
} 
  
int main() 
{ 
    char digit[]="1234567";
	int T, N[11];
	char str[10];
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		count=0;		
		printf("Case #%d:\n",(i+1));

		if(N[i] >= 1 && N[i] <= 7){
			for(int j=0;j<N[i];j++){
				str[j] = digit[j];
			};
			
	
		    permute(str, 0, N[i]-1);
		    bublesort(list,count);
			display();			
		}
	
	};
	
	
    return 0; 
} 

