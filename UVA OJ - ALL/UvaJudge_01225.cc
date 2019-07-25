#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,q;
	
	scanf("%d",&q);
	
	while(q--){
		scanf("%d",&n);
		int vet[10] = {0};
		int aux;
		for(int i = 1; i <= n ; ++i){
			aux = i;
			while(aux){
				int pos = aux%10;
				vet[pos]++;
				aux /=10 ;
			}		
		}		
		for(int i = 0 ; i < 9 ; ++i){
			printf("%d ",vet[i]);
		}printf("%d\n",vet[9]);
	}
	return  0;
}
