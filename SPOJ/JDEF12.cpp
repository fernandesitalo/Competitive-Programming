#include <stdio.h>

int main(){
	
	int k1,maior;
	int i; // contador
	
	
	scanf("%d",&k1);
	maior = k1;
		
	while(k1 != 0){			
		if(k1 > maior){ // compara o valor lido com o maior ate o momento
			maior = k1; // armazena o maior valor
		}
		
		scanf("%d",&k1); 
	}	
	printf("%d",maior);	
	
	return 0;
}
