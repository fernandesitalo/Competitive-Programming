#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<vector<int> > grafo;
vector<int> grau;
vector<bool> removido;

vector<int> ts;


void reset(int &n){
	vector<int> a;
	grafo.assign(n,a);
	grau.assign(n,0);
	removido.assign(n,false);
	ts.clear();	
}


void TS(){
	
	queue<int> q;
	
	for(int p = 0 ; p < (int)grafo.size() ; p++){
		if(grau[p] == 0){
			q.push(p);
		}
	}
	
	while(!q.empty()){
		int top = q.front();
		q.pop();
		
		ts.push_back(top+1);
		removido[top] = true;
		
		for (int k = 0 ; k < (int)grafo[top].size(); ++k){			
			int v = grafo[top][k];		   
			if (!removido[v]  && --grau[v] == 0)
				q.push(v);
		}		
	}
}

int main(){
	int n,m,u,v;
	
	while(scanf("%d%d",&n,&m) , m||n){
		reset(n);
		
		while(m--){
			scanf("%d%d",&u,&v),grafo[u-1].push_back(v-1);
			grau[v-1]++;
		}
		
		TS();
		
		printf("%d",ts[0]);
		for(int i = 1 ; i < n ; i++){
			printf(" %d",ts[i]);	
		}printf("\n");
	}
	return 0;
}
