#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int MatAdj[210][210];
int grau[210];

int size;
int lim;

void dfs(int u){	
	for(int i = 0 ; i < lim; ++i){		
		if(MatAdj[u][i] > 0){
			MatAdj[u][i]--,MatAdj[i][u]--;				
			dfs(i);			
			size++;				
		}		
	}
}

bool verifica(){
	for(int i = 0 ; i < lim ; i++){
		if(grau[i]%2 != 0)
			return false;
	}
	return true;
}

int main(){	
	int u,v,r;
	
	while(scanf("%d%d",&lim,&r) != EOF){ 
		
		memset(MatAdj,0,sizeof(MatAdj));
		memset(grau,0,sizeof(grau));
		
		for(int i = 0 ; i < r ; ++i){
		
			scanf("%d%d",&u,&v);
			MatAdj[u][v]++;
			MatAdj[v][u]++;			
			grau[u]++;
			grau[v]++;
		}	
		size = 0;
		
		if(verifica()){			
			dfs(u);		
		}
				
		if(size == r && r > 0) printf("Possible\n");		
		else printf("Not Possible\n");
	}
	return 0;
}
