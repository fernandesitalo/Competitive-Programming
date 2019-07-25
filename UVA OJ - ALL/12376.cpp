#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int casos,i,n,m,aux,max;
	scanf("%d",&casos);
	
	for(int h = 0 ; h < casos ; h++)
	{
		scanf(" %d %d",&n,&m);
		
		vector <vector<int> > grafo(n);
		vector<int> conteudo(n);
		int proxNO = 0; // sempre;
		
		
		for(i = 0 ; i < n ; i++)
			scanf("%d",&conteudo[i]);
		int u,v;
		for(i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&u,&v);
			grafo[u].push_back(v);			
		}
		
		int tot = 0;
		while((int)grafo[proxNO].size() > 0)
		{
			max = 0;
			for( i = 0 ; i < (int) grafo[proxNO].size(); i++)
				if(conteudo[grafo[proxNO][i]] > max)
				{
					max = conteudo[grafo[proxNO][i]];
					aux = grafo[proxNO][i];
				}
									
			tot += max;
			proxNO = aux;
		}
		
		printf("Case %d: %d %d\n",h+1,tot,proxNO);	
	}
	
	return 0;
}
