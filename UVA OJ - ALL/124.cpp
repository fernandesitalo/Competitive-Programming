#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;


int tam;
char letras[30];
bool graf[30][30];
bool vis[30];
char saida[30];

void reset(){
    memset(vis,false,sizeof(vis));    
    memset(graf,false,sizeof(graf));
}



bool verifica(int size, int l)
{
    for ( int i = 0; i < size; i++ ) {
        if ( graf[l][saida[i] - 'a'] == true ) 
			return false;
    } 
    return true;
}



void funcao(int qtd){
	if(qtd == tam){
		for(int y = 0 ; y < tam ; y++){
			printf("%c",saida[y]);
		}
		printf("\n");
		return;
	}
	
	for(int h = 0 ; h < tam ; h++){
		if(verifica(qtd,letras[h]-'a') && !vis[h]){
			saida[qtd] = letras[h];
            vis[h] = true;
			funcao(qtd + 1);
            vis[h] = false;			
		}
	}
}




int main(){

	char entrada[500];
    bool flag = false;
 
    while ( gets(entrada) ) {
        tam = 0;
 
        for ( int i = 0; entrada[i]; i++ )
            if ( isalpha (entrada[i])) letras[tam++] = entrada[i];
 
        sort (letras, letras + tam); 
        reset ();
 
        gets(entrada);
        char u,v;
 
        for ( int i = 0; entrada[i]; i++ ) {
           
            if (isalpha (entrada[i])) {
                u = entrada[i];
                i++;
                while(!isalpha(entrada[i])) i++;
					v = entrada[i];                
                graf[u - 'a'] [v- 'a'] = true;
            }
        }
 
        if ( flag )printf("\n");
			flag = true;
 
        funcao(0);
    }
 
    return 0;


	return 0;
}
