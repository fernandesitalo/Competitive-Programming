#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 100099
using namespace std;

vector<bool> vis(MAX);
vector<int> dis(MAX);
vector<vector<int> >grafo(MAX);

void reset(int tam){
	vis.assign(tam,false);
	dis.assign(tam,0);
	
	for(int i = 0 ; i < tam ; i++)
		grafo[i].clear();
}

int bfs(int inicio,int fim)
{
	queue<int> q;
	q.push(inicio);
	dis[inicio] = 0;
	vis[inicio] = true;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		
		for(int i = 0 ; i < (int)grafo[top].size(); i++){
			if(grafo[top][i] == fim)
				return dis[top];			
			if(!vis[grafo[top][i]]){
				vis[grafo[top][i]] = true;
				dis[grafo[top][i]] = dis[top] + 1;
				q.push(grafo[top][i]);
			}
		}	
	}	
	return 0;
}



int main(){
	
	int i,num,ct,camarada,qtd,aux,inicio,fim,tam,j;
	for(scanf("%d",&num),ct = 1 ; ct <= num ; ct++)
	{		
		scanf(" %d",&tam);
		reset(tam);
		for(i = 0 ; i < tam ; i++)
			for(scanf("%d%d",&camarada,&qtd), j = 0 ; j < qtd ; j++)
				scanf("%d",&aux),grafo[camarada].push_back(aux);	
			
		scanf("%d%d",&inicio,&fim);		
		int r = bfs(inicio,fim);	
		printf("%d %d %d\n",inicio,fim,r);		
		if(ct != num)
			printf("\n");
	}

}
