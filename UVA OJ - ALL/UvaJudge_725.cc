/**	UVa judge 725 - DIVISION
  *	
  * 
  * Solução: busca completa iterativa!
  * 
  * vamos desde a primeira possibilidade(01234) ate a ultima (98765)
  * pegamos a possibilidade e multiplicamos por N, ate pq queremos dois numeros
  * que juntos tem uma unica vez os numeros de 0 a 9...
  * 
  * entao se o numero tiver o 0 nao significativo, isto é, 
  * 0 a esquerda por exemplo 01234, temos que ativar o zero...
  * 
  * entao vamos ativar todos os numeros da primeira possibilidade
  * e ativar todos os numero do complemento da possibilidade, isto é,
  * o numero que e possibilidade * N.... pq devem ser divisiveis e tals
  * 
  **/


#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	bool p = false;
	while(scanf(" %d",&N),N){ // queremos um numero fghij/abcde = N onde 
		bool alface = true;   // as letras sao interios de 0 a 9 que nao se repetem
		
		if(p) puts(""); p = true;
		
		for(int fghij = 01234 ; fghij <= 98765/N ; ++fghij){
			int abcde = fghij * N;
			int bitmask = (fghij < 10000); // ativa o bit zero se ele for um zero a esquerda
			
			int temp = fghij;
			while(temp){bitmask |= 1<<(temp%10);temp /= 10;}
			temp = abcde;
			while(temp){bitmask |= 1<<(temp%10);temp /= 10;}
			
			if(bitmask == 1023){ // 1023 == 1111111111 em binario, isto é, todos os bits ativos
				printf("%0.5d / %0.5d = %d\n",abcde,fghij,N);alface = false;	
			}
		}
		
		if(alface) printf("There are no solutions for %d.\n",N);		
	}
	return 0;
}
