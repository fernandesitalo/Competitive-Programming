#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
using namespace std;

typedef vector<bool>	vb;
typedef vector<int>		vi;




vb visited;
vector<vi> AdjList;
list<int> OrdemVertices;

void DFS(int u) {	
	visited[u] = true;		
	for (int j = 0; j < (int)AdjList[u].size(); ++j){
		if (visited[ AdjList[u][j] ] == false) 
			DFS( AdjList[u][j] );	
	}		
}


void Ordem(int e){
	visited[e] = true;	
	for (int j = 0; j < (int)AdjList[e].size(); ++j){
		if(visited[ AdjList[e][j] ] == false)
			Ordem( AdjList[e][j] );
	}
	OrdemVertices.push_front(e);	
}





void reset(int V){ 
	visited.assign(V, false);	
	OrdemVertices.clear();
	vi a;AdjList.assign(V,a);	
}



int main(void){
	
	int t,u,v,n,m;
	int ct = 1;
	char enter;
	bool flag = false;
	scanf("%d",&t);
	while(t--){
		if(flag)scanf("%c",&enter),flag = true;
		scanf("%d%d",&n,&m);
		
		reset(n+3);
		
		while(m--){
			scanf("%d%d",&u,&v);
			AdjList[u].push_back(v);
		}
		
		for (int i = 1; i <= n; i++){
			if (visited[i] == false){
				Ordem(i);
			}
		}
		visited.assign(n+2, false);
		
		int cont = 0;
		for(list<int>::iterator it = OrdemVertices.begin() ; it != OrdemVertices.end() ; ++it){
			if(visited[*it] == false){
				DFS(*it);
				cont++;
			}
		}
		
		printf("Case %d: %d\n",ct++,cont);				
	}
	return 0;	
}
