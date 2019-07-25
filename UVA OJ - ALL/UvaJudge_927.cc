#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int coef[MAXN];



int main(){
	
	freopen("in","r",stdin);
	
	int t,n,k,d;
	for(scanf(" %d",&t);t--;){		
		scanf(" %d",&n);
		n++;		
		for(int i = 0 ; i < n ; ++i) scanf(" %d",&coef[i]);

		scanf(" %d %d",&d,&k);
	
		
		int pos = d;
		int pp = 1; 
		while( k > d){			
			d += pos * (++pp);
		}		
		
		unsigned long long ans = 0;
		unsigned long long pot = 1;
		
		for(int i = 0 ; i < n ; ++i){
			ans += (unsigned long long ) coef[i] * pot;
			pot *= pp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
