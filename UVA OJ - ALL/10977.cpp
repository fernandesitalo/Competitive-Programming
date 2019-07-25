#include <stdio.h>
#include <queue>
#include <utility>
#include <cmath>
#define MAX 210
using namespace std;

bool grafo[MAX][MAX];
int dist[MAX][MAX];
int linha,coluna;

void bfs(int y,int x)
{
	queue<pair<int,int> > fila;
	
	fila.push(make_pair(y,x));
	dist[y][x] = 0;
	
	while(!fila.empty())
	{
		int l = fila.front().first;
		int c = fila.front().second;
		fila.pop();		
		
		int L[] = {l-1,l+1,l  ,  l};
		int C[] = {c  ,c  ,c+1,c-1};
		
		for(int i = 0 ; i < 4 ; i++)
		{				
			if((L[i] >= 0) && (C[i] >= 0) && (L[i] < linha) && (C[i] < coluna) && grafo[L[i]][C[i]])
			{
				grafo[L[i]][C[i]] = false;
				dist[L[i]][C[i]] = dist[l][c] + 1;
				fila.push(make_pair(L[i],C[i]));				
					
			}			
		}		
	}	
}


int main()
{	
	int num,i,j,l,x,y,k;		
	
	while(scanf("%d%d",&linha,&coluna),linha||coluna){
		
		for(i = 0 ; i < linha ; i++)
		for(j = 0 ; j < coluna ; j++)
		grafo[i][j] = true,dist[i][j] = -1;	
		
		for(scanf("%d",&num),i = 0 ; i < num ; i++){
			scanf("%d%d",&y,&x);			
			grafo[y-1][x-1] = false;
		}	
		
		
		
		for(scanf("%d",&num),i = 0 ; i < num ; i++){
			scanf("%d%d%d",&y,&x,&l);y--,x--;			
			
				for(k = 0 ; k < linha ; k++)
				{
					for(j = 0 ; j < coluna ; j++)
					{
						if((y - k)*(y - k) + (x - j)*(x - j) <= l*l)
						{
							grafo[k][j] = false;
						}		
					}
				}				
		}
		
		
		
		
		bfs(0,0);		
		if(dist[linha-1][coluna-1] == -1)
			puts("Impossible.");
		else
			printf("%d\n",dist[linha-1][coluna-1]);	
	}
	return 0;	
}
