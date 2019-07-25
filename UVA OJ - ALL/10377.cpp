//ACCEPTED
#include <stdio.h>
using namespace std;

int main()
{
	int casos,linha,coluna,i,j,x,y;
	char aux[100];
	bool flag;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf(" %d %d",&linha,&coluna);
		char lab[linha+1][coluna+1];
		
		for(i = 0 ; i < linha ; i++)
		{
			scanf(" %[^\n]",aux);			
			for(j = 0 ; aux[j] != '\0' ; j++)
				lab[i][j] = aux[j];	
		}
		
		
		scanf(" %d %d",&y,&x);
		x--; y--;
		char o = 'N';
		
		flag = false;
		while(1)
		{		
			scanf("%s",aux);		
			for(i = 0 ; aux[i] != '\0' ; i++)
			{
				
				if(aux[i] == 'L'){				
					if(o == 'N') o = 'W';
					else if(o == 'W') o = 'S';
					else if(o == 'S') o = 'E';
					else o = 'N';					
					continue;
					
				}
				
				if(aux[i] == 'R'){					
					if(o == 'N') o = 'E';
					else if(o == 'E') o = 'S';
					else if(o == 'S') o = 'W';
					else o = 'N';				
					continue;
				}
			
			
				if(aux[i] == 'F'){
										
					if(o == 'N' && y-1 < linha && lab[y-1][x] != '*')y--;				
					else if(o == 'E' && x+1 < coluna && lab[y][x+1] != '*')x++;
					else if(o == 'S'&& y+1 > -1 && lab[y+1][x] != '*')y++;
					else if(o == 'W' && x-1 > -1 && lab[y][x-1] != '*')x--;								
					continue;
				}
				
				flag = true;
				break;		
			}
			
			if(flag)
				break;
		}
		
		printf("%d %d %c\n",y+1,x+1,o);
				
		if(casos != 0)
			printf("\n");
	}
	
	return 0;
}
