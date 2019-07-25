#include <stdio.h>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector< vector<int> > grafo(26);
set<int> visitados;
set<int> vertices;
stack<int> pilha;

int cont;

void funcao(int x) // X E O VERTICE
{
	if(pilha.empty())	
		pilha.push(x);
	else if(pilha.top() != x)
			pilha.push(x);	
	
	visitados.insert(x);
	cont++;
	
	x = pilha.top();
	while(!grafo[x].empty())
	{
		int prox = grafo[x].back();
		grafo[x].pop_back();
		
		if(visitados.find(prox) == visitados.end())
			return funcao(prox);
	}	
	
	pilha.pop();	
	if(pilha.empty())
		return;		
	return funcao(pilha.top());	
}

int main()
{
	int num;
	char aresta[60];
	scanf("%d",&num);
	while(num--)
	{		
		visitados.clear();
		grafo.clear();
		vertices.clear();
		while(scanf(" %s",aresta),aresta[0] != '*') //montando o grafo com a estrutura VECTOR DE VECTOR	
		{
			grafo[aresta[1]-'A'].push_back(aresta[3]-'A');
			grafo[aresta[3]-'A'].push_back(aresta[1]-'A');		
		}
		scanf(" %s",aresta);
		
		for(int i = 0 ; aresta[i] != '\0' ; i++) // montando um set com todos os vertices que pertencem ao grafo
			vertices.insert(aresta[i] - 'A');		
		
		vertices.erase(',' - 'A');	
	
		int arvores = 0, isolados = 0;		
		for(int i = 0 ; i < 26 ; i++)
		{
			if(vertices.find(i) != vertices.end() && visitados.find(i) == visitados.end())	
			{	
				cont = 0;		
				funcao(i);
				//printf("\noi\n");				
				if(cont > 1)
					arvores++;
				else if(cont == 1)
						isolados++;				
			}
		}	
		printf("There are %d tree(s) and %d acorn(s).\n",arvores,isolados);

/*		int i,k;
		for(i = 0 ; i < 26 ; i++)
		{
				for(k = 0 ; k < grafo[i].size() ; k++)
					printf("-------> %d\n",grafo[i][k]);
			
				printf("-\n");			
		}
*/ 
	}
	return 0;
}



