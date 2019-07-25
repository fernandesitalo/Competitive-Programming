#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
ll limite;
vector<ll> primes;
bitset<1000010000> bs;


void sieve(int LIM){
	limite = LIM+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2 ; i <= limite ; ++i){
		if(bs[i]){
			primes.pb(i);
			for(ll j = i*i ; j <= limite ; j+=i) bs[j] = 0;
		}
	}
}


ll numDiv(ll N){
	ll idx = 0;
	ll FP = primes[idx];
	ll ans = 1;
	
	while(FP*FP <= N){
		ll power = 0;
		while(N%FP == 0) N /= FP,power++;
		ans *= (power+1);
		FP = primes[++idx];
	}
	if(N != 1) ans *= 2;
	return ans;
}




ll EP(ll N){
	
	ll idx = 0;
	ll FP = primes[idx];
	ll ans = N;
	
	while(FP * FP <= N)
	{
		if(N%FP == 0) ans -= ans/FP;
		while(N%FP == 0) N /= FP; 
		FP = primes[++idx];
	} 
	
	if(N != 1) ans -= ans/N;
	return ans;
}

int main(){
	
	sieve(100000ll);
	ll n;
	
	while(cin>>n,n){
		cout << EP(n) << endl;
	}
	
	return 0;
}
