#include<bits/stdc++.h>
#define MAXN 20000010
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
	for(int i = 0 ; primes[i] <= raiz ; ++i)
		if(n%primes[i] == 0) return false;
	return true;
}



typedef pair<ll,ll> ii;

int main(){
	
	ll M = 20000000;
	
	gera(M);
	
	vector<ii> v;
	

	for(register ll i = 3 ; (int)v.size() < 100000 ; ++i){
		if(ISPRIME(i) && ISPRIME(i+2)){
				v.push_back(ii(i,i+2));
		}
	}
	
	
	
	int n;
	while(scanf(" %d",&n) == 1){
		printf("(%lld, %lld)\n",v[n-1].first,v[n-1].second);
	}
	
	
	
	
	
	
	
	
	return 0;
}
