#include <stdio.h>
using namespace std;

int main()
{
	
	int i,j;
	int linha,coluna,c,l,cf,lf;
	
	int casos = 1;
	
	while(scanf("%d%d%d%d%d%d",&linha,&coluna,&l,&c,&lf,&cf),linha||coluna||c||l||cf||lf)
	{
		int lab[15][15];			
		int imp[15][15] = {0};
		
		for(i = 1 ; i <= linha ; i++)
			for(j = 1 ; j <= coluna ; j++)
				scanf("%d",&lab[i][j]);		

		imp[l][c] = 1;// posicao inicial
		int cont = 2;
		
		while(c != cf || l != lf)
		{	
	
	
/*		for(i = 1; i <= linha ; i++)
		{
				for(j =1 ; j <= coluna ; j++)
				printf("%d   ",imp[i][j]);
				printf("\n");
		}printf("\n\n");
		
*/	

			// MAIOR QUE 0 E O CAMINHO
			// IGUAL A -1 JA FOI VISITADA...
			
			if(c-1 > 0 && imp[l][c-1] == 0 && lab[l][c-1] != 1 && lab[l][c-1] != 3) // OESTE
			{
				imp[l][--c] = cont++;
				continue;	
			}
			
			if(l-1 > 0 && imp[l-1][c] == 0 && lab[l-1][c] != 2 && lab[l-1][c] != 3)  //NORTE
			{
				imp[--l][c] = cont++;
				continue;
			}	
			
			if(c+1 <= coluna && imp[l][c+1] == 0 && lab[l][c] != 1 && lab[l][c] != 3 )//LESTE
			{
				imp[l][++c] = cont++;
				continue;
			}	
			
			if(l+1 <= linha && imp[l+1][c] == 0 && lab[l][c] != 3 && lab[l][c] != 2)  //SUL
			{
				
				imp[++l][c] = cont++;
				continue;
			}
			
			imp[l][c] = -1;
			
			cont--;
			
		//	printf("imp .. %d   cont ... %d\n",imp[l][c-1],cont-1);
			if( c-1 > 0 && imp[l][c-1] == cont-1 && lab[l][c-1] != 1 && lab[l][c-1] != 3) // visitou tudo....
			{
				c--;
				continue;				
			}
		//	printf("imp .. %d   cont ... %d\n",imp[l-1][c],cont-1);
			if( l-1 > 0 && imp[l-1][c] == cont-1 && lab[l-1][c] != 2 && lab[l-1][c] != 3) // visitou tudo....
			{
				l--;
				continue;				
			}
			
		//	printf("imp .. %d   cont ... %d\n",imp[l][c+1],cont-1);
			if( c+1 <= coluna && imp[l][c+1] == cont-1 && lab[l][c] != 1 && lab[l][c] != 3) // visitou tudo....
			{
				c++;
				continue;				
			}
			
		//	printf("imp .. %d   cont ... %d\n",imp[l+1][c],cont-1);
			if(l+1 <= linha && imp[l+1][c] == cont-1 && lab[l][c] != 3 && lab[l][c] != 2) // visitou tudo....
			{
				l++;
				continue;				
			}



			
			break;
			
			
		}
	
	
	
	
	
	
	
	
	
	
		printf("Maze %d\n\n", casos++);
		
		for(printf("+"),j = 1 ; j <= coluna ; j++)
			printf("---+");
		printf("\n");
		
		for(i = 1 ; i <= linha ; i++)
		{
			
			for(printf("|"),j = 1 ; j <= coluna ; j++)
			{
				if(imp[i][j] == -1) 
					printf("???");
				else
					if(imp[i][j] == 0)
						printf("   ");
					else				
						printf("%3.d",imp[i][j]);
				if(lab[i][j] == 1 || lab[i][j] == 3)
					printf("|");
				else
					if(j != coluna)
						printf(" ");
			}
				
			if(lab[i][j-1] != 1 && lab[i][j-1] != 3)
				printf("|");
			printf("\n");
		
		if(i != linha)	
		{
			for(printf("+"),j = 1 ; j <= coluna ; j++)
			{
				if(lab[i][j] == 2 || lab[i][j] == 3)
					printf("---");
				else
					printf("   ");
				
				printf("+");	
			}
			printf("\n");
		}			
		}
		
				
		for(printf("+"),j = 1 ; j <= coluna ; j++)
			printf("---+");
		printf("\n");
		
		printf("\n\n");
	}
	return 0;
}
