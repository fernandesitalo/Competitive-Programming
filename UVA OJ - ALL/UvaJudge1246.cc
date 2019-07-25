#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back


bitset<10099> bs;
ll Limite;
vector<ll> primes;


void sieve(ll Lim){
	Limite = Lim+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2 ; i < Limite ; ++i)
	if(bs[i]){
		for(ll j = i*i ; j < Limite ; j += i) bs[j] = 0;
		primes.pb(i);
	}
}

bool isPrime(ll N){
	if(N <= Limite) return bs[N];
	
	
	ll raiz = sqrt(N);
	
	for(int i = 0 ; primes[i] <= raiz ; ++i){
		if(N%primes[i] == 0) return false;
	}
	return true;
}



ll numFact(ll N){
	ll idx = 1,FP = primes[0],num = 2ll;
	
	while(FP * FP <= N)
	{
		while(N%FP == 0) N /= FP,num++;
		FP = primes[idx++];
	}
	
	if(N != 1) num++;
	
	return num;
}



ll numDiv(ll N){
	ll idx = 1,FP = primes[0],ans = 1ll;
	
	
	while(FP * FP <= N)
	{
		ll power = 0;
		
		while(N%FP == 0) N /= FP,power++;
		ans *= (power + 1);
		FP = primes[idx++];
	}	
	
	if(N != 1) ans *= 2;
	return ans;
	
}




int main(){

	
	//~ freopen("in","r",stdin);
	
	sieve(10009);
	
	bool temTr[10009];
		
	for(ll i = 0 ; i < 10001 ; ++i){
		temTr[i] = isPrime(numDiv(i));
	}
	
	bool spc;
	int a,b,t;
	
	for(cin>>t;t--;){
		
		scanf(" %d %d",&a,&b);
		
		spc = 0;
		
		for(int i = a; i <= b ; ++i){
			if(temTr[i]){
				if(spc) printf(" ");
				printf("%d",i);
				spc = 1;
			}
		}
		
		puts(spc?"":"-1");				
	}
	return 0;
}
