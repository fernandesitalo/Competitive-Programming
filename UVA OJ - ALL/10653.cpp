#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 1099
using namespace std;

bool grafo[MAX][MAX];
int dis[MAX][MAX];
int linha,coluna;

void reset(){
	for(int i = 0 ; i < linha ; i++)
		for(int j = 0 ; j < coluna ; j++)
			grafo[i][j] = false,dis[i][j] = 0;
}
bool valida(int l , int c){
	return (l < linha && c < coluna && l >=0 && c >= 0 && !grafo[l][c]);
}

int bfs(int l, int c,int lf,int cf){
	queue<pair<int,int> >q;
	q.push(make_pair(l,c));
	dis[l][c] = 0;
	while(!q.empty()){
		l = q.front().first;
		c = q.front().second;
		q.pop();
		if(l == lf && c == cf)
			return dis[l][c];
		
		int L[] = {l,l,l+1,l-1};
		int C[] = {c+1,c-1,c,c};
		for(int i = 0; i < 4 ; i++){
			if(valida(L[i],C[i])){
				grafo[L[i]][C[i]] = true;
				dis[L[i]][C[i]] = dis[l][c] + 1;
				q.push(make_pair(L[i],C[i]));			
			}
		}
	}	
	return 0;
}


int main()
{
	int i,j,qtd,lin,num,aux,li,lf,ci,cf;
	while(scanf("%d%d",&linha,&coluna),linha||coluna){
		reset();		
		for(scanf("%d",&num),i = 0 ; i < num ; i++){			
			for(scanf("%d%d",&lin,&qtd), j = 0 ; j < qtd ; j++)
				scanf("%d",&aux),grafo[lin][aux] = true;
			}
			scanf("%d%d%d%d",&li,&ci,&lf,&cf);
			
			int r = bfs(li,ci,lf,cf);
			printf("%d\n",r);			
		}	
	return 0;
}
