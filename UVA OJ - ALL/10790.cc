#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long a,b;
	int ct = 1;
	
	while(scanf("%lld%lld",&a,&b),a || b){
		printf("Case %d: %lld\n",ct++,(a*b*(a-1)*(b-1))/4);
	}
	
	return 0;
}
