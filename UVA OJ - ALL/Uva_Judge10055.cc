#include <bits/stdc++.h>
using namespace std;

int main(){
	long long Seu,Oponente;
	while(scanf("%lld%lld",&Seu,&Oponente)!= EOF){
		printf("%lld\n",(long long)fabs(Oponente - Seu));
	}
	return 0;
}
