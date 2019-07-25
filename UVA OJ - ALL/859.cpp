#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAX 100
using namespace std;


int linha,coluna;
int grafo[MAX][MAX]; /// visitados

/// vizinhos adjacentes
int L[] ={-1,0,0};
int C[] ={0,1,-1};

/// vizinhos
int LL[] ={0,0,-2,-2,-2};
int CC[] ={2,-2,0,2,-2};

int LI[] = {0,0,-1,-1,-1};
int CI[] = {1,-1,0,1,-1};


struct no{
	int l,c,s; // linha coluna salto
	no(int l,int c, int s){
		this->l = l;
		this->c = c;
		this->s = s;
	}
};

void reset(){
	for(int i = 0 ; i <= linha ; i++)
	for(int j = 0 ; j <= coluna ; j++)
		grafo[i][j] = 1, grafo[i][j] = 1;
}


inline bool valida(int l, int c){
	return (l >= 1 && l <= linha && c <= coluna && c >= 1);
}

void bfs(int l, int c, map<pair<int,int>, int > &aux){
	
	queue<no> q;
	int s;
	q.push(no(l,c,0));	
	while(!q.empty()){
		l = q.front().l;
		c = q.front().c;
		s = q.front().s;
		q.pop();
		
		
		if(s == 0){						
			for(int i = 0 ; i < 3 ; i++){
				if(valida(l+L[i],C[i]+c) && grafo[L[i]+l][C[i]+c] == 1){
					aux[make_pair(l+L[i],c+C[i])] = s+1;
					grafo[L[i]+l][C[i]+c] = -1; // visitado - ok
					
					
				}
				
			}			
		}
		
		//puts("*");
		for(int i = 0 ; i < 5 ; i++){  
			
			 // printf("%d   %d\n%d   %d\n",l,c,l+LL[i],c+CC[i]);                     
			if(valida(l+LL[i],CC[i]+c) && grafo[LL[i]+l][CC[i]+c] == 1 && grafo[l+LI[i]][c+CI[i]] == 0){
				aux[make_pair(l+LL[i],c+CC[i])] = s+1;
				grafo[LL[i]+l][CC[i]+c] = -1; // visitado - ok
				q.push(no(LL[i]+l,CC[i]+c,s+1));			
			}	
		}
	}	
}












int main(){
	
	int i,li,ci;
	bool flag = false;
	while(scanf("%d%d",&linha,&coluna) != EOF){
		reset();
		for(i = 0 ; i < coluna*4 ; i++){
			scanf("%d%d",&li,&ci);
			grafo[(linha+1)-li][ci] = 0;
			grafo[(linha+1)-li][ci] = 0;
		}	
		
		scanf("%d%d",&li,&ci);
		
		li = (linha+1) - li;
		
		map<pair<int,int>, int> m;
		bfs(li,ci,m);
		if(flag)puts("");flag = true;
		
		for(map<pair<int,int>, int>::iterator it = m.begin() ; it != m.end() ; it++){
			printf("%d %d %d\n",(linha+1)-it->first.first,it->first.second, it->second);
			
		}
		
		
	//	for(i = 1 ; i <= linha ; i++,puts(""))
	//	for(int j = 1 ; j <= coluna ; j++)
	//		printf("%d ",grafo[i][j]);
		
		
	}

	return 0;
}
