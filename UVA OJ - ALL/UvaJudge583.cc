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

bool ISPRIME(ll number){
	if(limite >= number) return bs[number];
	
	for(ll k = 0 ; primes[k]*primes[k] <= number ; ++k){
		if(number%primes[k] == 0) return false;
	} 
	return true;
}



vector<ll> fatora(ll number){
	
	vector<ll> fatoracao;
	if(number < 0)number *= -1,fatoracao.pb(-1);

	ll idx_fp = 0;
	ll FP = primes[idx_fp++]; // fator primo
		
	while(FP * FP <= number){
		while(number%FP == 0){ number /= FP;fatoracao.pb(FP);}
		FP = primes[idx_fp++];
	}
	if(number != 1) fatoracao.pb(number);
	return fatoracao;
}

int main(){
	
	sieve(1000000);
	
	ll N;
	while(scanf(" %lld",&N) == 1 && N){
		vector<ll> ans = fatora(N);
		vector<ll>::iterator it = ans.begin();
		printf("%lld = %lld",N,*it);
		
		for(it++ ; it != ans.end() ; ++it){
			printf(" x %lld",*it);
		}puts("");
	}	
	
	
}
