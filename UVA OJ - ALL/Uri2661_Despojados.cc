#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb puts("PEIXE")

typedef long long ll;
ll limite;
vector<ll> primes;
bitset<1000100> bs;


void sieve(ll LIM ){
	limite = LIM+1;
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i = 2 ; i <= limite ; ++i){
		if(bs[i]){
			for(ll j = i*i ; j <= limite ; j+= i) bs[j] = 0;
			primes.pb(i);
		}	
	}
}

bool isprime(ll N){
	
	if(limite >= N) return bs[N];
	
	for(int i = 0 ; N >= primes[i]*primes[i] ; ++i){
		if(N%primes[i] == 0) return false;
	}
	return true;
}


ll EhDespojado(ll N){

	if(isprime(N)) return 0ll;

	ll qtdprimes = 0ll;
	ll idx = 1; // index do fator primo
	ll FP = primes[0];
	
	while(FP * FP <= N){		
		
		if(N%FP == 0){ N /= FP;
			
			if(N%FP == 0) return 0ll;
			qtdprimes++;
		}
		FP = primes[idx++];	
	}
	
	if(N != 1) qtdprimes++;
	
	if(qtdprimes <= 1) return 0ll ;
	
	return 1ll;
}




int main(){
		
	//~ freopen("in","r",stdin);
	
	sieve(1000010ll);

	ll n;
	
	while(scanf(" %lld",&n) == 1){
		ll ans = 0ll;
		
		if(!isprime(n)){
			
			for(ll i = 1 ; n >= i*i ; ++i){
				if(n%i == 0) {
					ans += EhDespojado(i);
					if(i != n/i ) ans += EhDespojado(n/i);
				}
			}
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
