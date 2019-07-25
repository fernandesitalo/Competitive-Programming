#include <bits/stdc++.h>
using namespace std;

int val[40];
int wt[1010];
int K[40][1010];
int constante;

void PrintRecursiva(int qtd,int n,int W){
	if(n == 0) {printf("%d\n",qtd);return;}
	
	printf("---- %d %d\n",K[n][W],K[n-1][W]);
	if(K[n][W] != K[n-1][W]){
		PrintRecursiva( qtd+1 , n-1 ,  W-val[n-1] );
		printf("%d %d\n", wt[n-1]/(3*constante) , val[n-1] );
	}
	else  PrintRecursiva(qtd,n-1,W);
}




void knapSack(int W, int n){
   int i, w; 
	for (i = 0; i <= n; i++){
		
		for (w = 0; w <= W; w++){
		   if (i==0 || w==0) K[i][w] = 0;
		   
		   else if (wt[i-1] <= w)   K[i][w] = max(val[ i-1 ] + K[ i-1 ][ w - wt[ i-1 ] ],  K[ i-1 ][ w ]);
		   
		   else  K[i][w] = K[i-1][w];
		}
	} 
	printf("%d\n",K[n][W]);
	PrintRecursiva(0,n,W);   
}


int main(){
	freopen("e.txt","r",stdin);
	int t,qtd,d,v;
	bool barraN = false;	
	while(scanf(" %d %d",&t,&constante) != EOF){		
		if(barraN)puts(""); barraN = true;				
		scanf(" %d",&qtd);		
		for(int i = 0 ; i < qtd ; i++){
			scanf(" %d %d",&d,&v); // d-distancia / v-valor
			val[i] = v;
			wt[i] = d*(3*constante);			
		}
		knapSack(t,qtd);
	}
	return 0;
}
