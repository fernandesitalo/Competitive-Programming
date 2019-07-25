/* UVA JUDGE 12047	- Highest Paid Toll
 * A questão pede para achar o maior vertice possivel ao qual se possa
 * passar, atraves de um caminho se inciando em 's' e terminando em 't'
 * menor do que 'p'.
 * Foram usados 2 grafos... O primeiro de acordo com a entrada de dados
 * o segundo e o inverso do primeiro.
 * Então executamos dijkstra no grafo1 apartir do vertice 's' inicial
 * depois executamos do dijkstra no grafo2 apartir do vertice 't' final
 * 
 * todos vertices sao armazenados e uma fila de prioridade mv, da maior
 * a menor... da seguinte forma: (custoDaAresta,vertice inicial,vertice final)
 * começando do topo da fila de prioridade, verificamos a condicao:
 * 
 *  if(dist_g1[vertice1] + dist_g2[vertice2] + custoDaAresta <= p)
 * 
 * se esta condicao for satisfeita, paramos a busca, e imprimimos o custo da aresta
 * caso contrario, vamos percorrer toda fila de prioridade , caso nao tenha nenhuma
 * aresta que satisfaça a condicao, imprimimos '-1'
 *  
 * */


#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
#define rep(i_,TAM) for(int i_= 0 ; i_ < TAM ; ++i_)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;

vi dist,dist1;

void dijkstra(vector<vii>& adj, int s, int tam){
	dist.assign(tam,INF);	
	priority_queue<ii,vector<ii> , greater<ii> >pq;
	pq.push( ii(0,s) ); 
	dist[s] = 0;
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();		
		if(d > dist[u]) continue;
		for(int j = 0 ; j < (int) adj[u].size() ; ++j){
			ii v = adj[u][j];
			if(dist[v.first] > dist[u]+v.second){
				dist[v.first] = dist[u] + v.second;
				pq.push( ii(dist[v.first] , v.first) );
			}
		}	
	}	
}

int main(){
	///freopen("e","r",stdin);
	int q,n,m,s,t,p;
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d %d %d %d %d",&n,&m,&s,&t,&p);
		priority_queue<iii> mv;
		vector<vii> g1(n+2),g2(n+2);
		int uu,vv,cc;
		rep(i,m){
			scanf(" %d %d %d",&uu,&vv,&cc);
			g1[uu].push_back( ii(vv,cc) );
			g2[vv].push_back( ii(uu,cc) );
				
			mv.push(iii(cc,ii(uu,vv)));
		}
		
		dijkstra(g1,s,n+2);
		dist1 = dist;
		dijkstra(g2,t,n+2);
		
		int ans = -1;
		while(!mv.empty()){
			int cost = mv.top().first;
			int v1 = mv.top().second.first;
			int v2 = mv.top().second.second;
			mv.pop();
			
			if(dist1[v1] + dist[v2] + cost <= p){
				ans = cost;
				break;
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}
