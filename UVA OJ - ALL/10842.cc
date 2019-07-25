/* dentre a arvore geradora, optar pelos vertices mais pesados,
 * e dentre estes escolher o menor deles.... 
 * 
 * */


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
priority_queue<ii> pq;
vi vis;
 
 
void process(int vtx){
	vis[vtx] = 1;
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!vis[v.first]) pq.push( ii(v.second,v.first) );
	}
}
 


int main(){
	freopen("e","r",stdin);
	int q,v1,v2,cost,n,m;
	
	scanf(" %d",&q);
	for(int ct = 1 ; ct <= q ; ct++){
		scanf(" %d %d",&n,&m);
		adj.assign(n+5,vii());
		vis.assign(n+5,0);
		
		while(m--){
			scanf(" %d %d %d",&v1,&v2,&cost);
			adj[v1].push_back( ii(v2,cost) );
			adj[v2].push_back( ii(v1,cost) );
		}
		
		int ans = 9999999;	
		process(v1);
		while(!pq.empty()){
			int d = pq.top().first;
			int u = pq.top().second;
			pq.pop();			
			if(!vis[u]) ans = min(ans,d),process(u);
		}
		
		printf("Case #%d: %d\n",ct,ans);
		
	}
	
	return 0;
}
