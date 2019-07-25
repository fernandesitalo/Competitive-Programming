#include <iostream>
#include <stdio.h>
using namespace std;

int main(){	
	int qtd;
	scanf(" %d",&qtd);
	long long a,b;
	while(qtd--){
		scanf(" %lld %lld",&a,&b);
		if(a == b) printf("=\n");
		else printf(a > b?">\n":"<\n");
	}
	return 0;
}
