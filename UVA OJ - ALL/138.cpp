#include <bits/stdc++.h>
using namespace std;

int main(){
	int q = 0;
	for(long long am = 2 ; q < 10 ; ++am){
		double f = am*am + am;
		double c = sqrt(f/2.0);
		if(c ==(int)c){
			printf("%10.lld%10.lld\n",(long long)c,am);
			q++;
		}
	
	}
	return 0;
}
