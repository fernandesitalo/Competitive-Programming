#include <stdio.h>
#include <math.h>

int main(){	
	int i = 0,aux,vet[15];	
	scanf("%d",&vet[i]);
	while(vet[i] != -1 && i < 15)
	{	
		vet[i] = pow(2,vet[i])+1;
		vet[i] = vet[i] * vet[i];
			
		i++;
		scanf("%d",&vet[i]);	
	}
		
	for(aux = 0 ; aux < i ; aux++){
			printf("\nteste %d\n%d\n",aux+1,vet[aux]);	
	}
	return 0;
}	
