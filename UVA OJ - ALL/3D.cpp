#include <stdio.h>
#include <queue>
#define MAX 31
using namespace std;

char grafo[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int linha,coluna,profundidade;// pra nao ter que passar parametro na funcao...

struct no{
	int a;//nivel
	int b;//linha
	int c;//coluna	
	no(int a,int b, int c){
		this->a = a;
		this->b = b;
		this->c = c;		
	}
};


int bfs(int n, int l, int c){
	queue<no> fila;
	fila.push(no(n,l,c));
	dist[l][c][n] = 0;	
	
	while(!fila.empty()){
		n = fila.front().a;
		l = fila.front().b;
		c = fila.front().c;
		fila.pop();
		
		int N[] = {n-1, n+1, n , n , n  , n  };
		int L[] = {l  , l  , l , l , l+1, l-1};
		int C[] = {c  ,  c ,c+1,c-1, c  , c  };
		
		for(int i = 0 ; i < 6 ; i++)
		{
			if(N[i] >= 0 && N[i] < profundidade && L[i] >= 0 && L[i] < linha && C[i] >= 0 &&C[i] < coluna && grafo[L[i]][C[i]][N[i]] != '#')
			{
				if(grafo[L[i]][C[i]][N[i]] == 'E')
					return (1 + dist[l][c][n]);
				
				grafo[L[i]][C[i]][N[i]] = '#';// marca como visitado aproveitando a propria matriz existente
				dist[L[i]][C[i]][N[i]] = 1 + dist[l][c][n];
				fila.push(no(N[i],L[i],C[i]));			
			}			
		}
	}	
	return -1;// nao tem jeito de sair da jaula
}

int main()
{
	int n,i,j;
	int l,c,p;
	
	while(scanf("%d%d%d",&profundidade,&linha,&coluna), linha||coluna||profundidade){	
	for(n = 0 ; n < profundidade ; n++)
		for(i = 0 ; i < linha ; i++)
			for(j = 0 ; j < coluna ; j++){
				scanf(" %c",&grafo[i][j][n]);	
				dist[i][j][n] = -1;	
				
					if(grafo[i][j][n] == 'S'){
						p = n;
						l = i;
						c = j;
					}				
				}		
		
		l = bfs(p,l,c);		
		if(l == -1)
			puts("Trapped!"); // mostro nao vai sair da jaula
		else
			printf("Escaped in %d minute(s).\n",l);// monstro saiu da jaula
	}
	return 0;
}
