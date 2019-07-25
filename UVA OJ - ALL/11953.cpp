#include <stdio.h>
#include <queue>
#define MAX 101
using namespace std;

char grafo[MAX][MAX];
bool vis[MAX][MAX];
int tam;

bool valida(int l, int c){
	return (l >= 0 && l < tam && c >= 0 && c < tam && !vis[l][c]); 
}

void b(int l, int c){	
	queue<pair<int,int> >q;
	q.push(make_pair(l,c));
	vis[l][c] = true;
		
	while(!q.empty())
	{
		l = q.front().first;
		c = q.front().second;
		q.pop();
		
		int L[] = {l,l,l+1,l-1}; 
		int C[] = {c+1,c-1,c,c};
		
		for(int i = 0 ; i < 4 ; i++)
		{
			if(valida(L[i],C[i]) && (grafo[L[i]][C[i]] == 'x' || grafo[L[i]][C[i]] == '@')){
				vis[L[i]][C[i]] = true;				
				q.push(make_pair(L[i],C[i]));
			}			
		}
	}
}




int main(){
	
	int i,j,num,casos,cont;
	char entrada[MAX];
	
	for(scanf("%d",&num),casos = 1 ; casos <= num ; casos++)
	{
		for(scanf("%d",&tam), i = 0 ; i < tam ; i++)
			for(scanf("%s",entrada),j = 0 ; j < tam ; j++)
				grafo[i][j] = entrada[j],vis[i][j] = false;
				
				
		for(cont = 0,i = 0 ; i < tam ; i++)
			for(j = 0 ; j < tam ; j++)
				if(grafo[i][j] == 'x'&& !vis[i][j]){
					b(i,j);
					cont++;
				}
		
		printf("Case %d: %d\n",casos,cont);	
	}
	return 0;
}
