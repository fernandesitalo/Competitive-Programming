#include <stdio.h>
int vet[100009];

int busca(int x)
{
	if(vet[x] == x)
		return x;		
	return vet[x] = busca(vet[x]);		
}

int main(){
	int a,b,n,k;
	char op;
	scanf(" %d %d",&n,&k); //  'n' e o numero de bancos
							// 'k' e o numero de operacoes
	
	for(a=0; a < n ; a++) /// NO INCIO, O PROPRIO BANCO E PAI DE SI MESMO 
		vet[a] = a;
							
	for( ; k ;k-- )
	{
		scanf(" %c %d %d",&op,&a,&b); // a - CODIGO DO BANCO A, b - CODIGO DO BANCO B
	
		a = busca(a-1);// acha o pai do banco a
		b = busca(b-1);// acha o pai do banco b
		
		if(op == 'F')					
			vet[a] = b;
		else
			printf(vet[a] == vet[b] ?"S\n":"N\n");
	}						
	return 0;
}
