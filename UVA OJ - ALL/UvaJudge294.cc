/*	ACHAR QUAL E O NUMERO EM UM DETERMINADO INTERVALO, QUE CONTEM O 
 * 	MAIOR NUMERO DE DIVISORES....
 * 
 * 	USAMOS A FUNCAO NUMDIV() -> COMPETITIVE PROGAMMING 3
 * 	
 * PASSANDO POR TODAS POSSIBILIDADES .. ISTO É, TODOS ELEMENTOS DO INTERVALO	
 */


#include <bits/stdc++.h>
using namespace std;
#define MAXN 33000
#define pb push_back
#define deb puts("PEIXE")

typedef long long ll;
ll limite;
vector<ll> primes;
bitset<34000> bs;


void sieve(ll LIM = MAXN){
	ll limite = LIM+1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i = 2 ; i <= limite ; ++i){
		if(bs[i]){
			for(ll j = i*i ; j <= limite ; j+= i) bs[j] = 0;
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
	int t;
	ll a,b;
	sieve();
	
	for(cin>>t;t--;){
		scanf(" %lld %lld",&a,&b);
		ll num = 0;
		ll numdiv = 0;
		for(ll i = a ; i <= b ; ++i){
			ll temp = numDIV(i);
			if(temp > numdiv){
				numdiv = temp;
				num = i;	
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num,numdiv);
	}
	return 0;
}
