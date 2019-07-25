#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int i,h,casos;
	char entrada[100];
	scanf(" %d",&casos);	
	for(h = 0 ; h < casos ; h++)
	{
		vector<vector<int> > grafo(26);
		stack<int> pilha;
		
		scanf(" %s",entrada);
		pilha.push(entrada[0] - 'A');
		
		for(i = 1 ; entrada[i] != '\0' ; i++)
		{			
			if((entrada[i]-'A') == pilha.top())
			{
				int aux = pilha.top();
				pilha.pop();
				if(!pilha.empty())				
					grafo[aux].push_back(pilha.top());	
				continue;			
			}
			grafo[pilha.top()].push_back(entrada[i]- 'A');		
			pilha.push(entrada[i] - 'A');

		}
		printf("Case %d\n",h+1);
		
		for(i = 0 ; i < 26 ; i++)
			if(grafo[i].size() > 0)
				printf("%c = %d\n",i+65,(int)grafo[i].size());		
	}
	return 0;
}
