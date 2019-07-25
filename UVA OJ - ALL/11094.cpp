#include <stdio.h>
#include <queue>
#define MAX 20
using namespace std;

char grafo[MAX][MAX];
bool vis[MAX][MAX];
int cont,linha,coluna;
char agua,terra;

void p(int l,int c){
	
	queue<pair<int,int> >fila;
	fila.push(make_pair(l,c));
	cont = 1;
	vis[l][c] = true;
	
	while(!fila.empty()){
		
		l = fila.front().first;
		c = fila.front().second;
		fila.pop();
		
		int L[] = {l  ,l  ,l+1,l-1};
		int C[] = {c-1,c+1, c ,  c};
		
		for(int u = 0 ; u < 4 ; u++){
			if(C[u] == -1) C[u] = coluna-1;			
			
			if(C[u] == coluna) C[u] = 0;			
				
			if(L[u] >= 0 && L[u] < linha && grafo[L[u]][C[u]] == terra && !vis[L[u]][C[u]]){
				cont++;
				vis[L[u]][C[u]] = true;
				fila.push(make_pair(L[u],C[u]));
			}	
		}
	}
}

int main(){
	int i,j;
	char entrada[30];
	
	while(scanf(" %d %d",&linha,&coluna) != EOF){
		for(i = 0 ; i < linha ; i++)		
			for(scanf(" %s",entrada),j = 0; j < coluna ; j++)
				{grafo[i][j] = entrada[j];vis[i][j] = false;}
		
		scanf(" %d %d",&i,&j);
		
		terra = grafo[i][j];
		
		cont = 0;
		p(i,j);		
		
		int maior = 0;
		for(i = 0 ; i < linha ; i++){
			for(j = 0 ; j < coluna ; j++){				
				if(grafo[i][j] == terra && vis[i][j] == false){	
					p(i,j);					
					if(cont > maior)maior = cont;								
				}
			}	
		}				
		printf("%d\n",maior);	
	}
	return 0;
}
