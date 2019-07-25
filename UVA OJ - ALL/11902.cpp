#include <stdio.h>
#include <vector>
#include <stack>
#define EST_INICIAL -1
using namespace std;

vector<int> grafo; // grafo armazenado aqui
vector<int> aux; // todos calculados entram aqui
vector<bool> visitado;
stack<int> pilha;

int maxi;
int ver;
int cont ;
void funcao(int vertice)
{
	if(visitado[vertice])
	{
		int a = pilha.size();
		while(!pilha.empty())
		{
			aux[pilha.top()] = a + cont;
			pilha.pop();		
		}
				
		return;
	}
	
	
	cont++;
	visitado[vertice] = true;
	pilha.push(vertice);
	return funcao(grafo[vertice]);
}


int main()
{
	int i,casos,num,u,v;
	scanf(" %d",&casos);
	for(int h = 0 ; h < casos ; h++)
	{
		scanf(" %d",&num);
		
		grafo.assign(num,EST_INICIAL);
		aux.assign(num,0);
		visitado.assign(num,false);		
		
		
		for(i = 0 ; i < num ; i++)
		{
			scanf(" %d %d",&u,&v);
			grafo[u-1] = v-1;	
		}
		
		maxi = 0;
		for(i = 0 ; i < num ; i++)
		{
			if(!visitado[i])
			{
				cont = 0;
				funcao(i);
				
				if(aux[i] > maxi)
				{
					maxi = aux[i];
					ver = i;
				}
			}					
		}	
				
		printf("Case %d: %d\n",h+1,ver+1);
	}
	return 0;
}
