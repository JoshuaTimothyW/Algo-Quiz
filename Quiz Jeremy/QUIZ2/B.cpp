#include <stdio.h>

int n,m;

int node[102];

void reset(){
	for(int i=0;i<100;i++){
		node[i] = 0;
	}
}

void push_node(int src, int dst){
	node[src]++;
	node[dst]++;
}

int check_star(){
	int count=0,central=0,regular=0;
	
	if(m != (n-1)){
		return 0;
	}
	
	if(n == 1){
		return 1;
	}
	
	for(int i=1;i<=n;i++){
		if(node[i] == n-1){
			count++;
			central = i;
		}
		else{
			regular++;
		}
	}
	
	if(count != 1){
		return 0;
	}
	
	if(regular != m){
		return 0;
	}
	
	return 1;
}

int main(){
	
	int src,dst;
	
	reset();
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&src,&dst);
		push_node(src,dst); 
	}
	
	if(check_star()){
		printf("YES");
	}
	else{
		printf("NO");
	}
	printf("\n");
	
	return 0;
}
