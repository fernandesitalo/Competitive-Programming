#include <bits/stdc++.h>
#define MAXN 10009
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii; // <peso,distancia>

vector<vii> G;

int ouro[MAXN];
bitset<1000000> vis;

int carruagem;

int F(int u){

	vis[u] = 0;
	int ans = 0;

	for(int i = 0 ; i < (int)G[u].size() ; ++i){
		
		ii v = G[u][i];
		
		if(vis[ v.first ]){
			ans += F(v.first) + v.second*2* (int)ceil((double)ouro[v.first]/(double)carruagem);			
			ouro[u] += ouro[v.first];
		}		
	}
	
	//~ cout << "vertice "<< u +1 << " = "<< ans << endl;
	
	return ans;
}





int main(){
		
	freopen("in","r",stdin);	
		
	int n;

	scanf(" %d %d",&n,&carruagem);
	
	for(int i = 0 ; i < n ; ++i) scanf(" %d",ouro+i);
	
	G.assign(n+1,vii());
	
	int u,v,c;
	
	for(int i = 0 ; i < n-1 ; ++i){
		scanf(" %d %d %d",&u,&v,&c);
		u--;v--;
		G[u].push_back(ii(v,c));
		G[v].push_back(ii(u,c));
	}
	
	vis.set();
	
	printf("%d\n",F(0));


	return 0;
}
