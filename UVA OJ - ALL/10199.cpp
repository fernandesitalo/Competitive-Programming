#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include<iostream>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vi> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int descoberta, dfsRoot, rootChildren;

// quantidade de cameras que existem no caso de teste


map<string,int > indice;
map<int,string > indice2;


void Search_Vertex(int u) {
  dfs_low[u] = dfs_num[u] = descoberta++;
 
 
  for(int j=0; j<(int)G[u].size(); j++) {
    int v = G[u][j];
    
    if(dfs_num[v] == DFS_WHITE) {
      dfs_parent[v] = u;
      
      if(u == dfsRoot)rootChildren++;

      Search_Vertex(v);

      if(dfs_low[v] >= dfs_num[u])articulation_vertex[u] = true; // caso onde existe Vertice de corte      
      
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      
    } else if(v != dfs_parent[u])
		dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void reset(int v){
  descoberta = 0;
  dfs_num.assign(v, DFS_WHITE);
  dfs_low.assign(v, 0);
  dfs_parent.assign(v, 0);
  vi a; G.assign(v,a);
  articulation_vertex.assign(v, 0);
  indice.clear();
  indice2.clear();
}



int main() {
  int n,m;
  int cont;
  int ct = 1;
  string aux,aux2;
  bool alface = false;
  
	while(scanf("%d",&n),n){
		reset(n+5);
		
		if(alface)puts("");
		alface = true;
		
		cont = 0;
		while(cont < n){
			cin>>aux;
			indice2[cont] = aux;
			indice[aux] = cont;
			cont++;		
		}
		
		scanf("%d",&m);
		
		while(m--){
			cin>>aux>>aux2;
			G[indice[aux]].push_back(indice[aux2]);
			G[indice[aux2]].push_back(indice[aux]);			
		}
		
		
		for(int i=0; i<n; i++) {
			if(dfs_num[i] == DFS_WHITE) {
			  dfsRoot = i;
			  rootChildren = 0;
			  Search_Vertex(i);
			  articulation_vertex[dfsRoot] = (rootChildren > 1);			  
			}
		}    
		
		
		
		cont = 0;
		set<string> s;
		for(int i = 0 ; i < n ; ++i)if(articulation_vertex[i]) s.insert(indice2[i]),cont++;
		
		printf("City map #%d: %d camera(s) found\n",ct++,cont);
		
		for(set<string>::iterator it = s.begin() ; it != s.end() ; ++it) {
			cout<<*it<<endl;		  
		}
}
  
  return 0;
}
