#include <stdio.h>
using namespace std;

int numero;

int main(){
	int L,MOD,TAM,i,NUM;
	int ajusta_tam = -1;
	
	while(scanf("%d%d",&L,&numero),L||numero){
		int coluna = (L+1)/2;
		int linha = (L+1)/2;
		
		
		NUM = MOD = 1;
		TAM = 1;
		
		ajusta_tam = -1;
		
		while((NUM*NUM) < numero){
			NUM+= 2;
			linha++;
			coluna++;			
		}	
		TAM = NUM-1;
		NUM*= NUM;
		
		
		
		while(1){
			
		//	printf("%d %d || %d\n",linha,coluna,NUM);
			if(NUM == numero) break;
			
			if(MOD == 1){					
				for(i = 0 ; i < TAM ; i++){
				//	printf("%d %d || %d\n",linha,coluna,NUM);
					linha--;
					NUM--;
					if(NUM == numero) break;					
				} 			
			}
			else if(MOD == 2){
				for(i = 0 ; i < TAM ; i++){
				//	printf("%d %d || %d\n",linha,coluna,NUM);
					coluna--;
					NUM--;
					if(NUM == numero) break;					
				} 			
			}
			else if(MOD == 3){
				for(i = 0 ; i < TAM ; i++){
				//	printf("%d %d || %d\n",linha,coluna,NUM);
					linha++;
					NUM--;
					if(NUM == numero) break;					
				} 			
			}
			else if(MOD == 4){
				for(i = 0 ; i < TAM ; i++){
					//printf("%d %d || %d\n",linha,coluna,NUM);
					coluna++;
					NUM--;
					if(NUM == numero) break;					
				} 			
			}
			
			if(++MOD == 5) MOD = 1;
			
			if(ajusta_tam == 2)  --TAM,ajusta_tam = 0;
			else ajusta_tam++;	
		}
		
		
		printf("Line = %d, column = %d.\n",linha,coluna);
	}
	return 0;
}
