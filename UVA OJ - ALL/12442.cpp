#include <stdio.h>
#include <vector>
using namespace std;

vector<int> grafo;
vector<bool> global(50000,false);
vector<bool> visitado;
int cont;

int funcao(int vertice)
{
	if(visitado[vertice])
		return cont;		
	
	global[vertice] = true;
	visitado[vertice] = true;
	cont++;
	return funcao(grafo[vertice]);
}


int main()
{
	int casos,i,k,u,v,num;
	for(scanf("%d",&casos),i = 1 ; i <= casos ; i++)
	{	
		scanf("%d",&num);
		
		grafo.assign(num,-1);
		visitado.assign(num,-1);
		global.assign(num,false);
		
		for(k = 0; k < num ; k++)
			scanf("%d%d",&u,&v),grafo[u-1] = v-1;
		
		int ver;
		int max = 0;
		
		for(k = 0 ; k < num ; k++)
		{
			if(!global[k])
			{				
				visitado.assign(num,false);	
				cont = 0;			
				int tam = funcao(k);				
				if(tam > max){
					max = tam;
					ver = k+1;
				}				
			}		
		}	
		printf("Case %d: %d\n",i,ver);
	} 
	

	return 0;
}
