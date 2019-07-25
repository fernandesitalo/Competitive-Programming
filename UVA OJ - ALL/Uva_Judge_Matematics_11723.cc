#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int index,r,i,ct = 1;
	
	while(scanf("%d %d",&r,&i), r||i){
		
		printf("Case %d: ",ct++);
		if(i*27 >= r){
			for(index = 2 ; index < 27 ; ++index){
				if((i*index + i) >= r) break;
			}
			printf("%d\n",index);
		}
		else{		
			puts("impossible");
		}
	}
	
	
	
	return 0;
}
