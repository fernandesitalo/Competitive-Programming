#include <bits/stdc++.h>
using namespace std;

int wt[1010];
int val[1010];
int K[1010][1010];
int aux[200];

/// compara pesos e quarga valores
int knapSack(int W ,int n, int tam){
   int i, w;
    
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++) /// quantidade de itens
   {
       for (w = 0; w <= W; w++) /// numero de mochilas
       { /// w e o peso da mochila
           if (i==0 || w==0) // evita inicialização de linha coluna
               K[i][w] = 0;
           else if (wt[i-1] <= w) // wt e o que esta dentro da mochila numero i-1 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else K[i][w] = K[i-1][w];
       }
   } 
   
   int res = 0;
   for(int i = 0 ; i < tam ; i++) res+= K[n][aux[i]];
   
   return res;
}

int main(){
	//freopen("e.txt","r",stdin);
	
	int qtd,n;
	int res,g;
	
	scanf(" %d",&qtd);
	
	while(qtd--){
		scanf(" %d",&n);
				
		for(int i = 0 ; i < n ; i++){
			scanf(" %d %d",&val[i],&wt[i]);
		}
		scanf("%d",&g);
		
		int maior = -9999;
		for(int i = 0 ; i < g ; i++){
			scanf(" %d",&aux[i]);
			
			if(maior < aux[i]) maior = aux[i];			
		}
				
		res = knapSack(maior,n,g);
		
		printf("%d\n",res);
	}
	
	return 0;
}
