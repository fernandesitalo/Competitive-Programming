#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	
	int atual,total,a,b,c;
	while(scanf(" %d %d %d %d",&atual,&a,&b,&c) != EOF){
	total = 0;
		if(atual < a) total += a - atual;
		else total += (40-atual) + a;
		
		if(b > a) total += b - a;
		else total += (40-b) + a;
		
		total *= 360/40;
		total += 360*3;	
			printf("%d\n",total);
	
	}

	return 0;
} 
