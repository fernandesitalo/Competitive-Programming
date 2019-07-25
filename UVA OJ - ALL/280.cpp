#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{	
	int vertice,cont,i,u,v,num;
	while(scanf("%d",&num),num)
	{
		vector<vector<int> > grafo(num+1);
		
		while(scanf("%d",&v),v)
			while(scanf("%d",&u),u)	
				grafo[v-1].push_back(u-1);		
		
		scanf(" %d",&u);
		while(u--)
		{						
			vector<bool> VISITADO(num,false);
			queue<int> lista;		
		
			scanf(" %d",&v),lista.push(--v);		
			cont = 0;
			
			while(!lista.empty())
			{	
				vertice = lista.front();
				lista.pop();
				
				for(i = 0 ; i < (int)grafo[vertice].size() ; i++)
				{
					if(!VISITADO[grafo[vertice][i]]) // nao pode ter sido visitado ainda
					{
						lista.push(grafo[vertice][i]);
						VISITADO[grafo[vertice][i]] = true;
						cont++;
					}
				}			
			}
						
			printf("%d",num - cont);			
			for(v = 0 ; v < num ; v++)
				if(!VISITADO[v])
					printf(" %d",v+1);		
			puts("");
		}
	}
	return 0;
}
