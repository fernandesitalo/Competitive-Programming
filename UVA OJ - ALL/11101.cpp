#include <stdio.h>
#include <queue>
#define MAX 2000
#define INF 500000000
using namespace std;

char grafo[MAX][MAX];
int dis[MAX][MAX];
bool vis[MAX][MAX];
queue<pair<int,int> >q;

void reset(){
	for(int i = 0 ; i < MAX ; i++)
		for(int j = 0 ; j < MAX ; j++)
			grafo[i][j] = '-',dis[i][j] = 0,vis[i][j] = false;
}

bool valida(int l , int c){
	return (l < MAX && c < MAX && l >=0 && c >= 0);
}

int bfs(){
		
	while(!q.empty()){
		int l = q.front().first;
		int c = q.front().second;
		q.pop();
		
		int L[] = {l,l,l+1,l-1};
		int C[] = {c+1,c-1,c,c};
		
		for(int i = 0; i < 4 ; i++){			
			if(valida(L[i],C[i]) && !vis[L[i]][C[i]]){				
				if(grafo[L[i]][C[i]] == 'i') 
					return (dis[l][c]+1);									
					vis[L[i]][C[i]] = true;					
					dis[L[i]][C[i]] = dis[l][c] + 1;
					q.push(make_pair(L[i],C[i]));
			}
		}
	}	
	return -1;
}

int main(){	
#ifndef ONLINE_JUDGE
    freopen("../e.txt","r", stdin);
    freopen("../s.txt","w", stdout);
#endif
	
	int i,j,shop1,shop2,l,c;	
	
	while(scanf("%d",&shop1), shop1){
		
		reset();
		for(i = 0 ; i < shop1 ; i++){
			scanf("%d%d",&l,&c);			
			grafo[l][c] = 'i';
		}
		
		while(!q.empty()){
			q.pop();	
		}
		for(scanf("%d",&shop2),j = 0 ; j < shop2 ; j++){
			scanf("%d%d",&l,&c);			
			q.push(make_pair(l,c));
			vis[l][c] = true;		
		}	
		int r = bfs();	
		printf("%d\n",r);		
	}	
	return 0;
}
