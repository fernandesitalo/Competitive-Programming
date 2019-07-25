
#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 101
using namespace std;



char grafo[MAX][MAX];
int area;
int linha,coluna;

void funcao(int l,int c)
{
	int Y[] = {l  , l-1,l+1,l  }; 
	int X[] = {c-1, c  ,c  ,c+1};
	
	grafo[l][c] = 'P';
	area++;
		
	for(int u = 0 ; u < 4 ; u++)
	{
		if(X[u] >= 0 && X[u] < coluna && Y[u] >= 0 && Y[u] < linha && grafo[Y[u]][X[u]] == '0')
			funcao(Y[u],X[u]);
	}	
}



int main(){

	int num,k,x,y;
	string entrada;
	
	scanf(" %d",&num);
	while(num--)
	{
		linha = 0;		
		scanf(" %d %d",&x,&y);cin.ignore();
		
		while(getline(cin,entrada), entrada[0] != '\0')
		{
			for(k = 0 ; entrada[k] != '\0' ; k++)
			{
				grafo[linha][k] = entrada[k];
			}		
			
			linha++;	
			coluna = k;
		}
		
	/*	for(int i = 0 ; i < linha ; i++,puts(""))
		for(int j = 0 ; j < coluna ; j++)
			printf("%c",grafo[i][j]);
		
		
		printf("linha == %d   coluna === %d\n",linha,coluna);
		* */
			
		area = 0;
		funcao(x-1,y-1);			
		printf("%d\n",area);		
		
		if(num)
			printf("\n");
	}
	return 0;
}









