// ALGORITMO DE DIJKTRA - CAMINHO MINIMO
/*
5
7
0 1 1
0 3 3
0 4 10
1 2 5
2 4 1
3 2 2
3 4 6
* */
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#define MAX 99999999
using namespace std;

int main(){
	
	// pair ->"first" e o vertice destino
	// pair ->"second" e o custo a esse vertice destino
	
	int tam,num,v1,v2,cust,i;
	scanf("%d",&tam);
	vector<vector<pair<int,int> > > grafo(tam);/// antes fazer a leitura do tamanho maximo do grafo(tam)
	
	scanf("%d",&num);
	
	while(num--)
	{
		/// adicionar uma aresta de v1 a v2
		scanf("%d%d%d",&v1,&v2,&cust);
		grafo[v1].push_back(make_pair(v2,cust));	
		grafo[v2].push_back(make_pair(v1,cust));
	}
	
	/// DISJKTRA
	vector<int> dist(tam,MAX);
	dist[0] = 0;
	vector<bool> vis(tam,false);//Expandidos
	
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > fila;
	fila.push(make_pair(0,0)); // no de origem, onde vamos descobrir o caminho minimo
	
	while(!fila.empty())
	{
		pair<int,int> p = fila.top();
		int u = p.first;
		fila.pop();	
		
		if(!vis[u])// verifica se o vertice nao foi expandido
		{
			vis[u] = true;		
			for(i = 0 ; i < (int)grafo[u].size() ; i++)// percore os vertices adjacentes a u
			{
				//obtem o vertice adjacente e o custo da aresta
				int adj = grafo[u][i].first;
				int custo = grafo[u][i].second;
				
				if(dist[adj] > (dist[u]+custo))//relaxamento
				{
					dist[adj] = dist[u]+custo;
					fila.push(make_pair(dist[adj],adj));				
				}
			}	
		}
		
	}
	
	// ao final deste while o vector dist guarda o resultado deste algoritmo

	
	for(i = 0 ; i < tam ; i++)
	{
		printf("dis[%d] = %d\n",i,dist[i]);		
	}
	
	return 0;
}
