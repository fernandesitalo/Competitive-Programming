/* UVA JUDGE 10684_ THE JACKPOT
 *	APLICAÇÃO DIRETA DO ALGORITMO DE JAY KADANE
 * 	
 * 
 * 	-> o algoritmo visa obter a maior soma de uma sequencia...
 * 
 * 	////////////// inside int main() /////////////////////
 * 	int n = 9, A[] = {4,-5,6,-7,3,-1,4,4,5};
 * 	int sum = 0,ans = 0;
 * 	for(int i = 0 ; i < n ; ++i){
 * 		sum += A[i];
 * 		ans = max(ans,sum);
 * 		if(sum < 0) sum = 0;
 * 	}
 * 	printf("Max 1D Range Sum = %d\n",ans); 
 * 	//////////////////////////////////////////////////////	
 * 
 * */


#include <bits/stdc++.h>
using namespace std;


int main(){
	
	//freopen("in","r",stdin);
	
	int n;
	
	while(scanf("%d",&n),n){
		
		int vet[n];
		
		for(int i = 0 ; i < n ; ++i)
		scanf("%d",&vet[i]);
		
		int sum = 0,ans = 0;
		
		for(int i = 0 ; i < n ; ++i){
			sum += vet[i];
			ans = max(ans,sum);
			if(sum < 0) sum = 0;
		}
		
		if(ans > 0) printf("The maximum winning streak is %d.\n",ans);
		else printf("Losing streak.\n");
	}
	return 0;
}


/*
	ACCEPTED TBM!
int main(){
	
	//freopen("in","r",stdin);
	
	int n,aux;
	
	while(scanf("%d",&n),n){
		
		int sum = 0,ans = 0;		
		for(int i = 0 ; i < n ; ++i){
			scanf("%d",&aux);
			sum += aux;
			ans = max(ans,sum);
			if(sum < 0) sum = 0;
		}
		
		if(ans > 0) printf("The maximum winning streak is %d.\n",ans);
		else printf("Losing streak.\n");
	}
	return 0;
}

 * */
