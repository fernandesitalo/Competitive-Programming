/*		Uva judge 507 _ JILL RIDES AGAIN 
 * 	
 * 	Uso Do Algoritmo de Jay Kadane's... MAIOR SOMA DE UMA SEQUENCIA
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
 * */

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	//freopen("in","r",stdin);
	
	int q,n;
	
	scanf("%d",&q);
	for(int rt = 1; rt <= q ; ++rt){
		
		
		scanf("%d",&n);
		
		
		n--;
		int vet[n];
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&vet[i]);
		}
		
		int inicio = 0;

		
		int ans_inicio = 0,ans_fim = 0;
		
		int resp = 0;
		int sum = 0,ans = 0;
		for(int i = 0 ; i < n ; i++){
			sum += vet[i];
			
			ans = max(ans,sum);			
			
			if(sum < 0) sum = 0,inicio = i+1;
			
			if( ans > resp || (sum == resp  && (ans_fim - ans_inicio) < (i - inicio) )){ //condicao que a  questao pede
				resp = ans;																 // pegar maior sequencia
				ans_inicio = inicio;
				ans_fim = i;
			}
		}
		
		if(resp <= 0)
			printf("Route %d has no nice parts\n",rt);
		else 
			printf("The nicest part of route %d is between stops %d and %d\n",rt,ans_inicio+1,ans_fim+2);
	
	}
	
	return 0;
}
