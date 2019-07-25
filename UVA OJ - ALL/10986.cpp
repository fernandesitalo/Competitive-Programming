#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main(){	
	int n,m,t,u,v,cost,qtd,s;
	int ct = 1;
	
	scanf(" %d",&qtd);
	
	vector<vii> adj;
	
	while(qtd--){
		scanf(" %d %d %d %d",&n,&m,&s,&t);
		
		adj.assign(n+1,vii());
		
		while(m--){
			scanf(" %d %d %d",&u,&v,&cost);
			
			adj[u].push_back(ii(v,cost));
			adj[v].push_back(ii(u,cost));
			
		}
		
		vi dist(n+1, INF); dist[s] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

		  while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int j = 0; j < (int)adj[u].size(); j++) {
			  ii v = adj[u][j];
			  if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
		  } } }
		
		printf("Case #%d: ",ct++);
		printf(dist[t] == INF ? "unreachable\n":"%d\n",dist[t]);
		
	}	
return 0;}
