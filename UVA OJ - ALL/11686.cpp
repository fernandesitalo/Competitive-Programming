#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;


vector<vector<int> > graf;
vector<int> grau;
vector<bool> removido;
vector<int> ordem;


void reset(int n){	
	
    grau.assign(n+1,0);
    removido.assign(n+1, false);    
    vector<int> a;
    graf.assign(n+1,a);
    
    ordem.clear();	
}


void ts(){
	
	queue<int> q;
	for(int i = 1 ; i < (int)grau.size() ; i++){
		if(!grau[i]){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int w = q.front();
		q.pop();	
		
		ordem.push_back(w);
		removido[w] = true;		
		
		for (int k = 0 ; k < (int)graf[w].size(); ++k){			
			int v = graf[w][k];		   
			if (!removido[v]  && --grau[v] == 0)
				q.push(v);
		}
	}	
}
int main(){	
	int n,m;
	int u,v;
	while(scanf("%d%d",&n,&m),n||m){
		reset(n);
		while(m--){
			scanf("%d%d",&u,&v);
			
			graf[u].push_back(v);
			grau[v]++;
		}		
		ts();		
		if((int)ordem.size() == n){
			for(int r = 0 ; r < (int)ordem.size() ; ++r){
				printf("%d\n",ordem[r]);
			}		
		}
		else puts("IMPOSSIBLE");
	}
	return 0;
}
