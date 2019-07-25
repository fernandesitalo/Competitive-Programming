#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back


bitset<10000010> bs;
ll Limite;
vector<ll> primes;


void sieve(ll Lim){
	Limite = Lim+1;
	bs.set();	
	bs[0] = bs[1] = 0;
	for(ll i = 2 ; i <= Limite ; ++i)
	if(bs[i]){
		primes.pb(i);
		for(ll j = i*i ; j <= Limite ; j+= i) bs[j] = 0;
	}
}

ll EulerPhi(ll N){
	if(N == 1) return 0;
	ll idx = 1,FP = primes[0],ans = N;
	while(FP * FP <= N)
	{		
		if(N%FP == 0) ans -= ans/FP;
		while(N%FP == 0) N /= FP;
		FP = primes[idx++];
	}	
	if(N != 1) ans -= ans/N;
	return ans;
	
}

int main(){
	
	ll n;
	
	freopen("in","r",stdin);

	sieve(100000ll);
	
	while(cin>>n,n){
		cout<<EulerPhi(n)<< endl;
	}

	return 0;
}
