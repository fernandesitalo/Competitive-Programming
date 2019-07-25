#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 101
using namespace std;



char grafo[MAX][MAX];
char aux[MAX][MAX];
int area;
int linha,coluna;

void funcao(int l,int c)
{
	int Y[] = {l-1, l  , l+1, l-1,l+1,l-1,l  ,l+1}; 
	int X[] = {c-1, c-1, c-1, c  ,c  ,c+1,c+1,c+1};
	
	grafo[l][c] = '.';
	area++;
		
	for(int u = 0 ; u < 8 ; u++)
	{
		if(X[u] >= 0 && X[u] < coluna && Y[u] >= 0 && Y[u] < linha && grafo[Y[u]][X[u]] == 'W')
			funcao(Y[u],X[u]);
	}	
}



int main(){

	int num,k,i,j,x,y;
	string entrada;
	
	scanf("%d",&num);
	while(num--)
	{
		linha = 0;
		
		scanf("\n\n");
		
		while(getline(cin,entrada), entrada[0] == 'W' || entrada[0] == 'L')
		{
			for(k = 0 ; entrada[k] != '\0' ; k++)
			{
				aux[linha][k] = entrada[k];
			}		
			
			linha++;	
			coluna = k;
		}
	
		do
		{
			x = 0;
			y = 0;
			
			for(i = 0 ; entrada[i] != ' ' ; i++){
				x *= 10;
				x+= entrada[i] - '0';				
			}
			
			for(i++ ; entrada[i] != '\0' ; i++){
				y *= 10;
				y+= entrada[i] - '0';
			}
			
			
			
			for(i = 0 ; i < linha ; i++)		
				for(j = 0 ; j < coluna ; j++)			
					grafo[i][j] = aux[i][j];
			
		
			area = 0;
			funcao(x-1,y-1);			
			printf("%d\n",area);
		
		/*	
			for(i = 0 ; i < linha ; i++,puts(""))
				for(j = 0 ; j < coluna ; j++)
					printf("%c",grafo[i][j]);			
			*/
		}while(getline(cin,entrada),entrada[0] != '\0');
		
		
		if(num)
			printf("\n");
	}
	return 0;
}









