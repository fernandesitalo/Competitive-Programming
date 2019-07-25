#include <stdio.h>
#include <map>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n && m)
	{	
		n += m;
		map<int,int> cd;
		
		
		int cont = 0;
		
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&m);
			if(cd[m] == m)			
				cont++;
			
			cd[m] = m;
		}		
		printf("%d\n",cont);
	}
	return 0;
}
