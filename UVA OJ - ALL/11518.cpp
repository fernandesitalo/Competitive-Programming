#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

typedef vector<bool>	vb;
typedef vector<int>		vi;

vb visited;
vector<vi> AdjList;
int cont ;

void DFS(int u) {	
	visited[u] = true;		
	for (int j = 0; j < (int)AdjList[u].size(); ++j){
		if (visited[ AdjList[u][j] ] == false) {
			cont++;
			DFS( AdjList[u][j] );	
		}
	}
}


void reset(int V){ 
	visited.assign(V, false);	
	vi a;AdjList.assign(V,a);	
}



int main(void){
	
	int t,u,v,n,m,i,aux;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d%d",&n,&m,&i);
		
		reset(n+3);
		
		while(m--){
			scanf("%d%d",&u,&v);
			AdjList[u].push_back(v);
		}
		cont = 0;
		
		while(i--){
			scanf("%d",&aux);		
			
			if(visited[aux] == false){
				DFS(aux);cont++; // SE ENTROU AQUI, TEMOS QUE CONTAR UM DOMINO DERRUBADO, O PRIMEIRO, OS OUTROS SERAO CONTADOS NO DFS
			}
		}	
		
		printf("%d\n",cont);				
	}
	return 0;	
}
