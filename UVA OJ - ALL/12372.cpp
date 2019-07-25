#include <bits/stdc++.h>
using namespace std;


int main(){
	int qtd;
	int aux;
	int ct = 1;
	scanf(" %d",&qtd);	
	while(qtd--){
		bool alface = true;
		scanf(" %d",&aux);
		if(aux > 20) alface = false;
		scanf(" %d",&aux);
		if(aux > 20) alface = false;
		scanf(" %d",&aux);
		if(aux > 20) alface = false;		
		printf("Case %d: ",ct++);printf(alface?"good\n":"bad\n");		
	}

	return 0;
}
