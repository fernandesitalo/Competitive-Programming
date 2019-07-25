#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <utility>
using namespace std;


vector<vector<char> > grafo;
bool vis[15][10];
set<pair<int,int> >pos;





int quantidade(int l, int c, char cor){	
	if(l == (int)grafo.size() || l == -1 || c == 10 || c == -1 || vis[l][c] || grafo[l][c] != cor)
		return 0;
			
	vis[l][c] = true;	
	pos.insert(make_pair(l,c));
	
	return (quantidade(l,c+1,cor) + quantidade(l,c-1,cor) + quantidade(l+1,c,cor) + quantidade(l-1,c,cor)) + 1;
}



void pinta(int l, int c,char cor){
	
	if(l == (int)grafo.size() || l == -1 || c == 10 || c == -1 || grafo[l][c] != cor)
		return;		
		
	grafo[l][c] = '.';
		
	pinta(l,c+1,cor);
	pinta(l,c-1,cor);
	pinta(l+1,c,cor);
	pinta(l-1,c,cor);
}










int main(){
	
	int num,ct;
	int i,j;
	char entrada[25];
	
	for(scanf("%d",&num), ct = 1 ; ct <= num ; ct++){
		int move = 1;
		int score = 0;
		vector<char> v;
		grafo.assign(15,v);	
		int coluna = 10;	
		char mat[10][15];
		
/// leitura dos dados de entrada		
		for(i = 0 ; i < 10 ; i++)						
			for(scanf(" %s",entrada),j = 0 ; j < 15 ; j++)			
				mat[i][j] = entrada[j];					
		for(i = 9; i > -1 ; i--)
			for(j = 0 ; j < 15 ; j++)
				grafo[j].push_back(mat[i][j]);	
				
/// calculo e exigencias do progama			
			
		
		printf("Game %d:\n\n",ct);
		
		while(true)
		{	
			memset(vis,false,sizeof(vis));
			int maior = 1;
			int lin;
			int col;
				
			// ACHAR MAIOR MANCHA NA GRADE	
			for(i = 0 ; i < (int)grafo.size() ; i++){
				for(j = 0 ; j < coluna ; j++){
					if(!vis[i][j] && grafo[i][j] != '.'){
											
						pos.clear();
						int r = quantidade(i,j,grafo[i][j]);
						
						if(r > maior)
						{
							maior = r;
							pair<int,int> aux = *pos.begin();
							lin = aux.first;
							col = aux.second;						
						}
					}		
				}
			}			
			
			if(maior < 2) break;
			
			
			
			i = (maior-2)*(maior-2);
			score += i;
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",move++,col+1,lin+1,maior,grafo[lin][col],i);
			pinta(lin,col,grafo[lin][col]);// PINTAR MAIOR MANCHA	
				
			
			
	// passar as celulas pintadas para frente		
			for(i = 0 ; i < (int)grafo.size() ; i++){
				
				vector<char> fila(10,'.');
				int cont = 0;
				int pontos = 0;
						
				for(j = 0 ; j < coluna ; j++){				
					
					if(grafo[i][j] != '.')
						fila[cont++] = grafo[i][j];
					else
						pontos++;
				}			
				if(pontos == coluna){
					grafo.erase(grafo.begin()+i);
					i--;
				}
				else
					grafo[i] = fila;		
			}
		}
		int resto = 0;
		for(i = 0 ; i < (int)grafo.size() ; i++){
			for(j = 0 ; j < coluna ; j++){
				if(grafo[i][j] != '.')
					resto++;
			}		
		}
		if(resto == 0)
			score += 1000;
		
		printf("Final score: %d, with %d balls remaining.\n",score,resto);
		
		if(ct != num)
			printf("\n");
	
	}
		return 0;
}
