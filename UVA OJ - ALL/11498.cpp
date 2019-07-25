#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	
	int qtd,a,b,x,y;
	while(scanf(" %d",&qtd), qtd != 0){
		scanf(" %d %d",&x,&y);
		while(qtd--){
			scanf(" %d %d",&a,&b);
			
			if(a == x || b == y) printf("divisa\n");
			
			else if(b > y){ // 2 ou 4
				if(a > x) printf("NE\n");
				else printf("NO\n");
			}
			else{ // 1 ou 3
				if(a > x) printf("SE\n");
				else printf("SO\n");
			}
		}	
	}

	return 0;
}
