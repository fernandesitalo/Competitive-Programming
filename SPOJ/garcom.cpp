#include <stdio.h>

int main(void) {
	
	int n,i,k;
	
	scanf("%d",&n);
	int vet[n-1];
	
	for(i=0; i<(n-1) ; i++){ 	//leitura dos n-1 valores inteiros
		scanf("%d",&vet[i]);
	}
	
	for(i= 0 ; i< n ; i++){	
		
		for(k=0 ; k < (n-1) && vet[k] != (i+1) ; k++); 
		
		if(k == (n-1)) {
			printf("%d",i+1);
			i = n;
		}
	}
	return 0;
}
