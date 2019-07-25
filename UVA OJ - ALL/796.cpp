#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef set<int> si;
#define DFS_WHITE -1

vector<si> G;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
int dfsNumberCounter, dfsRoot, rootChildren;
set<ii>out;

void articulationPointAndBridge(int u) {
	
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  
  for(si::iterator it = G[u].begin() ; it != G[u].end() ; it++){
    int v = *it;
    
    if(dfs_num[v] == DFS_WHITE) {
      dfs_parent[v] = u;
      
	if(u == dfsRoot)rootChildren++;

	articulationPointAndBridge(v);
	
	
	if(dfs_low[v] > dfs_num[u]){
		int a = min(u,v);
		int b = max(u,v);		  
		out.insert(make_pair(a,b));	
	}
	
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      
    } else if(v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}


void reset(int v){
  dfsNumberCounter = 0;
  dfs_num.assign(v, DFS_WHITE);
  dfs_low.assign(v, 0);
  dfs_parent.assign(v, 0);

  
  out.clear();
  si a; G.assign(v,a);		
	
}

int main() {
	int n;
	int u,v,qtd,i;
	char buf;
	
	
	
	while(scanf(" %d",&n)!= EOF){
		reset(n+3);
		
		for(int h = 0 ; h < n ; ++h){
			scanf(" %d",&u);	
		
			for(scanf(" %c %d %c",&buf,&qtd,&buf),i = 0 ; i < qtd ; i++){
				scanf(" %d",&v);
				G[u].insert(v);
				G[v].insert(u);				
			} 
		}		
		
		//PERCORRER O GRAFO PROCURANDO PONTES
		  for(i=0; i < n; i++) {
				if(dfs_num[i] == DFS_WHITE) {
					  dfsRoot = i;
					  rootChildren = 0;
					  articulationPointAndBridge(i);
				}
		  }    
			
			printf("%d critical links\n",(int)out.size());
			for(set<ii>::iterator it = out.begin(); it != out.end() ; ++it){
				printf("%d - %d\n",it->first,it->second);
			}		
			puts("");
	}  
	  
	

  
  return 0;
}
