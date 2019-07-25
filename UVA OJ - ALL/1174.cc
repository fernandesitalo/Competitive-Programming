#include <bits/stdc++.h>
using namespace std;

#define TAM 100

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> adj; // <vertice vizinho, custo da aresta>



vi taken;
priority_queue<ii> pq; // <distancia, vertice>

void process(int vtx){
	taken[vtx] = 1;
	for(int j = 0 ; j < (int)adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!taken[v.first]) pq.push( ii( -v.second , -v.first ) );
	}
}


int main(){
	freopen("e","r",stdin);
	int q,cost,m,n;
	string str1,str2;
	scanf(" %d",&q);
		
	while(q--){		
		scanf(" %d %d",&m,&n);

		adj.assign( m+5 , vii() ); //// incicialização
		taken.assign( m+5 , 0 ); //// inicialização
		
		map< string , int > indice;
		int index = 0;
		while(n--){
			
			cin>> str1 >> str2;
			scanf(" %d",&cost);
			
			if( indice.find(str1) == indice.end() ) indice[ str1 ] = index++;
			if( indice.find(str2) == indice.end() ) indice[ str2 ] = index++;
			
			adj[ indice[str1] ].push_back( ii( indice[str2] , cost ) );
			adj[ indice[str2] ].push_back( ii( indice[str1] , cost ) );		
		}

		
		process( 0 );
		int mst_cost = 0;
		
		while(!pq.empty()){
			int u = - pq.top().second;
			int w = - pq.top().first;
			pq.pop();
			if(!taken[u]) mst_cost += w, process(u);		
		}
		
		printf("%d\n",mst_cost);
		if(q)puts("");
	}
		
	return 0;
}
