#include<bits/stdc++.h>
#define MAXN 10000010
using namespace std;


bitset<MAXN> bs;
vector<int> primes;
typedef long long ll;

ll tamMax;


void gera(ll limite){
	tamMax = limite + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i = 2; i <= tamMax ; ++i){
		if(bs[i]){
			for(ll j = i*i ; j <= tamMax ; j += i) bs[j] = 0;			
			primes.push_back((int)i);
		}
	}	
}

bool ISPRIME(int n){
	if(tamMax >= n) return bs[n];
	
	ll raiz = sqrt(n);
	
	for(int i = 0 ; primes[i] <= raiz ; ++i){ //  ir so ate a raiz de n.....
		if(n%primes[i] == 0) return false;
	}
	return true;
}

ll m;



int main(){
	
	freopen("in_","r",stdin);
	//freopen("out_","w",stdout);
	
	
	gera( 1000000 );
	
	ll n;
	
	while(scanf(" %lld %lld",&n,&m) != EOF){
		
		ll c1,c2;
		ll d1,d2;
		
		ll menor = 9999999;
		ll maior =-1000000;
		
		vector<ll> v;
		
		for(ll i = n ; m >= i ; ++i){
			if(ISPRIME(i)){
				v.push_back(i);
			}
		}
		
		ll diff = 0;		
		for(int i = 1 ; i < (int)v.size() ; ++i){
			diff = v[i] - v[i-1];
			if(diff > maior) maior = diff,d1 = v[i-1],d2 = v[i];
			if(diff < menor) menor = diff,c1 = v[i-1],c2 = v[i];
		}
		
		if(v.size() <= 1) puts("There are no adjacent primes.");
		else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",c1,c2,d1,d2);	
	}
	
	return 0;
}
