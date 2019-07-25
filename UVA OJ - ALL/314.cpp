#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#define MAX 50
#define N 1 /*NORTE*/
#define E 2 /*OESTE*/
#define S 3 /*SUL*/
#define W 4 /*LESTE*/
using namespace std;


/*
       [1]             ---> direita
	    N
		|
[4]W----|----E[2]
	    |	
	    S              <--- esquerda
	   [3]
*/

int grafo[MAX][MAX][5]; // a terceira dimensao para saber se seus vizinhos pra 1,2,3,4 ja foram visitados
int mat[MAX][MAX];
int linha,coluna;

struct no{
	int l;
	int c;
	int tempo;
	int direcao;
	
	no(int l,int c, int tempo,int direcao){
		this->l = l;
		this->c = c;
		this->tempo = tempo;
		this->direcao = direcao;
	}
};

void TransformaMatriz(){
	
	linha--;coluna--;		
	for(int i = 0 ; i < linha ; i++)
	for(int j = 0 ; j < coluna ; j++){			
		if(!mat[i][j] && !mat[i][j+1] && !mat[i+1][j] && !mat[i+1][j+1])
			grafo[i][j][0] = 0;
		else 
			grafo[i][j][0] = 1;
			
		grafo[i][j][1] = 0;
		grafo[i][j][2] = 0;
		grafo[i][j][3] = 0;
		grafo[i][j][4] = 0;
		
	}		
}


bool valida(int l, int c){
	return (l < linha && l >= 0 && c >= 0 && c < coluna);	
}


int bfs(int y, int x,int d, int lf, int cf){
	int dir,esq;
	int L[3],C[3];
	int t;
	queue<no> q;
	q.push(no(y,x,0,d));
	grafo[y][x][d] = 1;
	while(!q.empty()){
		y = q.front().l;
		x = q.front().c;
		t = q.front().tempo;
		d = q.front().direcao;
		q.pop();
		
		if(y == lf && x == cf)
			return t;			
		

		if(d+1 == 5)dir = N;// direita de d
		else dir = d+1;
		
		if(d-1 == 0)esq = W;// esquerda de d
		else esq = d-1;
		
		if(grafo[y][x][dir] == 0){
			q.push(no(y,x,t+1,dir));
			grafo[y][x][dir] = 1;		
		}
		if(grafo[y][x][esq] == 0){
			q.push(no(y,x,t+1,esq));
			grafo[y][x][esq] = 1;		
		}	
		
		
		if(d == N){
			L[0] = y-1; L[1]= y-2; L[2] = y-3;
			C[0] = x; C[1] = x; C[2] = x;
		}
		else if(d == E){
			L[0] = y; L[1]= y; L[2] = y;
			C[0] = x+1; C[1] = x+2; C[2] = x+3;
		}
		else if(d == S){			
			L[0] =y+1; L[1]= y+2; L[2] = y+3;
			C[0] = x; C[1] = x; C[2] = x;
		}
		else if(d == W){
			L[0] = y; L[1]= y; L[2] = y;
			C[0] = x-1; C[1] = x-2; C[2] = x-3;
		}
		
				
		for(int i = 0 ; i < 3 ; i++){	
				
			if(valida(L[i],C[i]) && grafo[L[i]][C[i]][0] == 0){
				 if(grafo[L[i]][C[i]][d] == 0){
					grafo[L[i]][C[i]][d] = 1;
					q.push(no(L[i],C[i],t+1,d));
				 }
				 else
					continue;
			 }
			else i = 4;
				
		}		
	}
	return -1;	
}






int main(){
		//	#ifndef ONLINE_JUDGE
		//	freopen("../e.txt","r", stdin);
		//	freopen("../s.txt","w", stdout);
		//	#endif

	int i,j;
	int li,ci,lf,cf;
	char orientacao[20];
	
	while(scanf(" %d %d",&linha,&coluna),linha||coluna){
		for(i = 0 ; i < linha ; i++)
		for(j = 0 ; j < coluna ; j++)
			scanf("%d",&mat[i][j]);					
		
		scanf("%d%d%d%d %s",&li,&ci,&lf,&cf,orientacao);
		TransformaMatriz();	
		
		
		int k;
		switch(orientacao[0]){
		case 'n':k = N;break;
		case 's':k = S;break;
		case 'e':k = E;break;
		case 'w':k = W;break;		
		}
		
		
		int r = bfs(li-1,ci-1,k,lf-1,cf-1);
		
		printf("%d\n",r);	
		
		
	}
	return 0;
}


