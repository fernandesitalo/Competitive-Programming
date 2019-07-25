#include <stdio.h>
using namespace std;


int grafo[50][50];
int tam;
void funcao(int x,int y)
{
	int X[] = {x-1,x,x+1,x-1,x+1,x-1,x,x+1}; 
	int Y[] = {y-1,y-1,y-1,y,y,y+1,y+1,y+1};
	
	grafo[x][y] = -1;
	
	for(int i = 0 ; i < 8 ; i++)
	{
		if(X[i] >= 0 && X[i] < tam && Y[i]>=0 && Y[i]<tam && grafo[X[i]][Y[i]] == 1)
			funcao(X[i],Y[i]);
	}	
}




int main()
{

	int i,j;
	char entrada[50];
	int ct = 1;
	
	while(scanf("%d",&tam) != EOF)
	{
		
		for(i = 0 ; i < tam ; i++)
		{
			scanf(" %s",entrada);
			
			for(j = 0 ; j < tam ; j++)
			{
				if(entrada[j] == '1')
					grafo[i][j] = 1;
				else
					grafo[i][j] = 0;			
			}
		}
			
			int tot = 0;
			for(i = 0 ; i < tam ; i++)
			{
				for(j = 0 ; j < tam ; j++)
				{
					if(grafo[i][j] == 1)
					{
						funcao(i,j);
						tot++;				
					}					
				}			
			}
		printf("Image number %d contains %d war eagles.\n",ct++,tot);			
	}
	return 0;
}
