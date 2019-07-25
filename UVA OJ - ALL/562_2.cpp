#include <bits/stdc++.h>
using namespace std;



int table[110][510*100];
int moedas[110];


int fun(int sum){	
	memset(table,0,sizeof table);
	
	for(int item = 1 ; item <= moedas[0] ; item++){		
		for(int mochila = 0 ; mochila <= sum ; mochila++){
			
			if(moedas[item] <= mochila){
				table[item][mochila] = moedas[item] + table[mochila-moedas[item]][]
			}
			else{
				table[item][mochila] = table[item-1][mochila];				
			}
								
		}
	}	
	return table[moedas[0]][sum];
}


int main(){	
	//freopen("e.txt","r",stdin);
	
	int qtd;
	scanf(" %d",&qtd);
	while(qtd--){
		scanf(" %d",&moedas[0]);
		
		int soma = 0;
		
		for(int i = 1 ; i <= moedas[0] ; i++){
			scanf(" %d",&moedas[i]);
			soma +=	moedas[i];	
		}
		int maxi = soma/2;
		
		
		int res = fun(maxi);
		
		printf("%d\n",soma - 2*res);
	}
	
	return 0;
}


