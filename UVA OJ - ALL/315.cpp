#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int>	ii;
typedef vector<ii>	vii;
typedef vector<int>	vi;


vi dfs_num, dfs_low , visited,articulation_vertex,dfs_parent; // global variables
int numSCC,descoberta;
int dfsRoot;
int rootChildren;


vector<vi> AdjList;


void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = descoberta++;
	
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		
		if (dfs_num[v] == -1/*UNVISITED*/) {
				
			dfs_parent[v] = u;			
			
			if (u == dfsRoot) rootChildren++;		

			articulationPointAndBridge(v);			
			
			if (dfs_low[v] >= dfs_num[u])			
				articulation_vertex[u] = 1;	
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
	} 
}


void reset(int n){
	dfs_num.assign(n,-1);
	dfs_low.assign(n,0);
	visited.assign(n,0);
	articulation_vertex.assign(n,0);
	dfs_parent.assign(n,0);
	vi a;
	AdjList.assign(n,a);	
}

int main(void){	
	int n,v,u;
	char buff;
	
	while(scanf(" %d",&n),n){
		reset(n+3);
		descoberta = 0;
		
		while(scanf(" %d",&v),v){
			do{
				scanf(" %d%c",&u,&buff);				
				AdjList[u].push_back(v);
				AdjList[v].push_back(u);				
			}while(buff != '\n');	
		}
	
		

		for (int i = 1; i <= n; i++){
			if (dfs_num[i] == -1/*UNVISITED*/) {
				dfsRoot = i;
				rootChildren = 0; 
				articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);  // special case
			}
		}
		int Vertice_De_Corte = 0;
		
		for(int i = 1 ; i <= n ; i++){
			if(articulation_vertex[i] == 1) ++Vertice_De_Corte;
		}
		
		printf("%d\n",Vertice_De_Corte);	
	}	
	return 0;
}
