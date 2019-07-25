#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int main()
{
	char op[13];
	int a,b;
	
	map<int,set<int> > m;
	set<int>::iterator kl;
	map<int,set<int> >::iterator it;
	map<int,int> aux;
	
	while(scanf(" %s",op),op[0] != '#')
	{
		scanf(" %d%d",&a,&b);
		m[b].insert(a);	
		
		aux[a] = b;	
	}
	int tam,i;
	
	for(scanf(" %d",&tam),i = 0 ; i < tam ;)
	{
		it = m.begin();	
		
		kl = m[it->first].begin();
		
		while(kl != m[it->first].end() && i < tam)
		{
			printf("%d\n",*kl);
			//printf(":::::::::: %d      kl = %d\n", aux[*kl],*kl);
			
			m[it->first + aux[*kl]].insert(*kl);
			i++;
			
			kl++;
		}

		m.erase(m.begin());
	}

	return 0;
}

