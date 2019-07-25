#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int num,tam,i,k,aux;
	
	for(scanf(" %d",&num),i = 0 ; i < num ; i++)
	{
		vector<int> v;
		for(scanf(" %d",&tam),k = 0 ; k < tam ; k++)
		{
			v.push_back(k+1);
		}
		
		for( k = 0 ; k < tam ; k++)
		{
			scanf("%d",&aux);
			
			printf("%d",v[aux]);
			
			v.erase(v.begin()+aux);
			
			if(!v.empty())
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;	
}
