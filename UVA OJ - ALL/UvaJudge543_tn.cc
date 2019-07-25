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
	
	int n;
	while(scanf(" %d",&n), n){
		
		// n = x + y
		// y = n - x
		// .:
		// x + (n-x) = n
		// onde x e (n-x) devem ser primos!!!!!!!
		// passou meio que uma busca linear....
		
		int i;
		bool achou = false;
		for(i = n-1 ; i > 2 ; --i){
			if(ISPRIME(i)){
				if(ISPRIME(n-i)){
					if(i+(n-i) == n){
						achou = true;
						break;
					}
				}
			}
		}
		
		if(achou)	printf("%d = %d + %d\n",n,n-i,i);
		else puts("Goldbach's conjecture is wrong.");
	}
	return 0;
}
