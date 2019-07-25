#include <bits/stdc++.h>
using namespace std;

int taba[100];


int pd[60][60];

int F(int inicio, int fim){

	if(taba[inicio] == taba[fim-1]) return 0;
	
	int & ref = pd[inicio][fim];

	if(ref != -1) return ref;
	
	ref = 9999999;
	
	for(int i = inicio+1; i < fim ; ++i){
		ref = min(ref,F(inicio,i) + F(i,fim) +(taba[fim] - taba[inicio]));// TENHO A OPCAO DE CORTAR ENTRE OS 
																		  // N CORTES ENTRE INICIO E FIM DESSA TABA
	}
	return ref;
}


int main(){

	int tam,n; 

	while(scanf(" %d",&tam),tam){

		taba[0] = 0;
		scanf(" %d",&n);
		taba[n+1] = tam;
		
		for(int i = 1 ; i <= n ; ++i) scanf(" %d",taba + i);
		
		memset(pd,-1,sizeof pd);
		printf("The minimum cutting is %d.\n",F(0,n+1));
		
	}

	return 0;
}
