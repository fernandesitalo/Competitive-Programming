#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define pb push_back
#define file freopen("in","r",stdin);
#define deb puts("DEBUG")	


vector<ll> primos;
ll limite;
bitset<40000> ehprimo;

void sieve(ll lim){
	limite = lim+1;
	ehprimo.set();
	ehprimo[0] = ehprimo[1] = 0;
	for(ll i = 2 ; i <= limite ; ++i){
		if(ehprimo[i]){
			primos.pb(i);
			for(ll j = i*i ; j <= limite ; j += i) ehprimo[j] = 0;
		}
	}
}


int main(){
	
	ll n;
	
	sieve(35000);
	
	while(scanf(" %lld",&n),n){
			
		ll ans = 0;	
			
		for(int i = 0 ; primos[i] <= n ; ++i){
			for(int j = i ; primos[j] <= n ; ++j){
				if(primos[i] + primos[j] == n) ans++;
			}
		}
		cout << ans << endl;
		
	}
	

	return 0;
}
