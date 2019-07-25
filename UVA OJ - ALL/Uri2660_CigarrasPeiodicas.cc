#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b){ return (b == 0 ? a : gcd(b , a%b));}
ull lcm(ull a, ull b){ return (a * b / gcd(a,b));}



int main(){
	
	
	//~ freopen("in","r",stdin);
	
	ull n,l;
	
	while(scanf(" %llu %llu",&n,&l) == 2){
		
		ull aux;
		scanf(" %llu",&aux);
		
		ull cicloAtual = aux;
		
		for(ull i = 1 ; i < n ; ++i){
			scanf(" %llu",&aux);
			cicloAtual = lcm(cicloAtual,aux);
		}
		
		
		ull periodo_Otimo = 1;
		ull maiorMdc = cicloAtual;
		
		
		for(ull i = 1 ; i <= l ; ++i){
		
			ull temp = lcm(cicloAtual,i);
		
			if(temp > maiorMdc && temp <= l){
				periodo_Otimo = i;
				maiorMdc = temp;
			}
		}
		
		printf("%llu\n",periodo_Otimo);

	}

	return 0;
}
