#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int, int>	ii;
typedef vector<ii>	vii;
typedef vector<int>	vi;


vi dfs_num, dfs_low , visited,dfs_parent; // global variables
int descoberta;

vector<set<int> > AdjList;

set<pair<int,int> > resp;
void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = descoberta++; 
	
	for(set<int>::iterator it = AdjList[u].begin() ; it != AdjList[u].end() ; it++){
		int v = *it;
		
		
		if (dfs_num[v] == -1){	
			dfs_parent[v] = u;	
			
			articulationPointAndBridge(v);				
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
			
			if (dfs_low[v] > dfs_num[u]){					
				resp.insert(make_pair(u,v));
				resp.insert(make_pair(v,u));		
									
			}	
			else if(resp.find(make_pair(v,u)) == resp.end()){
				resp.insert(make_pair(u,v));
			}
		}
		else 
			if (v != dfs_parent[u]) {
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
				
				if(resp.find(make_pair(v,u)) == resp.end()){
					resp.insert(make_pair(u,v));
				}				
			}
	} 
}

void reset(int V){
	dfs_num.assign(V, -1); dfs_low.assign(V, 0); visited.assign(V, 0);
	dfs_parent.assign(V, 0);	
	set<int> a;AdjList.assign(V,a);
	resp.clear();
}

int main(){
	
	int m,n,u,v;
	int caso = 1;
	while(scanf("%d%d",&n,&m),m|n){
		reset(n+2);
		printf("%d\n\n",caso++);
		while(m--){
			scanf("%d%d",&u,&v);
			AdjList[u].insert(v);
			AdjList[v].insert(u);			
		}
			
	descoberta = 0;	
			
		for (int i = 1; i <= n; i++){
			if (dfs_num[i] == -1) {
				articulationPointAndBridge(i);
			}
		}
		
			for(set<ii>::iterator it = resp.begin() ; it != resp.end() ; it++){
				printf("%d %d\n",it->first,it->second);
			}
			puts("#");
		
	}
	return 0;
}
