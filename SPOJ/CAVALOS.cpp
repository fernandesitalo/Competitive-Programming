#include <stdio.h>

int main(void){
	
	int s,m,n,aux;
	
	scanf("%d %d",&m,&n);
		if(n > m)
		{ // m sera o maior de qualquer forma 
			aux = m;
			m = n;
			n = aux;
		}
	
	if(m > 2 && n > 2) // caso de um tabuleiro normal , com m e n maiores que 2 
	{		
		s = (m/2)*n + (m%2)*(n - (n/2));
	}	
	else
	{		
		if(m == 2 || n == 2)// caso de m ou n ser igual a 2 
		{
			if(m == 2 && n == 2)  // caso unico 2x2
			{
				s = m*n;
			}
			else
			{					
				s = (m / 4) * 4;  
				
			
				if((m%4) <= 2)
				{
					s += (m%4) * n;
				}
				if((m%4) == 3)
				{
					s += 4;
				}
			}		
		}		
		else{ // ultimo caso , onde m ou n e igual a 1
			s = m*n;
		}	
	}
	
	printf("%d",s);
	
	
	
	
	
	
}
