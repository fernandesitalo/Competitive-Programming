#include <bits/stdc++.h>
using namespace std;

int main(){
	int qtd,total = 0,aux;
	string op;
	scanf(" %d",&qtd);	
	while(qtd--){
		cin>>op;		
		if(op == "donate")
			scanf(" %d",&aux),total+= aux;
		else printf("%d\n",total);
	}return 0;
}
