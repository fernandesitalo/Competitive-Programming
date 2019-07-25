#include <stdio.h>
#include <queue>
#include <list>
#include <map>
using namespace std;

int main()
{
    int i,k,num,tam,aux,dude,caso = 1;
    char opcao[10];
        
    while(scanf(" %d",&num),num)
    {   
		queue<int> vet[1010];
		list<int> sequencia;
		list<int>::iterator iter;
				
		map<int,int> pessoa;
					
        for(i = 0 ; i < num ; i++)
        {      
            for(scanf(" %d",&tam),k = 0 ; k < tam ; k++)          
			{
				scanf(" %d",&aux);
				pessoa[aux] = i;				
			}                                   
        }
        
        printf("Scenario #%d\n",caso++);
        while(scanf("%s",opcao), opcao[0] != 'S')
        {
            if(opcao[0] == 'E')
            {
				scanf(" %d",&dude);				
				aux = pessoa[dude];				
				vet[aux].push(dude);
				
				for(iter = sequencia.begin(); *iter != aux && iter != sequencia.end() ;iter++);
				
				if(iter == sequencia.end())
				{
					sequencia.push_back(aux);
				}
							
            }
            else
            {
				iter = sequencia.begin();	
				
				printf("%d\n",vet[*iter].front());
				vet[*iter].pop();	
				
				if(vet[*iter].empty())
				{
					sequencia.remove(*iter);
				}			
			}
		}		
		printf("\n");
	}	
	return 0;
}
