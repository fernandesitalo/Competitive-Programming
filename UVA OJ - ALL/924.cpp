#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define MAX 2501
using namespace std;

vector<vector<int> > grafo(MAX);
vector<int> dist;
vector<bool> vis;

void bfs(int v){
	queue<int> fila;
	fila.push(v);	
	dist[v] = 0;
	vis[v] = true;	
	while(!fila.empty()){
		int top = fila.front();
		fila.pop();		
		
		for(int i = 0 ; i < (int) grafo[top].size() ; i++)
		{
			if(!vis[grafo[top][i]]){
				dist[grafo[top][i]] = dist[top] + 1;
				vis[grafo[top][i]] = true;
				fila.push(grafo[top][i]);
			}		
		}	
	}
}

int main(){
	int i,j,aux,qtd,num;		
	for(scanf("%d",&num), i = 0 ; i < num ; i++)
		for(scanf("%d",&qtd), j = 0 ; j < qtd ; j++)
			scanf("%d",&aux),grafo[i].push_back(aux);
			
	for(scanf("%d",&qtd), i = 0 ; i < qtd ; i++){
		scanf("%d",&aux);			
		dist.assign(num,0);	
		vis.assign(num,false);
		bfs(aux);
		map<int,set<int> > m;		
		
		for(j = 0 ; j < num ; j++)
			if(vis[j])
				m[dist[j]].insert(j);		
	
		int max = 0,dia = 1;				
		for(map<int,set<int> >::iterator it = m.begin() ; it != m.end() ; it++)
			if((int)it->second.size() > max)
				max = it->second.size(),dia = it->first;
		
		if((int)grafo[aux].size() == 0)
			puts("0");
		else
			if(dia == 0) dia = 1;
				printf("%d %d\n",max,dia);
	}			
	return 0;
}
