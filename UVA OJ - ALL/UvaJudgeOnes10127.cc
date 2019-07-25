#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ll n;
	int i;	
	
	while(scanf(" %lld",&n)){
		ll p = 1;
		ll p1 = 1;
		for(i = 1; ; ++i){
			if(p1 % n == 0) break;
			p *= 10;
			p1 = p+p1;
			//~ cerr << p << " " << p1 <<endl;
		}

		printf("%d\n",i);
	}
	return 0;
}
