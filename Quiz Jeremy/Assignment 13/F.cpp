#include <stdio.h>
#define MAX 5050

int arr[MAX+1];

void fill_prime(){
	
	arr[0] = 2;
	
	int j=3,index=1,c;

    for(int i=2; i <= MAX; j++)  
    {
        for(c = 2; c < j; c++)
        {
            if(j%c == 0) break;
        }

        if(c == j)
        {
			arr[index] = j%10;
			index++;
            i++;
        }

    }
}

void display(int n){
	
	int index=0,j;
	
	for(int i=1;i<=n;i++){
		for(j=0;j<i;j++){
			printf("%d",arr[index]);
			index++;
		}
		printf("\n");	
	}
}

int main(){

	int t,n;

	fill_prime();
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		printf("Case #%d:\n",i);
		display(n);
	}
	
    return 0;
}
    
