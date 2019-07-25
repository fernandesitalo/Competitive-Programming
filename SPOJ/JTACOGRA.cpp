#include<stdio.h>

int main(void){
	int d= 0; // distancia inicial igual a zero
	int n,t,v,i;
	
	scanf("%d",&n);
	
	for(i=0 ; i<n ; i++){
		scanf("%d%d",&t,&v);
		
		d += t*v;
	}
	
	printf("%d",d);
	
	return 0;
}
