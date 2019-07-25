#include <bits/stdc++.h>
using namespace std;



typedef long long ll;
#define pb push_back
vector<ll> primes;
bitset<10000110> bs;
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
	//~ printf(">>>>>> %lld\n",primes.back());
}


// modificado
void fatora(ll number){

	ll idx_fp = 0;
	ll FP = primes[idx_fp++]; // fator primo
		
	while(FP * FP <= number){
		while(number%FP == 0){ number /= FP;printf("    %lld\n",FP);}
		FP = primes[idx_fp++];
	}
	
	if(number != 1) printf("    %lld\n",number);
}




int main(){
	
	
	  //~ freopen("in","r",stdin);
	  //~ freopen("out","w",stdout);
	sieve(10000000);
	ll N;
	while(scanf(" %lld",&N)== 1 && N > 0){
		fatora(N);
		puts("");
	}

	return 0;
}
