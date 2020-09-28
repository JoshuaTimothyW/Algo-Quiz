#include <stdio.h>
#define get getchar();

unsigned long long total_h, total_w, count_w,count_h;

struct Food{
	unsigned long long weight;
	unsigned long long happy;
}food[20];

void swap(struct Food *x,struct Food *y){ 
	struct Food temp = *x; 
	*x = *y; 
	*y = temp; 
}

void quick_sort(struct Food arr[],unsigned long long l,unsigned long long r) 
{ 
	unsigned long long j,k; 
	if(l < r){
		j = l;
		k = r + 1;
		do{ 
			do{ j=j+1; } while(arr[j].weight < arr[l].weight); 
			do{ k=k-1; } while(arr[k].weight > arr[l].weight); 
			if(j < k) swap(&arr[j],&arr[k]); 
		}while(j <= k); 
		
		swap(&arr[l],&arr[k]); 
		quick_sort(arr,l,k-1); 
		quick_sort(arr,k+1,r); 
	}
}

int main(){
	
	unsigned long long M, T,N;
	
	scanf("%llu",&T); get
	
	for(int i=0;i<T;i++){
		scanf("%llu %llu",&N,&M); get
		
		total_h = total_w = count_h = count_w = 0;
		
		for(int j=0;j<N;j++){
			scanf("%llu %llu",&food[j].happy,&food[j].weight); get
			total_h += food[j].happy;
			total_w += food[j].weight;
		}
		
		printf("Case #%d: ",(i+1));
		
		if(total_h < M){
			printf("Impossible\n");
		}else if(total_h == M){
			printf("%llu\n",total_w);
		}else{
			quick_sort(food,0,N-1);
			
			for(int j=0;count_h < M;j++){
				count_h += food[j].happy;
				count_w += food[j].weight;
			}
			
			printf("%llu\n",count_w);
		}
		
	}
	
	return 0;
}
