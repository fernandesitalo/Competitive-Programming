#include <stdio.h>
#include <map>

using namespace std;

struct guerra{
	int lem;
	bool time;// azul = true ;; verde = false 
};

int main()
{	

	int qtd,max;
	scanf("%d",&qtd);	
	while(qtd--)
	{
		int verde,aux,azul,campos,i;
		scanf("%d%d%d",&campos,&verde,&azul);
		guerra vet[campos];
			
		map<int,int> v;	
		map<int,int> a;
		map<int,int>::reverse_iterator ve;
		map<int,int>::reverse_iterator az;
		
		for(i = 0 ; i < verde ; i++){
			scanf("%d",&aux);			
			v[aux]++;			
		}
		
		for(i = 0 ; i < azul ; i++){
			scanf("%d",&aux);			
			a[aux]++;			
		}
		
		while(!v.empty() && !a.empty()){
		max = 0;			
		
			for(i = 0 ; i < campos && !v.empty() && !a.empty() ; i++){		
				ve = v.rbegin();
				az = a.rbegin();
				
				if(ve->first != az->first)
				{
					if(ve->first > az->first){					
						vet[max].lem = ve->first - az->first;
						vet[max].time = false;
						max++;
					}
					else{
						vet[max].lem = az->first - ve->first;
						vet[max].time = true;
						max++;			
					}				
				}			
				if(ve->second == 1)
					v.erase(ve->first);
				else
					v[ve->first]--;			
			
				if(az->second == 1)
					a.erase(az->first);
				else
					a[az->first]--;								
			}		
			max--;			
			while(max >= 0){
				
				if(vet[max].time)
					a[vet[max].lem]++;
				else
					v[vet[max].lem]++;		
				max--;
			}
		}
		
		if(a.empty() && v.empty())
		{
				printf("green and blue died\n");
		}
		else
		{
			if(v.empty())
			{
				printf("blue wins\n");
				
				az = a.rbegin();
				while(az != a.rend())
				{
					for(i = 0 ; i < az->second ; i++)
						printf("%d\n",az->first);
					az++;	
				}		
						
			}	
			else
			{
				printf("green wins\n");
				ve = v.rbegin();
				
				while(ve != v.rend())
				{
					for(i = 0 ; i < ve->second ; i++)
						printf("%d\n",ve->first);
						
					ve++;	
				}					
			}	
		}
				
		if(qtd)
				printf("\n");

	
	}
	return 0;	
}
