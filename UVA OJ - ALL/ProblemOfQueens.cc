#include <bits/stdc++.h>
using namespace std;


int Coluna[10]; // rainha 0 na posicao [0,Coluna[0]] / rainha 1 na posicao [1,Coluna[1]] ...


bool ValidaRainha(int l,int c){  // posicao candidata 
	
	// quantidade de rainhas atual igual a quantidade de linha
	// A RAINHA CANDIDATA PODE NÃO PODE ESTAR NA MESMA LINHA,COLUNA E DIAGONAL DE QUALQUER OUTRA RAINHA
	
	for(int i = 0 ; i < l ; ++i)
		if(c == Coluna[i] || abs(c - Coluna[i]) == abs(i - l)) 
			return false;
	return true;	
}


int QUEENS(int linha){ // QUANTIDADE DE LINHAS E IGUAL A QUANTIDADE DE RAINHAS JÁ POSICIONADAS
	
	if(linha == 8){ 		//deu bom
		for(int l = 0 ; l < 8 ; ++l,puts("")){
			for(int c = 0 ; c < 8 ; ++c){
				if(c == Coluna[l]) printf("X");
				else printf("L");	
				
				printf("  ");		
			}
		}puts("");
		return 1;
	}
	
	int ret = 0;
	
	for(int c = 0 ; c < 8 ; ++c){ // TENTA TODAS POSSIBILIDADES, ISTO É, AS 8 COLUNAS		
		if(ValidaRainha(linha,c)){
			Coluna[linha] = c,ret += QUEENS(linha+1);
		}
	}
	return ret;
}

int main(){
	cout << QUEENS(0);
	return 0;
}
