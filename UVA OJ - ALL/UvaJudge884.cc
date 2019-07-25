#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back


bitset<1000999> bs;
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



int main(){
	
	ll n;
	
	
	sieve(1000000);
	
	while(cin>>n){
		
		ll ans = 0;
		
		for(ll idx = 0 ; primes[idx] <= n ; idx++){
			
			double razao = 1.0/(double)primes[idx];
			
			for(int i = n*razao ; i ; i *= razao){
				ans += i;
			}	
		}
		cout << ans << endl;
	}
	
	return 0;
}
