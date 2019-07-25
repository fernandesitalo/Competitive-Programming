#include <bits/stdc++.h>
using namespace std;
int main(){
/*
"Multiplicar n por 567, em seguida, dividir o resultado por 9, em seguida, 
adicionar 7492, em seguida, multiplicar por 235, em seguida, dividir
Por 47, então subtraia 498. Qual é o dígito na coluna de dezenas? "
*/

	int qtd,n;
	scanf(" %d",&qtd);
	while(qtd--){
		scanf(" %d",&n);
		
		long long aux = (((n*567/9) + 7492) * 235)/47 - 498;
		
		printf("=> %lld\n",aux);
		printf("%lld\n",abs((aux/10)%10));
		
	}

}
