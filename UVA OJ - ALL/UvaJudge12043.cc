#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define pb push_back
#define file freopen("in","r",stdin);
#define deb puts("DEBUG")	


vector<ll> primos;
ll limite;
bitset<1000100> ehprimo;

void sieve(ll lim){
	limite = lim+1;
	ehprimo.set();
	ehprimo[0] = ehprimo[1] = 0;
	for(ll i = 2 ; i <= limite ; ++i){
		if(ehprimo[i]){
			for(ll j = i*i ; j <= limite ; j += i) ehprimo[j] = 0;
			primos.pb(i);
		}
	}
}


// soma dos numeros de divisores de a,b,c
// soma das somas do numeros de divisores de a,b,c

ll sd;
ll snd;

void num(ll N){
	
	ll idx = 1;
	ll FP = primos[0];
	ll sumdiv = 1; // numero de divisores
	ll numdiv = 1;
	
	while(FP * FP <= N){
		ll power = 0;
		while(N % FP == 0){ N /=FP; power++;}
		sumdiv *= (power+1);
		numdiv *= ((ll)pow((double)FP,power+1.0)-1)/(FP-1);
		FP = primos[idx++];
	}
	
	if(N!=1) sumdiv *= 2,numdiv *= ((ll)pow((double)N,2.0)-1)/(N-1);;
	
	//~ cout << sumdiv << "  " << numdiv << endl;
	
	sd  += sumdiv;	
	snd += numdiv;
}


int main(){
	
	ll a,b,k;
	
	sieve(1000001);
	
	int t;
	for(cin>>t;t--;){
		scanf(" %lld %lld %lld",&a,&b,&k);
		
		sd = snd = 0ll;
		
		for(ll i = a ; i <= b ; ++i){
			if(i % k == 0){
				num(i);
			}
		}
		
		printf("%lld %lld\n",sd,snd);
		
	}
	
	return 0;
}
