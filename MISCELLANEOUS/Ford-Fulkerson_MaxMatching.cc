/*
Your task is to find maximum matching in the given bipartite graph.
Input
The first line contains two integers n and m (1 ≤ n, m ≤ 250) — number of the vertices in the part A and in the part B.
The following n lines contain description of the edges. The i-th vertex from A is described in the (i + 1)-th line. Each line contains the vertices from B connected to the i-th vertex from A. Vertices in both parts are numbered independently. Each line ends with 0.
Output
The first line must contain integer l — the number of edges in maximum matching. Each of the following l lines must contain two integers uj, vj — the edges of maximum matching.
*/

#include <bits/stdc++.h>
using namespace std;
#define maxn 600
#define pb push_back

int match[maxn] = {0},vis[maxn] = {0},n,m;
vector<int> G[maxn];

// 1...n são os vertices pertencem a parte 'A'
// n+1...m são os vertices que pertencem a parte 'B'
// não tem sink e não tem source


bool dfs(int u){
	if(vis[u]) return 0;
	
	vis[u] = 1; // não posso parear com esse cara qndo estiver voltando, isto é, 'A' <- 'B', forma um ciclo e emparelhamento nao pode
	
	for(auto i : G[u]){
		if(!match[i] || dfs(match[i])){ // se o vertice i não foi combinado ainda OU se foi combinado e podemos modificar as combinaçoes existentes para
			match[i] = u;									// deixar u -> i , e match[i] tem outra combinacao, que por sua vez e valida , deixando o mesmo numero de 
			return 1;											// combinacões anteriores mais a atual
		}
	}
	return 0;
}


int main(){
	
  //~ freopen("in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	
	for(int i = 1 ; i <= n ; ++i){ // 'A'
		int x;
		while(cin>>x,x){	// 'B'
			G[i].pb(x+n);
		}
	}
	
	int MaxMatching = 0;
	for(int i = 1 ; i <= n ; ++i){
			memset(vis,0,sizeof vis);
			MaxMatching += dfs(i);
	}
	
	cout << MaxMatching << '\n';
	for(int i = 1 ; i <= n+m ; ++i){
		if(match[i] != 0) {
			cout << match[i] << " " << i-n << '\n';
		}
	}
	
	return 0;
}
