/*			USAR BIG INT....
 * 
 * 			MESMO CODIGO SO QUE COM BIG INT....
 * 
 * 
 * 
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	
	freopen("in","r",stdin);
	
	//freopen("out","w",stdout);
	
	int q;
	long long a,b,c;
	
	scanf("%d",&q);
	
	
	while(q--){
		
		
		scanf("%lld%lld%lld",&a,&b,&c);
		a *= (b*c);
		long long vet[a];
		
		for(int i = 0 ; i < a ; ++i ){
			scanf("%lld",&vet[i]);
		}
		
		long long ans = -9999999;
		long long pro;
		
		for(int i = 0 ; i < a ; ++i){
			pro = 1;
			
			for(int j = i ; j < a ; ++j){
				pro *= vet[j];
				ans = max(pro,ans);
			}		
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
