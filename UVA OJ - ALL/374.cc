#include <bits/stdc++.h>
using namespace std;


long long mod;

long long fastExp(long long n, long long exp){
	if(exp <= 1) return pow(n,exp);
	
	if(exp%2 == 0){
		long long aux = (fastExp(n,exp/2))%mod;
		return (aux*aux)%mod;
	}
	long long aux = (fastExp(n,floor(exp/2)))%mod;
	return (aux*aux*n)%mod;
}

int main(){
	
	long long a,b;
	while(scanf(" %lld %lld %lld",&a,&b,&mod) == 3){
		printf("%lld\n",fastExp(a,b));
	}
	
	return 0;
}
