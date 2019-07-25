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
	dist.assign(TamanhoMaximo,INF);
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
	freopen("e","r",stdin);
	
	int q,n,e,t;
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d %d %d",&n,&e,&t);
		
		
		adj.assign(n+4,vii());
		int u,v,c,tam;
		scanf(" %d",&tam);
		
		rep(i,tam){
			scanf("%d %d %d",&u,&v,&c);
			adj[u].push_back( ii(v,c) );		
		}
		
		u = 1;
		for(int i = 1 ; i <= n ; ++i){
			if(i != e){
				dijkstra(i , n+3);			
				if(t >= dist[e]) u++;
			}
		}
		printf("%d\n",u);
		if(q)puts("");
	}	
	return 0;
}
