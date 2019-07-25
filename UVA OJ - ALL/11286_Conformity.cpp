#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int main()
{	
	int aux,num,i,k;
	while(scanf("%d",&num),num){
		map<set<int> , int > m;
		map<set<int> , int >::iterator it;
		
		for(i = 0 ; i < num ; i++)
		{
			set<int> p;
			for( k = 0 ; k < 5 ; k++)
			{
				scanf("%d",&aux);
				p.insert(aux);
			}
			if(m.find(p) == m.end())
			{
				m[p] = 1;
			}
			else			
				m[p]+= 1;
		}
		
		it = m.begin();
		int qtd = 0;
		int x = 0;
		
		while(it != m.end())
		{
			if(it->second >= x)
			{
				if(it->second == x)
					qtd += it->second;
				else
				{
					x = it->second;	
					qtd = x;
				}
			}			
			it++;
		}
		printf("%d\n",qtd);
	}

	return 0;
}
