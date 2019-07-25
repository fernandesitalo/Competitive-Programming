#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int a,b,qtd;
	scanf(" %d",&qtd);	
	while(qtd--){
		scanf(" %d %d",&a,&b);		
		printf("%d\n",(a/3)*(b/3));	
	}
	
}
