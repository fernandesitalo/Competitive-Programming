#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

bool marcador;

int tam;
char letras[30];
bool graf[30][30];
bool vis[300];
char saida[200];

void reset(){
    memset(vis,false,sizeof(vis));    
    memset(graf,false,sizeof(graf));
}



bool verifica(int size, int l)
{
    for ( int i = 0; i < size; i++ ) {
        if ( graf[l][saida[i] - 'A']) 
			return false;
    } 
    return true;
}



void dfs_ts(int qtd){
	if(qtd == tam){ marcador = true;
		printf("%c",saida[0]);
		for(int y = 1 ; y < tam ; y++)
		{
			printf(" %c",saida[y]);
		}
		printf("\n");
		return;
	}
	
	for(int h = 0 ; h < tam ; h++)
	{
		if(verifica(qtd,letras[h]-'A') && !vis[h])
		{
			saida[qtd] = letras[h];
            vis[h] = true;
			dfs_ts(qtd + 1);
            vis[h] = false;			
		}
	}
}


int main(){

	char A[500];
	char enter;
	int ct;
	scanf("%d",&ct);
	
	getchar();
	
	while(ct--){
		//scanf("%c",&enter);
		
		getchar();
		
		gets(A);
		tam = 0;
		
		for(int i = 0 ; A[i] != '\0' ; i++)
			if(isalpha(A[i])) letras[tam++] = A[i];			
		
		sort(letras, letras + tam); 
        reset ();
		
		gets(A);	
		char u,v;	
		
		for(int i = 0 ; A[i] ; i++){ /// AO  INVEZ DE USAR LISTA DE ADJACENCIA, USA-SE A MATRIZ DE ADJACENCIA
						
			if(isalpha(A[i])){
				u = A[i];
				i++;
				while(!isalpha(A[i])) i++;				
				v = A[i];				
				graf[u - 'A'][v - 'A'] = true;					
				///printf(">>>>>>>>> %c %c\n",u,v);						
			}			
		}
		marcador = false;
		dfs_ts(0);	
		
		if(!marcador) printf("NO\n");
		if(ct) printf("\n");
	}
	
	return 0;
}
