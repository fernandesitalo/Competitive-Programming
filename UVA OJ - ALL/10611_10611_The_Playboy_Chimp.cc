// UVA JUDGE  _ 10611 - The Playboy Chimp

// SOLUCAO : APLICACAO  DE BUSCA BINARIA JA QUE O VETOR ESTA ORDENADO
// LEMBRANDO QUE A BUSCA BINARIA ENCONTRA O PRIMEIRO NUMERO QUE ENCONTRA.. ISTO É
// 11 11 11 11 12 14 15... SE PROCURARMOS O 11, A BUSCA IRA RETORNAR A POSICAO 0...


#include <bits/stdc++.h>
#define MAXN 50001
using namespace std;
typedef long long ll;

ll vet[MAXN];

int main(){
	//freopen("in","r",stdin);
	int n,m;
	ll value;
	
	while(scanf(" %d",&n)!= EOF){
		for(int i = 0 ; i < n ; ++i) scanf(" %lld",&vet[i]);
		
		scanf(" %d",&m);
		
		while(m--){
			scanf(" %lld",&value);
			int l = 0,r = n-1,middle;
			
			while(l!=r){				
				middle = (l+r)/2;				
				if(value > vet[middle]) l = middle+1;
				else r = middle;				
			}
			
			
						
			if(vet[l] == value){
				if(l-1 >= 0) printf("%lld ",vet[l-1]);
				else printf("X ");
				
				while(vet[l+1] == value) l++;
				
				
				if(l+1 < n) printf("%lld\n",vet[l+1]);
				else puts("X");	
				
				continue;	
			}			
			
			if(vet[l] > value){
				
				if(l-1 >= 0) printf("%lld ",vet[l-1]);
				else printf("X ");
			
				if(l < n) printf("%lld\n",vet[l]);
				else puts("X");			
				
				continue;		
			}
					
			if(l >= 0) printf("%lld ",vet[l]);
			else printf("X ");
			
			if(l+1 < n) printf("%lld\n",vet[l+1]);
			else puts("X");			
		}		
	}
	return 0;
}
