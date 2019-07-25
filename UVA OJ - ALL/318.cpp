#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#define MAX 9999999
using namespace std;


int main(){
	
	int tam,num,v1,v2,i,j;
	int casos = 1;
	float cust;
	while(scanf("%d%d",&tam,&num), num || tam)
	{
		vector<vector<pair<int,int> > > grafo(tam+2);
		
		while(num--)
		{
			scanf("%d%d%f",&v1,&v2,&cust);
			grafo[v1].push_back(make_pair(v2,cust));	
			grafo[v2].push_back(make_pair(v1,cust));
		}

		vector<int> dist(tam+3,MAX);		
		vector<bool> vis(tam+3,false);  //Expandidos		
		priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > fila;		
		fila.push(make_pair(1,0)); // no de origem, onde vamos descobrir o caminho minimo
		dist[1] = 0;
/********************************************************************************************/

		while(!fila.empty())
		{
			pair<int,int> p = fila.top();
			int u = p.first;
			int custo_u = p.second;
		//	printf("v = %d   c = %d\n",u,custo_u);
			
			fila.pop();	
			
			if(!vis[u])
				for(vis[u] = true,i = 0 ; i < (int)grafo[u].size() ; i++)// percore os vertices adjacentes a u
				{
					int adj = grafo[u][i].first; // vertice adjacente
					cust = grafo[u][i].second;	
									
					if(dist[adj] > (dist[u]+cust))
					{
						dist[adj] = dist[u]+cust;					
						fila.push(make_pair(adj,cust + custo_u));				
					}
				}				
		}
		
/******************************************************************************************/		
		double maior = 0;
		int v = 1,k = -1;
		
		for(i = 1 ; i <= tam ; i++)
		{
			if(dist[i] != MAX && dist[i] > maior) // a e o maior caminho minimo
			{
				maior = dist[i];
				v = i;
			}
		}
			
		k = -1;
			
			
			
			
		for(i = 1 ; i <= tam ; i++)
		{
			for(j = 0 ; j < (int) grafo[i].size() ; j++)
			{
				int destino = grafo[i][j].first;
				
				v1 = dist[i];
				v2 = dist[destino];
				
				if(v1 < v2){
					int aux = v2;
					v2 = v1;
					v1 = aux;
				}
				
				float temp = v1 + ((grafo[i][j].second - (v1 - v2))/2.0);
				
				if((v1 != MAX) && (v2 != MAX) && temp > maior)
				{
					if(i < destino)
					{
						v = i;
						k = destino;
					}
					else
						 {
						  	k = destino;
						 }			

					maior = temp;
				}
				
			}	
		}	
		
		
		//printf("%d      %d       %f\n",v,k,maior);
		
		
		printf("System #%d\n",casos++);
		
		if(k == -1)
		{
			printf("The last domino falls after %.1f seconds, at key domino %d.\n\n",maior,v);
			
		}
		else
			printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n",maior,v,k);
	
		
	}
	return 0;
}

