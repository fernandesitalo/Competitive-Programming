#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main(){
	int n,custo,aux;
	while(scanf(" %d",&n)!= EOF){
		scanf(" %d",&custo);
		
		int soma = 0;
		int soma_maxima = -INF;
		
		for(int i = 0 ; i < n ; ++i){
			scanf(" %d",&aux);
			soma += (aux - custo);
			soma_maxima = max(soma,soma_maxima);
			if(soma < 0) soma = 0;			
		}
		printf("%d\n",(soma_maxima > 0 ? soma_maxima :  0));
	}
	return 0;
}
