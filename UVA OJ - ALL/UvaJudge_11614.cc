#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long q,n;
	scanf("%lld",&q);
	while(q--){
		scanf("%lld",&n);
		printf("%lld\n",(unsigned long long) (-1 + sqrt(1 + 8*n)) / 2);
	}
	return 0;
}
