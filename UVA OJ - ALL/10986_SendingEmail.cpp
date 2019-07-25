#include <bits/stdc++.h>
using namespace std;

#define rep(i__,TAM) for(int i__ = 0 ; i__ < TAM ; ++i__)
#define INF 99999

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> ListaDeAdjacencia;

ListaDeAdjacencia adj;
vi dist;

void dijkstra(int begin,int TamanhoMaximo){
	dist[begin] = 0;
	priority_queue<ii,vector<ii>, greater<ii> > pq;
	pq.push(ii(0,begin));
	
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if(d > dist[u]) continue;
		
		rep(j,(int)adj[u].size()){
			ii v = adj[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
}


int main(){
	//freopen("e","r",stdin);
	int q,s,t,n,m;
	scanf(" %d",&q);
	
	rep(ct,q){		
		scanf("%d %d %d %d",&n,&m,&s,&t);		
		adj.assign(n+3,vii());
		dist.assign(n+3,INF);		
		int u,v,c;
		
		rep(i,m){
			scanf(" %d %d %d",&u,&v,&c);
			adj[u].push_back(ii(v,c));
			adj[v].push_back(ii(u,c));	
		}		
		
		dijkstra(s,n+3);
				
		printf("Case #%d: ",ct+1);
		if(dist[t] == INF) printf("unreachable\n");
		else printf("%d\n",dist[t]);	
	}
	return 0;
}
