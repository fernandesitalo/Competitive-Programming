#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
priority_queue<ii,vector<ii>,greater<ii> > pq;
vi vis;

void process(int vtx){
	vis[vtx] = 1;
	for(int j = 0 ; j < (int)adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!vis[v.first]) pq.push( ii(v.second,v.first) );
	} 
}

int prim(int begin){
	process(begin);
	int mst_cost = 0;
	
	while(!pq.empty()){
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(!vis[u]) mst_cost += d,process(u);
	}
	return mst_cost;
}


int main(){
	freopen("c","r",stdin);
	
	int q,n,m,a,ct = 1,v1,v2,cost;
	scanf(" %d",&q);
	
	while(q--){
		
		scanf(" %d %d %d",&n,&m,&a);
		adj.assign(n+3,vii());
		vis.assign(n+3,0);
		while(m--){
			scanf(" %d %d %d",&v1,&v2,&cost);
			adj[v1].push_back( ii(v2,cost) );
			adj[v2].push_back( ii(v1,cost) );
		}
		
		int ans = 0;
		int airport = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(!vis[i]){
				ans += prim(i);
				airport++;
			}
		}
		
		printf("Case #%d: %d %d\n",ct++,ans+a*airport,airport);	
	}	
	
	return 0;
}
