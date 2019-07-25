#include <stdio.h>

int main()
{
	
	int linha,coluna,qtd;
	while(scanf(" %d %d %d",&linha,&coluna,&qtd), linha||coluna|| qtd)
	{
		int l,c,i,j;
		char aux[coluna+qtd];
		char mat[linha+1][coluna+1];
		bool flag = true;
		for( i = 1 ; i <= linha ; i++)
		{
			scanf(" %s",aux);
			for(j = 0 ; aux[j] != '\0' ; j++)
			{
				mat[i][j+1] = aux[j];
				if(flag && (aux[j] == 'N' || aux[j] == 'S' || aux[j] == 'L' || aux[j] == 'O'))
				{
					l = i;
					c = j+1;
					flag = false;
				}			
			}
		}
		
		scanf(" %s",aux);
		
		int total = 0;
		
		for(i = 0 ; aux[i] != '\0' ; i++)
		{
			
			
		/*	for(int k = 1 ; k <= linha ; k++)
			{
				for(j = 1 ; j <= coluna ; j++)
				{
					printf("%c",mat[k][j]);
				}
				printf("\n");
			}printf("\n\n");
			
			printf(" >> %c\n",aux[i]);*/
			
			
			if(aux[i] == 'D')//"gire 90 graus para a direita
			{
				if(mat[l][c] == 'N') mat[l][c] = 'L';
				else if(mat[l][c] == 'S')mat[l][c] = 'O';
				else if(mat[l][c] == 'L')mat[l][c] = 'S';
				else mat[l][c] = 'N';
				continue;	
			}
			if(aux[i] == 'E')//gire 90 graus para a esquerda"
			{
				if(mat[l][c] == 'N') mat[l][c] = 'O';
				else if(mat[l][c] == 'S')mat[l][c] = 'L';
				else if(mat[l][c] == 'L')mat[l][c] = 'N';
				else mat[l][c] = 'S';
				continue;
			}
			// N l-- l > 0
			// S l++ l <= linha
			// L c++ c <= coluna
			// O c-- c > 0
			
			if(mat[l][c] == 'N' && l-1 > 0 && mat[l-1][c] != '#')
			{	
				
				l--;
				if(mat[l][c] == '*')
					total++;					
				
				mat[l][c] = 'N';
				continue;
			}
			if(mat[l][c] == 'S' && l+1 <= linha && mat[l+1][c] != '#')
			{
				
				l++;
				
				if(mat[l][c] == '*')
					total++;					
				
				mat[l][c] = 'S';
				continue;
			}
			
			
			if(mat[l][c] == 'L' && (c+1) <= coluna && mat[l][c+1] != '#')
			{
				++c;
				
				if(mat[l][c] == '*')
					total++;					
				
				mat[l][c] = 'L';
				continue;
			}
			if(mat[l][c] == 'O' && c-1 > 0 && mat[l][c-1] != '#')
			{
				c--;
				if(mat[l][c] == '*')
					total++;					
				
				mat[l][c] = 'O';
				continue;
			}	
		}
		
		printf("%d\n",total);
	}
	return 0;
}
