#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int num,i,entrada;
	
	stack<int>estacao;
	int vet[1010];
	
	while(scanf(" %d",&num),num)
	{
		while(scanf(" %d",&vet[0]),vet[0]) //leitura de como a saida deve estar
		{		
			for( i = 1 ; i < num ; i++)
			{				
				scanf(" %d",&vet[i]);
			}
			i = 0;
			
			
			entrada = 1;
			
			
			while(entrada <= num)
			{					
				
				estacao.push(entrada);
				entrada++;
				
				for(;i < num   && !estacao.empty() && estacao.top() == vet[i]; i++)
				{
					//cout <<":::::"<<estacao.top()<<endl;
					estacao.pop();
				}		 
			}
			
				
			if(estacao.empty())
				printf("Yes\n");
			else
			{
				printf("No\n");
				while(!estacao.empty())
				{
					estacao.pop();
				}	
				
			}
				
			


		}
		printf("\n");

	}
	

}
