#include <bits/stdc++.h>
using namespace std;



typedef long long ll;
#define pb push_back
vector<ll> primes;
bitset<10000010> bs;
ll limite;

void sieve(ll lim){
	limite = lim+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2 ; i <= limite ;++i){
		if(bs[i]){
			for(ll j = i*i ; j <= limite ; j+=i) bs[j] = 0;
			primes.pb(i);
		}
	}
}

// modificado
ll fatora(ll number){
	
	ll maiorFP = -1;
	
	set<ll> s;

	ll idx_fp = 0;
	ll FP = primes[idx_fp++]; // fator primo
		
	while(FP * FP <= number){
		while(number%FP == 0){ number /= FP;maiorFP = FP;s.insert(FP);}
		FP = primes[idx_fp++];
	}
	
	if(number != 1) maiorFP = max(maiorFP,number),s.insert(number);
	
	if(s.size() == 1) return -1;
	
	return maiorFP;
}




int main(){
	
	
	  freopen("in","r",stdin);
	  //~ freopen("out","w",stdout);
	sieve(10000110);
	ll N;
	while(scanf(" %lld",&N)== 1 && N){
		if(N < 0) N *= -1;
		ll ans = fatora(N);
		printf("%lld\n",ans);
	}

	return 0;
}
