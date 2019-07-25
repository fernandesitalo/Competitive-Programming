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
	
	freopen("out","w",stdout);
	
	long long vet[500];
	
	
	while(scanf("%lld",&vet[0])!= EOF){
		
		int n = 1;
		while(scanf("%lld",&vet[n]),vet[n++]!= -999999);
		
		n--;
		
		long long ans = -9999999;
		long long pro;
		
		for(int i = 0 ; i < n ; ++i){
			pro = 1;
			
			for(int j = i ; j < n ; ++j){
				pro *= vet[j];
				ans = max(pro,ans);
			}		
		}
		
		printf("%lld\n",ans);	
	
	}
	
	
	


	return 0;
}
