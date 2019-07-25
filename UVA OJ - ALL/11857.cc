/*	UVA JUDGE 11857 - Driving Range
 * 	
 * 	PRIM , APLICAÇÃO DIRETA 
 * 
 * 
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

priority_queue<ii> pq;
vector<vii> adj;
vi taken;

void process(int vtx){
	taken[vtx] = 1;	
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!taken[v.first]) pq.push( ii(-v.second,-v.first) );
	}
}


int main(){
	//freopen("e","r",stdin);
	int n,m,u,v,c;
	
	while(scanf(" %d %d ",&n,&m),n || m){
		adj.assign(n+5,vii());
		taken.assign(n+5,0);
		
		u = v = c = 0;
		
		while(m--){
			scanf("%d %d %d",&u,&v,&c);
			adj[u].push_back( ii(v,c) );
			adj[v].push_back( ii(u,c) ); 
		}
		
		int ans = 0;
		int mst_cost = 0;
	
		process(u);
		
		while(!pq.empty()){			
			int u = - pq.top().second;
			int w = - pq.top().first;
			pq.pop();			
			if(!taken[u]){
				process(u);
				ans = max(ans,w);
				mst_cost += w;
			}
		}	
		
		bool con = true;
		for(int i = 0 ; i < n ; ++i){
			if(!taken[i]){
				con = false;
				break;
			}
		}
		
		if(con) printf("%d\n",ans);
		else puts("IMPOSSIBLE");		
	}
	return 0;
}
