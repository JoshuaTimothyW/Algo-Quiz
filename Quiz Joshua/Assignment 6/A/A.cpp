#include <stdio.h>

long long arr[1100];
long long count=0, sum=0, min=1000001, max=0, range=0;
double mean;

void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		
		while(!feof(rd)){
			fscanf(rd,"%lld ",&arr[count]);
			
			
			if(arr[count] < min){
				min = arr[count];
			}
			
			if(arr[count] > max){
				max = arr[count];
			}
			
			sum += arr[count];
			count++;
			
		}
		
		mean = sum/(double)count;
		range = max-min;
	}
	
	fclose(rd);
	
}

void display(){
	printf("Count : %lld\n",count);
	printf("Sum   : %lld\n",sum);
	printf("Mean  : %.2lf\n",mean);
	printf("Min   : %lld\n",min);
	printf("Max   : %lld\n",max);
	printf("Range : %lld\n",range);
}

int main(){
	
	read();
	display();
	
	return 0;
}
