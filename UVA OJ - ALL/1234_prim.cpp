#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
//typedef pair<int>
typedef vector<ii> vii;
typedef vector<vii> graph;

graph adj;
vi taken;
priority_queue<ii> pq; // < custo da aresta ate o vizinho, vizinho >


void process(int vtx){
	taken[vtx] = 1;
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j]; // <vizinho, custo da aresta ate o vizinho>
		if(!taken[v.first]) pq.push( ii(v.second, v.first) );
	}	
}


int main(){
	//freopen("in","r",stdin);
	
	int q,n,m;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d %d",&n,&m);
		adj.assign(n+2,vii());
		taken.assign(n+2,0);
		
		int u,v,c;
		int cost_tot = 0;
		while(m--){
			scanf(" %d %d %d",&u,&v,&c);
			adj[u].push_back( ii(v,c) );
			adj[v].push_back( ii(u,c) );
			cost_tot += c;
		}
		
		process(u);
		int mst_cost = 0;
		while(!pq.empty()){
			u = pq.top().second;
			int d = pq.top().first;
			pq.pop();
			
			if(!taken[u]){
				mst_cost += d;
				process(u);
			}
		}
		
		printf("%d\n",cost_tot - mst_cost);
		
	}
	scanf("%*d");
	return 0;
}
