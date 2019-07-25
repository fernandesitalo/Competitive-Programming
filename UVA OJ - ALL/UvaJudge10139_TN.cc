#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back


bitset<50010> bs;
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


typedef pair<ll,int> ii;


 vector<ii> Fatora(ll N){ // fatora normal
		
	vector<ii> v;
	int cont;
		
	ll FP = primes[0];
	int idx = 1;
	
	while(FP*FP <= N){	
		cont = 0;	
		while(N%FP == 0){N /= FP;cont++;}
		if(cont != 0)	v.pb(ii(FP,cont));
		FP = primes[idx++];
	}
	if(N != 1) v.pb(ii(N,1));
	return v;
}



int main(){	
	//~ freopen("in","r",stdin);
	sieve(50000);
	
	/*	A CHAVE DA QUESTAO É.. FATORAR O 'M' E APARTIR DESTA FATORACAO, FATORAR O N! 
	 * 	COM BASE NAS BASES DA FATORACAO FEITA DE MM, FAREMOS A DE N!, PARA EVITAR CALCULOS DESNCESSARIOS
	 *  EVITAR TLES....... 
	 */
	
	
	ll a,b;
	while(scanf(" %lld %lld",&a,&b) == 2){
		
		vector<ii> v = Fatora(b);
		
		bool ans = true;
		
		for(auto it : v ){ // C++11
			
			double razao = 1.0/it.first; /// FORMULA PARA FATORAR O N!.... A FORMULA OBEDECE UMA PG
			ll sum = 0;
			for(int i = a*razao ; i ; i *= razao){
				sum += i; // SOMA A PORRA TODA ATE QUE O TERMO SEJA ZERO "FLOOR"
			}
			
			if(it.second > sum) {
				ans = false;
				break;
			}
		}
		if(ans) printf("%lld divides %lld!\n",b,a);
		else printf("%lld does not divide %lld!\n",b,a);
	}
	return 0;
}
