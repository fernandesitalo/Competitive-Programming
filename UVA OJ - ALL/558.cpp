#include<bits/stdc++.h>
using namespace std;

#define INF 9999999
#define rep(i__,TAM) for(int i__ = 0 ; i__< TAM ; ++i__)
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


vector<vii> adj;
vi dist;
// 's' VERTIVE DE INICIO(QUALQUER UM)   'qtdV' - QUANTIDADE DE VERTICES
bool BellmanFord(int s,int qtdV){ // RETORNA VERDADEIRO SE EXISTE CICLO NEGATIVO
	dist[s] = 0;			
	
	for(int u = 0 ; u < qtdV ;++u){
		for(int j= 0; j < (int)adj[u].size(); ++j){
			ii v = adj[u][j];				
			dist[v.first] = min(dist[v.first],dist[u]+v.second);
		}		
	}	
	
	for(int u = 0 ; u < qtdV ;++u){///relaxa a ultima vez
		for(int j= 0; j < (int)adj[u].size(); ++j){
			ii v = adj[u][j];	
			/// se for possivel relaxar qlqer vertice que seja, 
			//entao existe ciclo negativo			
			if(dist[v.first] > dist[u]+v.second) return true;
		}		
	}	
	return false;  /// nao relaxou nenhum vertice .: nao existe ciclo negativo
}



int main(){
	//freopen("e.txt","r",stdin);
	
	int n,m,q;
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d %d",&n,&m);
		
		adj.assign(n + 100,vii());
		dist.assign(n + 100,INF);
		 
		int u,v,c;
		
		rep( i , m ){
			scanf(" %d %d %d",&u,&v,&c);
			adj[u].push_back( ii( v , c ) );			
		}
		
		printf(BellmanFord( 0 , n )?"possible\n":"not possible\n");	
	}
	return 0;
}


