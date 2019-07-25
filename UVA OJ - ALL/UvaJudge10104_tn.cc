#include <bits/stdc++.h>
using namespace std;

int x,y,d;



void extendedEuclid(int a, int b){
	
	if(b == 0) {x = 1,y = 0,d = a; return;}
	extendedEuclid(b,a%b);
	
	int x1 = y;
	int y1 = x - (a/b) * y;
	
	x = x1;
	y = y1;
}


int main(){

	int a,b;
	while(scanf(" %d %d",&a,&b) == 2){
		extendedEuclid(a,b);
		printf("%d %d %d\n",x,y,d);
	}

}
