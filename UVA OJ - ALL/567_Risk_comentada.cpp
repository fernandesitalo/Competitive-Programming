/*	Uva judge 567 - Risk - accepted
 * 	CATEGORIA: CAMINHO MINIMO
 * 	
 * 	SOLUCAO: APLICAÇÃO DIRETA DO ALGORITMO DE FLOYD WARSHALL'S
 * 	ANAO O QUE SE EXPLICAR, A NAO SER QUE VC NÃO ENTENDA O ALGORITMO...
 * */
#include<bits/stdc++.h>
using namespace std;

int mat[20][20]; // MATRIZ 

void Floyd_Warshall(int V){		
	for(int k = 0 ; k < V ; ++k){
		for(int i = 0 ; i < V ; ++i){
			for(int j = 0 ; j < V ; ++j){
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}


int main(){
	//freopen("e","r",stdin);
	int q,ct = 1,aux;
	
	while(scanf(" %d",&q)!= EOF){
		
		memset(mat,10000,sizeof mat);
		
		while(q--){
			scanf(" %d",&aux);
			mat[0][aux-1] = 1;
			mat[aux-1][0] = 1;
		}
		
		for(int i = 1; i <= 18 ; ++i){
			scanf(" %d",&q);
			while(q--){
				scanf(" %d",&aux);
				mat[i][aux-1] = 1;
				mat[aux-1][i] = 1;
			}
		}
		
		Floyd_Warshall(20);
		printf("Test Set #%d\n",ct++);
		
		int u,v;
		scanf(" %d",&q);
		while(q--){
			scanf(" %d %d",&u,&v);
			printf("%2.d to %2.d: %d\n",u,v,mat[u-1][v-1]);
		}
		puts("");
	}
	return 0;
}
