#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> G;
bool nota[1001];
bool vis[1001];

int a;
int b;

void dfs(int u){
	vis[u] = true;
	
	if(nota[u]) a++;
	else b++;
	
	for(int i = 0 ; i < (int) G[u].size() ; ++i){
		int v = G[u][i];
		if(!vis[v]) dfs(v);
	}
}


int main(){

	int n,m;
	char aux;
	
	while(scanf(" %d %d",&n,&m)!= EOF){
		G.assign(n+1,vi());
		
		for(int i = 0 ; i < n ; ++i){
			scanf(" %c",&aux);
			nota[i] = ('A' == aux);
		}
		
		
		int u,v;
		while(m--){
			cin>>u>>v;
			u--;v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		bool ans = true;
		
		for(int i = 0 ; i < n ; ++i) vis[i] = false;
		for(int i = 0 ; i < n ; ++i){
			if(!vis[i]){
				a = b = 0;
				dfs(i);
				
				if(b%2 != 0){
					ans = false;
					break;
				}
			}
		}
		
		puts(ans?"Y":"N");
		
	}

}
