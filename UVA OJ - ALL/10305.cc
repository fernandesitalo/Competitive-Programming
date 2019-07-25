#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;		
vi grauentrada;		/// grau de entrada de cada vertice
vector<vi> G; 				/// GRAFO G[u].push_back(v); u -> v
int N; 						/// NUMERO DE VERTICES

vi ts;						/// ORDENACAO TOPOLOGICA

bool TOPOLOGICAL_SORT(){
	
	queue<int> q; 
	for(int i = 0 ; i < N ; ++i)			/// colocar na fila todos
		if(grauentrada[i] == 0) q.push(i);	/// que podem ser visitados
											/// sem pre-requisitos de visita
										    /// (sem ter que visitar outros)

	int explorados = 0;	/// total de vertices explorados ate o final do BFS
		
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		ts.push_back(u+1); /// aqui e formada a ordenacao topologica
		
		for(int i = 0 ; i < (int) G[u].size() ; ++i){
			int v = G[u][i];
			if(--grauentrada[v] == 0){ // estamos "retirando" o vertice u do grafo
				q.push(v);			   // entao vamos "tirar" suas conexoes, isto é
			}						   // decrementar o grau de entrada de seus vizinhos
		}
		
		explorados++; // ao final do for, o vertice 'u' foi explorado
	}	
	
	return (explorados == N); /// returna TRUE caso nao tenha ciclo
							  /// return FALSE caso tenha ciclo
}



int main(){
	
	int m;
	
	while(scanf(" %d %d",&N,&m),N|m){
		
		G.assign(N,vi());
		grauentrada.assign(N,0);
		ts.clear();
		
		int u,v;
		
		while(m--){
			scanf(" %d %d",&u,&v);
			G[u-1].push_back(v-1);
			grauentrada[v-1]++;
		}
		
		TOPOLOGICAL_SORT();
		
		printf("%d",ts[0]);
		for(int i = 1 ; i < (int)ts.size() ; ++i){
			printf(" %d",ts[i]);
		}
		puts("");	
	}
	return 0;
}
