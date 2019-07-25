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
	for(int i = 0 ; i < (int) primes.size() ; ++i)
		if(n%primes[i] == 0) return false;
	return true;
}



int main(){
	
	gera(1000000);
	
	
	
	cout << endl;
	cout << cont << endl;
	
	return 0;
}
