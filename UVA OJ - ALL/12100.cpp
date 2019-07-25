#include <stdio.h>
#include <map>
#include <list>
using namespace std;

int main()
{
	int num,i,k,pos,aux,qtd;
	
	for(scanf("%d",&num),i = 0 ; i < num ; i++)
	{
		map<int,int> m;
		list<int> l;
		list<int>::iterator it;
		
		for(scanf("%d%d",&qtd,&pos),k = 0 ; k < qtd ; k++)
		{
			scanf("%d",&aux);			
			m[k] = aux;
			l.push_back(k);
		}
		
		int cont = 0;		
					
		int pmaior;
		do
		{	
				
			it = l.begin();
			
			int maior = m[*it];
			pmaior = *it;
			
			it++;
			
			for(;it != l.end() ; it++)
			{
				if(m[*it] > maior)
				{
					pmaior = *it;
					maior = m[*it];
				}
			}	
		
			
			while(l.front() != pmaior)
			{
				l.push_back(l.front());
				l.pop_front();
			}
			
			cont++;
			
			if(pos == l.front())
			{
				break;
			}
			
			l.pop_front();
			

				
		}while(1);
		
		printf("%d\n",cont);
		
		
		}	
	
	return 0;
	
}

