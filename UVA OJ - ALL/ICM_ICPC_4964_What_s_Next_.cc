/**	ACM-ICPC 4964 - What’s Next?
 * 	Verificar se uma sequencia de 3 numeros formam uma PA ou
 * 	uma PG... . E ainda decidir qual o proximo termo da sequencia...
 * 	
 **/
 

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a1,a2,a3;	
	while(scanf("%d %d %d",&a1,&a2,&a3),a1||a2||a3){
		if( (a3-a2) == (a2-a1) ){
			printf("AP %d\n",a3 + (a2-a1));			
		}
		else{
			printf("GP %d\n",a3*(a2/a1));
		}	
	}
	return 0;
}
