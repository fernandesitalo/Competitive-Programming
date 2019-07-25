#include <bits/stdc++.h>
using namespace std;
#define MAXN 70000
#define pb push_back
#define deb puts("PEIXE")

typedef long long ll;
ll limite;
vector<ll> primes;
bitset<70080> bs;


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


ll numDIV(ll N){
	
	ll idx = 1; // index do fator primo
	ll FP = primes[0];
	ll ans = 1;
	
	while(FP * FP <= N){
		ll power = 0;
		while(N%FP == 0){N /= FP; power++;}
		ans *= (power+1);
		FP = primes[idx++];
		//~ deb;
	}
	if(N != 1) ans *= 2;
	return ans;
}




int main(){

	sieve(MAXN);
	ll n;
	while(scanf(" %lld",&n) && n){
		ll ans = numDIV(n);
		if(ans%2 == 0)puts("no");
		else puts("yes");
	}
	return 0;
}
