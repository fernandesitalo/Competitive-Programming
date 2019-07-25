#include <bits/stdc++.h>
using namespace std;

int main(){
	int qtd,a,b,c;
	scanf(" %d",&qtd);
	
	for(int i = 1 ; i <= qtd ; i++){
		scanf(" %d %d %d",&a,&b,&c);
		
		if(a > b){
			if(c > a)swap(a,c);				
		}
		else{ // a nao e o maior
			if(b > c) swap(a,b);			
			else swap(c,a);			
		}
		if(c > b) swap(b,c);	
		
		printf("Case %d: %d\n",i,b);
	}	
	return 0;
}
