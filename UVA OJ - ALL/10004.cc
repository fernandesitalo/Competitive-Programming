#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> graph;

int main(){
	freopen("in","r",stdin);
	int n,l,b,v;
	
	while(scanf(" %d",&n),n){		
		
		graph adj(n);		
		scanf(" %d",&l);
		for(int i = 0 ; i < l ; ++i){
			scanf(" %d %d",&b,&v);
			adj[b].push_back( ii(v,1));
			adj[v].push_back( ii(b,1));
		}		
		queue<int> q;
		q.push(0);
		vi color(n,INF);
		color[0] = 0;
		bool isBipartite = true;
		while(!q.empty() & isBipartite){
			int u = q.front();
			q.pop();
			for(int j = 0 ; j < (int) adj[u].size() ; ++j){
				ii v = adj[u][j];
				if(color[v.first] == INF){
					color[v.first] = 1 - color[u];
					q.push(v.first);
				}
				else if(color[v.first] == color[u]){
					isBipartite = false; break;			
		} } }
		
		printf(isBipartite? "BICOLORABLE.\n":"NOT BICOLORABLE.\n");	
	}
	return 0;
}
