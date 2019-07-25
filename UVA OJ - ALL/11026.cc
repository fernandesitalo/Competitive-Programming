#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Mod;
int N;

ll arr[1001];

ll pd[1001][10001];


ll F(int idx, int K){
	
	if(K == 0) return 1ll;
	if(idx == N) return 0ll;
	
	ll &ref = pd[idx][K];
	
	if(ref != -1) return ref;
		
	ref = ((arr[idx] * F(idx+1,K-1))%Mod + F(idx+1,K)%Mod)%Mod;// formar grupos com base nos menores já formados!
		
	return ref;	
}



int main(){
	
	//~ freopen("in","r",stdin);
	
	
	while(scanf(" %d %lld",&N,&Mod),N||Mod){
		
		ll ans = 1;
			
		for(int i = 0 ; i < N ; ++i) {
			scanf(" %lld",arr+i);
		}
		
		memset(pd,-1,sizeof pd);
			
		for(int i = 1 ; i <= N ; ++i){
			ans = max(ans,F(0,i));
		}

		printf("%lld\n",ans);
	}


	return 0;
}
