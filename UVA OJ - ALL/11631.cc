/*	UVA JUDGE 11631
 * 	
 * 	ALGORITMO DE PRIM, APLICACAO DIRETA 
 * 
 * 	ANS = SOMATORIO DOS PESOS - MST_COST
 * 
 * 
 * 
 * */


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;

priority_queue< ii > pq;
vi taken;


void process(int vtx){
	taken[vtx] = 1;
	
	for(int j = 0 ; j < (int)adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!taken[v.first]) pq.push( ii( - v.second, - v.first) );
	}
}

int main(){
	//freopen("e","r",stdin);
	
	int n,m,u,v,c;
			
		
	while(scanf(" %d %d",&n,&m), n || m ){
		
		int tot = 0;
		adj.assign(n+5,vii());
		taken.assign(n+5 , 0);
		
		while(m--){
			scanf(" %d %d %d",&u,&v,&c);
			adj[u].push_back( ii(v,c) );
			adj[v].push_back( ii(u,c) );
			tot += c;
		}
		
		int mst_cost = 0;
		process(u);
		
		while(!pq.empty()){
			int u = - pq.top().second;
			int w = - pq.top().first;
			pq.pop();
			
			if( !taken[u] ) process(u), mst_cost += w;				
		}

		printf("%d\n",tot-mst_cost);		
	}
	return 0;
}
