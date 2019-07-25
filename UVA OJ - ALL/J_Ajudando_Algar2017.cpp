/*	Questao pede para determinar todos Subconjuntosde um determinado
 *  Conjuto. Conforme o exemplo de entrada achamos um padrao....
 * 	o primeiro subconjunto sempre e o conjunto vazio
 * 	o segund subconjunto e o vazio mais a primeira letra
 * 	o terceiro subconjunto e o vazio mais o segundo elemento,
 * 	o quarto conjunto e o segundo subconjunto mais o terceiro elemento...
 *  
 * 	.: pegar os subconjuntos existentes, apatir do conjunto vazio e
 *     adicionar o elemento ao final deles.... fazer isso com todos...
 * 		meio que recorrencia
 * 
 * 		caso de Exemplo:
	
		Entrada:
		1
		3 abc     
		
		Saida:
		              /// linha em branco, referenciando o conjunto vazio que sempre sera o primeio;
		a
		b
		ab
		c
		ac
		bc
		abc  
 */


#define M 1
// M = 1 -> solução com Vector
// M = 0 -> solução com Vet de string

#if M

#include <bits/stdc++.h>
using namespace std;

int main(){
	int q,n,i;
	string e;
	scanf(" %d",&q);
	
	while(q--){
		scanf("%d",&n);
		cin>>e;
						
		vector<string> v;// usando um vector para guardar os subcnjuntos anteriores
		v.push_back("");
		
		for(i = 0,puts(""); e[i] ; ++i){				
			int tam = v.size();
			
			for(int k = 0 ; k < tam ; ++k){ 
				cout << v[k] + e[i] + "\n";
				v.push_back(v[k]+e[i]);		
			}
		}	
	}
	return 0;
}
#else //--------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int i,n,q,index,k;
	string e; 
	
	scanf("%d",&q);
	while(q--){
		scanf(" %d",&n);
		cin>>e;
		string vet[1000]; // usando um vetor de string para armazenar os subconjuntos anteriores
		index = 1;
		vet[0] = "";
		
		for(puts(""),i = 0 ; e[i] ;++i){					
			
			int tam = index;			 	
			
			for(k = 0 ; k < tam ; k++){
				cout<<vet[k]+e[i]+"\n";
				vet[index++] = vet[k]+e[i];				
			}
		}		
	}
			
	return 0;	
}
#endif
