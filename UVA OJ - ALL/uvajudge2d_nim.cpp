#include <stdio.h>
#include <map>
#include <string.h>
#define MAX 100
using namespace std;


bool grafo[MAX][MAX];

int N[MAX][MAX];
int S[MAX][MAX];
int L[MAX][MAX];
int O[MAX][MAX];


int main(){
	
	int num,i,k,j,l,c;
	scanf("%d",&num);
	while(num--){
	
		memset(grafo,false,sizeof(grafo));
		memset(S,0,sizeof(S));
		memset(N,0,sizeof(N));
		memset(L,0,sizeof(L));
		memset(O,0,sizeof(O));
		
		
		int linha,coluna,qtd;
		scanf("%d%d%d",&linha,&coluna,&qtd);
		
		
		for(i = 0 ; i < qtd; i++) scanf("%d%d",&l,&c),grafo[l][c] = true;

		
		for(i = 0 ; i < linha ; i++){
			for(k = coluna-1 , j = 0; j < coluna ; k--,j++){				
				
				if(grafo[i][j]){    /// --->
					if(j == 0)O[i][j] = 1;					
					else O[i][j] = O[i][j-1]+1;
				}				
				if(grafo[i][k] ){   //// <---
					if(k == coluna-1) L[i][k] = 1;
					
					else L[i][k] = L[i][k+1]+1;
				}				
			}			
		}	
		for(i = 0 ; i < coluna ; i++){
			for(k = 0, j = linha-1 ; k < linha ; k++,j--){		
			
				if(grafo[k][i]){
					if(k == 0) N[k][i] = 1;
					else N[k][i] = N[k-1][i] + 1;		
				}					
				if(grafo[j][i]){ 
					if(j == coluna-1) S[j][i] = 1;
					else S[j][i] = S[j+1][i] + 1;
				}
			}
		}
		
		
		map<int,int> m;
		for(i = 0 ; i < linha ; i++){
			for(j = 0 ; j < coluna ; j++){
				m[N[i][j] + S[i][j] + L[i][j] + O[i][j]]++;
			}
		}
		
		memset(grafo,false,sizeof(grafo));
		memset(S,0,sizeof(S));
		memset(N,0,sizeof(N));
		memset(L,0,sizeof(L));
		memset(O,0,sizeof(O));
		
		for(i = 0 ; i < qtd; i++) scanf("%d%d",&l,&c),grafo[l][c] = true;

		
		for(i = 0 ; i < linha ; i++){
			for(k = coluna-1 , j = 0; j < coluna ; k--,j++){				
				
				if(grafo[i][j]){    /// --->
					if(j == 0)O[i][j] = 1;					
					else O[i][j] = O[i][j-1]+1;
				}			
					
				if(grafo[i][k]){   //// <---
					if(k == coluna-1) L[i][k] = 1;
					else L[i][k] = L[i][k+1]+1;
				}				
			}			
		}	
		for(i = 0 ; i < coluna ; i++){
			for(k = 0, j = linha-1 ; k < linha ; k++,j--){		
			
				if(grafo[k][i]){
					if(k == 0) N[k][i] = 1;
					else N[k][i] = N[k-1][i] + 1;		
				}					
				if(grafo[j][i]){ 
					if(j == coluna-1) S[j][i] = 1;
					else S[j][i] = S[j+1][i] + 1;
				}
			}
		}

		for(i = 0 ; i < linha ; i++){
			for(j = 0 ; j < coluna ; j++){
				m[N[i][j] + S[i][j] + L[i][j] + O[i][j]]--;
			}
		}		

		
		bool flag = true;
		for(map<int,int>::iterator it = m.begin() ; it != m.end() ; it++){
			if(it->second != 0){
				flag = false;
				break;
			}
		}

		printf(flag == true?"YES\n":"NO\n");
		
	}
	return 0;
}
