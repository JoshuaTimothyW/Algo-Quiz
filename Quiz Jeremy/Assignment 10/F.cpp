#include <stdio.h>
#include <string.h>
#define ll long long int

struct Book{
	ll user;
	ll id;
	char title[10];
	char author[10];
}list_book[50001];

void swap(struct Book *x,struct Book *y){ 
	struct Book temp = *x; 
	*x = *y; 
	*y = temp; 
}

void check(int index1, int index2){
	
	ll diff_id = list_book[index2].id - list_book[index1].id;
	ll diff_title = strcmp(list_book[index2].title,list_book[index1].title);
	ll diff_user = list_book[index2].user - list_book[index1].user;
	
	if( diff_id < 0 ){
		swap(&list_book[index1],&list_book[index2]);
		return;
	}
	else if( diff_id == 0 && diff_title < 0 ){
		swap(&list_book[index1],&list_book[index2]);
		return;
	}
	else if( diff_id+diff_title == 0 && diff_user < 0 ){
		swap(&list_book[index1],&list_book[index2]);
		return;
	}
}

void sort(ll n){ 
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			check(j,j+1); 	
		} 
	} 
}

void display(ll n){
	for(int i=0;i<n;i++){
		if( list_book[i].user == 2 ){
			printf("%d\n",i+1);	
		}
	} 
}

int main(){
	
	ll t,n,a,b;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&a); getchar();
		
		for(int j=0;j<a;j++){
			scanf("%lld %s %s",&list_book[j].id,&list_book[j].title,&list_book[j].author); getchar();
			list_book[j].user = 1;
		}
		
		scanf("%lld",&b); getchar();
		
		n=a+b;
		
		for(int j=a;j<n;j++){
			scanf("%lld %s %s",&list_book[j].id,&list_book[j].title,&list_book[j].author); getchar();
			list_book[j].user = 2;
		}
		
		sort(n);
		
		printf("Case #%d:\n",i);
		display(n);
	}
	
    return 0;
}
    
