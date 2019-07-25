#include <stdio.h>
#include <queue>
using namespace std;

char grafo[15][15];
int aux[15][15];
int linha,coluna;

void funcaoBFS(int l, int c){
		
	int L[] = {l-1, l  , l+1, l-1,l+1,l-1,l  ,l+1};
	int C[] = {c-1, c-1, c-1, c  ,c  ,c+1,c+1,c+1};		
	
	for(int i = 0 ; i < 8 ; i++)
	{
		if(L[i] >= 0 && C[i] >= 0 && L[i] < linha && C[i] < coluna && grafo[L[i]][C[i]] == grafo[l][c] && aux[L[i]][C[i]] == 0)
		{
			aux[L[i]][C[i]] = aux[l][c];				
			funcaoBFS(L[i],C[i]);						
		}			
	}	
	
}

int main(){
	linha = 0;
	int i,j;
	char entrada[100];
		
	while(scanf(" %[^\n]",entrada) != EOF)
	{	
		if(linha >= 3 && entrada[0] != '%')
		{
			
								
			for(coluna = 0,j = 0 ; entrada[j] != '\0' ; j++)
			{
				if(entrada[j] != ' ')
				{				
					grafo[linha][coluna] = entrada[j];		
					aux[linha][coluna] = 0;
					coluna++;	
				}			
			}
			linha++;
		}
		else
		{		
	
			int cont = 1;
			
			for(i = 0 ; i < linha ; i++){
				for(j = 0 ; j < coluna ; j++){
					if(aux[i][j] == 0){
						aux[i][j] = cont++;						
						funcaoBFS(i,j);
					}
					
				}
			}
			
			int tam[15];
			
			for(i = 0 ; i < coluna ; i++)
			{
				int maior = 0;
				for(j = 0 ; j < linha ; j++)
				{
					if(aux[j][i] > maior)
						maior = aux[j][i];
				}
				
				tam[i] = maior;
			}
			
						
			for(i = 0 ; i < linha ; i++,puts(""))
			{
				
				for(j = 0 ; j < coluna ; j++)
				{
					if(tam[j] > 99)
						printf("%3.d",aux[i][j]);
					else if(tam[j] > 9)
							printf("%2.d",aux[i][j]);
					else printf("%d",aux[i][j]);		
					
					printf(j == coluna-1? "": " ");
				
				}
			}	
			puts("%");
			
			linha = 0;
		}	
	}
	return 0;

}
