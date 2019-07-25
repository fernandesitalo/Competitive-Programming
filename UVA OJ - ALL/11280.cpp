#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii; 

#define rep(cont,tam) for(int cont = 0 ; cont < tam ; ++cont)


typedef pair<int,ii> iii; /// first 
						  /// second.first
						  /// seconf.second
						  
int dist[101][101];						  


int fim;
map<int,int> m;			
vector<vii> adj;
			
	
						  
void d(int inicio, int max){	
	memset(dist,INF,sizeof dist);	
	
	dist[0][0] = 0;
	priority_queue<iii,vector<iii>,greater<iii> > pq;
	pq.push(iii(0,ii(inicio,0)));
	
	while(!pq.empty()){
		int d = pq.top().first; // distancia
		int u = pq.top().second.first; // vertice 
		int q = pq.top().second.second; // numero de passos 
		pq.pop();
		
		if(d > dist[u][q]) continue;
		
		for(int j = 0 ; j < (int) adj[u].size() ;j++){
			ii v = adj[u][j];
			
			if(dist[u][q] + v.second  <  dist[v.first][q+1] ){
				dist[v.first][q+1] = dist[u][q] + v.second;
				pq.push(iii(dist[v.first][q+1],ii(v.first,q+1)));
			}			
		}
	}	
}						  


int main(){
	//freopen("e.txt","r",stdin);
	
	int q,n,cost;
	string aux,aux2;
	scanf("%d",&q);
	
	int ct = 1;
	while(q--){
		
		m.clear();
			
		map<string,int> ind;
		scanf(" %d",&n);
		adj.assign(n+3,vii());
		int maxi = n;
		fim = n-1;
		rep(i,n){
			cin>>aux;
			ind[aux] = i;
		}
		
		scanf(" %d",&n);
		rep(i,n){
			cin>>aux>>aux2;
			scanf(" %d",&cost);
			adj[ind[aux]].push_back(ii(ind[aux2],cost));
		}
		
		
		scanf(" %d",&n);
		
		printf("Scenario #%d\n",ct++);
		d(0,maxi+3);
		rep(i,n){
			scanf(" %d",&cost);		
			
			int menor = INF;
			for(int i = 0 ; i <= cost+1 ; ++i){
				//printf("%d ",dist[fim][i]);
				menor = min(menor,dist[fim][i]);
			}
			
			if(menor >= INF)printf("No satisfactory flights\n");
			else printf("Total cost of flight(s) is $%d\n",menor);
			
		}	
		if(q) puts("");
	}
	return 0;
}
