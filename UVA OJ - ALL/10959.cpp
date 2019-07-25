#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 1000
#define INF 50000000
using namespace std;

vector<vector<int> >grafo(MAX);
vector<int> numgi(MAX);
vector<bool> vis(MAX);

void reset(){
	for(int i = 0 ; i < MAX ; i++)
		grafo[i].clear(),numgi[i] = 0,vis[i] = false;
}

void f(){
	
	queue<int> q;
	q.push(0);
	numgi[0] = 0;
	vis[0] = 0;
	
	while(!q.empty()){
		int top = q.front();
		q.pop();
				
		for(int i = 0 ; i < (int)grafo[top].size() ; i++){
				
			if(!vis[grafo[top][i]]){
				vis[grafo[top][i]] = true;
				numgi[grafo[top][i]] = numgi[top] + 1;
				q.push(grafo[top][i]);						
			}	
		}
				
	}
}





int main(){
	
	int num,i,u,v,p,d;
	scanf("%d",&num);
	while(num--){
		reset();
		
		for(scanf("%d%d",&p,&d),i=0;i < d ; i++){
			scanf("%d%d",&u,&v);			
			grafo[u].push_back(v);	
			grafo[v].push_back(u);								
		}
		
		
		f();
		
		for(i = 1 ; i < p ; i++){
			printf("%d\n",numgi[i]);		
		}
		
		if(num)puts("");
		
	}
	
	
	
	
}
