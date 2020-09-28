#include <stdio.h>
#define get getchar();

long long total_happy, total_weight, count_weight,count_happy;

struct Food{
	long long weight;
	long long happy;
}food[20];

void swap(struct Food *x,struct Food *y){ 
	struct Food temp = *x; 
	*x = *y; 
	*y = temp; 
}

void quick_sort(struct Food arr[],long long l,long long r) 
{ 
	long long j,k; 
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
	
	long long M, T,N;
	
	scanf("%lld",&T); get
	
	for(int i=0;i<T;i++){
		scanf("%lld %lld",&N,&M); get
		
		total_happy = total_weight = count_happy = count_weight = 0;
		
		for(int j=0;j<N;j++){
			scanf("%lld %lld",&food[j].happy,&food[j].weight); get
			total_happy += food[j].happy;
			total_weight += food[j].weight;
		}
		
		printf("Case #%d: ",(i+1));
		
		if(total_happy < M){
			printf("Impossible\n");
		}else if(total_happy == M){
			printf("%lld\n",total_weight);
		}else{
			quick_sort(food,0,N-1);
			
			for(int j=0;count_happy < M;j++){
				count_happy += food[j].happy;
				count_weight += food[j].weight;
			}
			
			printf("%lld\n",count_weight);
		}
		
	}
	
	return 0;
}
