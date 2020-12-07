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

int compare(int index1, int index2){
	
	int str = strcmp(list_book[index2].title,list_book[index1].title);
	
	if( list_book[index1].id != list_book[index2].id ){
    	return list_book[index1].id < list_book[index2].id;
	}
	
	if( str != 0 ){
		return str;
	}
	
	return list_book[index1].user < list_book[index2].user;
}

int check (int start, int end) 
{ 
    int i = (start - 1);
  
    for (int j = start; j <= end- 1; j++) 
    {         
       if( compare(j,end) > 0 ){
       	i++;
		swap(&list_book[i],&list_book[j]);
	   }
    }
	 
    swap(&list_book[i + 1], &list_book[end]); 
    
	return (i + 1); 
} 
  
void order_book(int start, int end) 
{ 
    if (start < end) 
    { 
        int pi = check(start, end); 
  
        order_book(start, pi - 1); 
        order_book(pi + 1, end); 
    } 
} 


void display(ll n){
	for(int i=0;i<n;i++){
		printf("%d %s %d\n",list_book[i].id,list_book[i].title,list_book[i].user);
	} 
}

int main(){
	
	ll t,n,a,b;
	
	scanf("%lld",&t); getchar();
	
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
		
		printf("Case #%d:\n",i);
		order_book(0,n-1);
		
		for(int j=0;j<n;j++){
			if( list_book[j].user == 2 ){
				printf("%d\n",j+1);	
			}	
		} 
	}
	
    return 0;
}
    
