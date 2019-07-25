#include <stdio.h>
#include <map>
using namespace std;

int main()
{	
	int i,k,aux,cases,qtd;
	for(scanf("%d",&cases), i = 0 ; i < cases ; i++){
		map<int,int> m;
		int max = 0;
		int cont = 0;
		int inicio = 0;	
		
		for(scanf("%d",&qtd), k = 1 ; k <= qtd ; k++){
						
			scanf("%d",&aux);		
			if(m.find(aux) != m.end()){				
				
				if(m[aux] >= inicio){					
					if(cont > max)
						max = cont;
						
					inicio = m[aux] + 1;
					cont = k - inicio;
				}		
			}	
			cont++;	
			m[aux] = k;		
		}
		
		if(cont > max)
			max = cont;
		printf("%d\n",max);
	}
}
