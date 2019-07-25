#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
#define pb push_back
#define deb puts("PEIXE")

typedef long long ll;
ll limite;
vector<ll> primes;
bitset<1000090> bs;


void sieve(ll LIM = MAXN){
	ll limite = LIM+1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i = 2 ; i < limite ; ++i){
		if(bs[i]){
			for(ll j = i*i ; j < limite ; j+= i) bs[j] = 0;
			primes.pb(i);
		}
	}
}


ll numFP(ll N){
	
	ll idx = 1; // index do fator primo
	ll FP = primes[0];
	ll ans = 0;
	
	bool alface;
	
	while(FP * FP <= N){
		alface = false;
		while(N%FP == 0){N /= FP; alface = true;}
		if(alface) ans++;
		FP = primes[idx++];
	}
	if(N != 1) ans++;
	return ans;
}


int main(){
	
	sieve();
	ll n;
	while(scanf(" %lld",&n),n){
		printf("%lld : %lld\n",n,numFP(n));
	}	
	return 0;
}
