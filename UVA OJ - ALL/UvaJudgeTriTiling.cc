#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 50

ll pd[N];

ll CONT(int n){
	if(n == 0) return 1ll;
	if(n < 0) return 0ll;	
	if(pd[n] != -1) return pd[n];
	
	ll temp = 0;
	
	for(int i = 6 ; n >= i ; i+=2)
	temp += 2*CONT(n-i);
	
	return pd[n] = temp + 2*CONT(n-2) + 2*CONT(n-4) + CONT(n-2);
}


int main(){
	int n;
	memset(pd,-1,sizeof pd);
	while(scanf(" %d",&n), n != -1) printf("%lld\n",CONT(n));
	return 0;
}
