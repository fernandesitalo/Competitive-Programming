#include <bits/stdc++.h>
using namespace std;


int main(){
	
	
	long long a,b,aux;
	
	
	while(scanf("%lld%lld",&a,&b),a||b){
		
		if(b < a){ swap(a,b);}
	
		long long ans = 0;
		long long temp = 0;
		long long v = 0;
		long long V = 0;
		
		for(int i = a ; b >= i ; i++){
			aux = i;
			temp = 0;
			v = 0;
			
			do{
				 temp++;
				 v = max(aux,v);
				 
				if(aux%2) aux = aux*3 + 1;
				else aux /= 2;			
			}while(aux!= 1);
			
			v = max(aux,v);
			
			if(temp > ans){				
				ans = temp;
				V = i;
			}	
		}
		
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",a,b,V,ans);
	}
		return 0;
}
