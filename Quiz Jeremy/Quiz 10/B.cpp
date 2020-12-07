#include <stdio.h>
#define ll long long int

struct Customer{
	char name[101];
	ll date;
	ll month;
	ll total_buy;
}list_customer[1001];

int main(){
	
	ll t,n,m,q;
	ll date,month,count;
	
	scanf("%lld",&t);
	for(ll i=1;i<=t;i++){
		
		scanf("%lld %lld",&n,&m);
		
		for(ll j=0;j<n;j++){
			scanf("%s %02lld/%02lld %lld"
			,&list_customer[j].name
			,&list_customer[j].date
			,&list_customer[j].month
			,&list_customer[j].total_buy);
		}
		
		printf("Case #%lld:\n",i);

		scanf("%lld",&q);
		
		for(ll j=0;j<q;j++){
			scanf("%02lld/%02lld",&date,&month);
			count=0;
			
			for(int k=0;k<n;k++){
				if( list_customer[k].date == date && list_customer[k].month == month && list_customer[k].total_buy >= m ){
					printf("%s\n",list_customer[k].name);
					count++;
				}
			}
			
			if(count < 1){
				printf("No one\n");
			}
		}
	}
	
    return 0;
}
    
