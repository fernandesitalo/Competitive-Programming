#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int n,i,k,aux,qtd;
	while(scanf("%d",&n), n)
	{
		map<int,int> m;
		map<int,int>::reverse_iterator it;		
		
		long long premio = 0;
		
		for(i = 0 ; i < n ; i++)
		{
			for(scanf("%d",&qtd), k = 0 ; k < qtd ; k++)
			{
				scanf("%d",&aux);
				m[aux]++;	
			}			
			it = m.rbegin();			
			
			premio += it->first - m.begin()->first;
			
			if(it->second == 1)
				m.erase(it->first);
			else
				m[it->first]--;	
				
			if(m.begin()->second == 1)
				m.erase(m.begin());
			else
				m[m.begin()->first]--;			
		}	
		printf("%lld\n",premio);
	}
	return 0;

}
