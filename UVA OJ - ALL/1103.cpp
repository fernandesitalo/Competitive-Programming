#include <stdio.h>
#include <map>
#define MAX 300
using namespace std;

int bin[][4] = {0,0,0,0 ,0,0,0,1 ,0,0,1,0 ,0,0,1,1 ,0,1,0,0 ,0,1,0,1 ,0,1,1,0, 
				0,1,1,1  ,1,0,0,0 ,1,0,0,1  ,1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1, 1,1,1,0, 1,1,1,1};
				
int grafo[MAX][MAX];
int L[] = {0,0,1,-1};
int C[] = {-1,1,0,0};
int linha,coluna;

bool valida(int l,int c){
	return (l >= 0 && l < linha && c >= 0 && c < coluna);
}

void PintaFundo(int l, int c){
	for(int i = 0 ; i < 4 ; i++)
		if(valida(l+L[i],c+C[i]) && grafo[l+L[i]][c+C[i]] == 0){
			grafo[l+L[i]][c+C[i]] = 3;
			PintaFundo(l+L[i],c+C[i]);
		}
}
int cont;

void Hiero(int l, int c){	
	for(int i = 0 ; i < 4 ; i++){
		if(valida(l+L[i],c+C[i])){

			if(grafo[l+L[i]][c+C[i]] == 1){
				grafo[l+L[i]][c+C[i]] = 7;
				Hiero(l+L[i],c+C[i]);
			}			
			else if(grafo[l+L[i]][c+C[i]] == 0){
				cont++;
				grafo[l+L[i]][c+C[i]] = 3;
				PintaFundo(l+L[i],c+C[i]);
			}
		}
	}
}

int main(){
	int i,j,k;
	int ct = 1;
	char entrada[400];
	while(scanf(" %d %d",&linha,&coluna), linha || coluna){
		for(i = 0 ; i < linha ; i++){		
			scanf(" %s",entrada);	
			int col = 0;
			for(j = 0 ; j < coluna ; j++){
				int aux = entrada[j] - '0';
				if(aux > 9)aux = entrada[j] - 87;// tabela ascii				
				for(k = 0 ; k < 4 ; k++){
					grafo[i][col++] = bin[aux][k];		
				}					
			}
		}	
		
		coluna *=4;
		
		for(i = 0 ; i < linha ; i++){
			for(j = 0 ; j < coluna ; j++){
				if((i == 0 || i == linha-1 || j == 0 || j == coluna-1) && grafo[i][j] == 0){
					grafo[i][j] = 3;
					PintaFundo(i,j);			
				}
			}
		}
		map<char,int> m;
		map<char,int>::iterator it;
				
		for(i = 0 ; i < linha ; i++)
			for(j = 0 ; j < coluna ; j++)
				if(grafo[i][j] == 1){
					cont = 0;
					grafo[i][j] = 7;
					Hiero(i,j);				
				
					if(cont == 0)m['W']++;				
					else if(cont == 1) m['A']++;
					else if(cont == 2) m['K']++;
					else if(cont == 3) m['J']++;
					else if(cont == 4) m['S']++;
					else if(cont == 5) m['D']++;
				}
		
		printf("Case %d: ",ct++);
		for(it = m.begin() ; it != m.end() ; it++)			
			for(j = m[it->first],i = 0 ; i < j ; i++)
				printf("%c",it->first);			
		printf("\n");
	}			
	return 0;
}
