#include <bits/stdc++.h>
using namespace std;

int main(){
	puts("PERFECTION OUTPUT");
	int soma,qtd,n;
	while(scanf("%d",&n),n){
		soma = 0;
		if(n != 1){		
			soma = 1;
			qtd  = 1;			
			for(int i = 2 ; i <= n/2 ; ++i){
				if(n%i == 0){
					qtd++;
					soma += i;
				}
			}
		}
		printf("%5.d  ",n);
		if(soma == n) puts("PERFECT");
		else if(soma > n) puts("ABUNDANT");
		else puts("DEFICIENT");
	}
	puts("END OF OUTPUT");
	return 0;
}
