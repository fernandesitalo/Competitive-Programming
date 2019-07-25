#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi grauentrada;
vector<vi> G;
int N;


int TS(){
	
	int ans = -1e9;
	
	queue<ii> q; //<vertice,tempo>
	
	for(int i = 0 ; i < N ; ++i)
		if(grauentrada[i] == 0) q.push(ii(i,1));
		
	int explorados = 0;	
		
	while(!q.empty()){
		int u = q.front().first;
		int t = q.front().second;
		
		ans = max(ans,t);
		q.pop();
		
		for(int i = 0 ; i < (int) G[u].size() ; ++i){
			int v = G[u][i];
			if(--grauentrada[v] == 0){
				q.push(ii(v,t+1));
			}
		}
		
		explorados++;
	}	
	
	if(explorados == N) return ans;
	return -1;
}



int main(){
	
	int tam,v;
	
	while(scanf(" %d",&N)!= EOF){
		G.assign(N+1,vi());
		grauentrada.assign(N+1,0);
		for(int i = 0 ; i < N ; ++i){
			scanf(" %d",&tam);
			while(tam--){
				scanf(" %d",&v);
				grauentrada[i]++;
				G[v-1].push_back(i);
			}
		}
		printf("%d\n",TS());
	}
	return 0;
}
