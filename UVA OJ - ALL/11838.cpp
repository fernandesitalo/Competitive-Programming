#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
#define UNVISITED -1001
using namespace std;

typedef long long ll;
typedef pair<int, int>	ii;
typedef vector<ii>	vii;
typedef vector<int>	vi;


vi dfs_num, dfs_low, visited;

int numSCC;
int descoberta;

vector<vi> AdjList;


void tarjanSCC(int u) {	
	dfs_low[u] = dfs_num[u] = descoberta++;
		
	visited[u] = 1;	
	
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		int v = AdjList[u][j];
		
		if(dfs_num[v] == UNVISITED)
			tarjanSCC(v);
	
		if(visited[v])		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
	}	
	
	if (dfs_low[u] == dfs_num[u]) ++numSCC;	
}


int main(){
	
	int n,m,d,u,v;	
	
	while(scanf("%d%d",&n,&m),m||n){
		dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); visited.assign(n, 0);
		descoberta = 0;
		numSCC = 0;
		
		AdjList.clear();
		AdjList.resize(n+1);
		
		while(m--){
			scanf("%d%d%d",&u,&v,&d);	
			u--;
			v--;		
			AdjList[u].push_back(v);
			if(d == 2)
			AdjList[v].push_back(u);
		}
		
		
		tarjanSCC(u);
		bool alface = true;
		
		if(numSCC == 1){
			for(int i = 0 ; i < n ; i++){
				if(dfs_num[i] == UNVISITED){
					alface = false;
					break;					
				}
			}
			
			if(alface == true) puts("1");
			else puts("0");
				
		}
		else{			
			puts("0");
		}
	}
	return 0;
}
