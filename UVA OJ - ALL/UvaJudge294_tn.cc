#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define pb push_back
#define deb puts("PEIXE"),
#define file freopen("in","r",stdin)

typedef long long ll;
ll limite;
vector<ll> primes;
bitset<1234567> bs;


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
	
	//~ file;
	
	sieve();
	ll n;
	while(scanf(" %lld",&n),n){
		printf("%lld : %lld\n",n,numFP(n));
	}	
	return 0;
}
