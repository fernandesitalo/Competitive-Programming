#include <bits/stdc++.h>
#define MAXN 70000
using namespace std;

int vet1[MAXN];
int main(){

	//freopen("in","r",stdin);
	
	int aux;
	int t;
	int n,p,q;
	scanf(" %d",&t);
	for(int ct = 1 ; ct <= t ; ++ct){
		
		scanf(" %d %d %d",&n,&p,&q);
		
		for(int i = 0 ; i <= p ; ++i) vet1[i] = -1;
		
		for(int i = 0 ; i <= p ; ++i){
			 scanf(" %d",&aux);
			 vet1[aux-1] = i;
		 }
		 
		 int TAM = 0;
		 
		 int vet[max(p+1,q+1)];
		 
		for(int i = 0 ; i <= q ; ++i){
			scanf(" %d",&aux);
			if(vet1[aux-1] != -1){ vet[TAM++] = vet1[aux-1];}
		}
			 
		int lismax = 0;
		
			int DP[TAM+1];
			
			DP[0] = 1;	
			for (int i = 0; i < TAM ; i++){
				DP[i] = 1;
				for (int j = i -1; j > -1; j--){
					if (DP[j] + 1 > DP[i] && vet[j] < vet[i]) DP[i] = DP[j] + 1;
					if (DP[i] > lismax)	lismax = DP[i];
				}
			}	

		printf("Case %d: %d\n",ct,lismax);
	
	
	
	}
	return 0;
}
