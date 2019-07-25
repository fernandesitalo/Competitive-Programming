#include <bits/stdc++.h>
using namespace std;


void buildHEAP(int *arr, int inicio , int fim){ // TEMPO LINEAR	
	
	int pai = arr[inicio];
	
	int filho = (inicio << 1)+1;
	
	while(fim >= filho){
		
		if(fim >= filho+1 && arr[filho+1] > arr[filho]) filho++;
		
		if(arr[filho] > pai){ // vamo trocar entao
			swap(arr[filho],arr[inicio]);
			inicio = filho;
			filho = (inicio << 1)+1;			
		}
		else return;
	}
}




void HEAP_SORT(int *arr, int tam){
		
	for(int i = (tam-1/2) ; i > -1 ; --i){ // constroi o heap maximo
		buildHEAP(arr,i,tam); 
	}
	
	// no heeap maximo, a raiz(posicao zero) sempre contem o 'maior' elemento
	
	
	for(int i = tam-1 ; i > 0 ; --i){
		swap(arr[0],arr[i]); // pega o primeiro elemento do heapMAXIMO, e coloca no final do array
		buildHEAP(arr,0,i-1); // controi um novo heap com o resto do vetor e faz a mesma coisa
	}
	
/*	ENTAO O HEAP SORTE É ISSO, COLOCA NA FILA DE PRIORIDADE E DEPOIS TIRA.... SÓ
 */
	
}


/*	HEAP BINARIO, 2 TIPOS: HEAP MAXIMO E MINIMO !
 * 
 * 	PAI = I/2
 * 
 * 	FILHO DIRETA = (I << 1)+1;
 * 
 * 	FILHO ESQUERDA = (I << 1);
 * 	
 */


int main(){
	
	int vet[] = {5,3,1,5,8,3,9,4,7,9,11,22,33,44,55,66,77,88,88};
	
	int n = (sizeof (vet)/ sizeof (int));
	
	cout << n << endl;
	
	HEAP_SORT(vet,n);
	
	for(int i = 0 ; i < n ; ++i){
		cout << vet[i] << " ";
	} cout << endl;

	return  0;
}
