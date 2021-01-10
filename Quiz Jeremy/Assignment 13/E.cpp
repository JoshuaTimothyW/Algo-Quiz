#include <stdio.h>
#define ll long long int

ll result,a[1001],b[1001],c[1001];
ll na,nb,nc,maxa,maxb,maxc;

ll calculate(){
	
	ll count=0;
	
	if( maxa+maxb+maxc < result ){
		return 0;
	}
	
	for(int i=0;i<na;i++){
		for(int j=0;j<nb;j++){
			for(int k=0;k<nc;k++){
				if( a[i]+b[j]+c[k] == result ){
					count++;
				}
			}	
		}	
	}
	
	return count;
}

int main(){
	
	int t;

	scanf("%d",&t);

	for(int j=1;j<=t;j++){
		maxa = maxb = maxc = 0;
		
		scanf("%lld",&na);
				
		for(int i=0;i<na;i++){
			scanf("%lld",&a[i]);
			if(a[i] > maxa){
				maxa = a[i];
			}
		}
		
		scanf("%lld",&nb);
				
		for(int i=0;i<nb;i++){
			scanf("%lld",&b[i]);
			if(b[i] > maxb){
				maxb = b[i];
			}
		}
		
		scanf("%lld",&nc);
				
		for(int i=0;i<nc;i++){
			scanf("%lld",&c[i]);
			if(c[i] > maxc){
				maxc = c[i];
			}
		}
		
		scanf("%lld",&result);
		
		printf("Case #%d: %lld\n",j,calculate());
	}
	

    return 0;
}
    
