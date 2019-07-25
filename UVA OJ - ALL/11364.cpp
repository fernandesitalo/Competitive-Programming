#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
	int qtd,t,aux;
	scanf(" %d",&qtd);
	while(qtd--){
		scanf(" %d",&t);
		int menor = 99999;
		int maior = -99999;
		
		while(t--){
			scanf(" %d",&aux);
			if(menor > aux) menor = aux;
			if(aux > maior) maior = aux;
		}
		printf("%d\n",2*(maior-menor));	
	}
	return 0;
}	
