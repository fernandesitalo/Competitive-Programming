#include <bits/stdc++.h>
using namespace std;


int main(){
	double r,n;
	int s;
	int ct = 1;
	while(scanf("%lf%lf",&r,&n), r||n){		
		s = (int)ceil((r/n) - 1);
		
		printf("Case %d: ",ct++);		
		
		if((s*n + n >= r && s <= 26) || n >= r) printf("%d\n",s);
		else puts("impossible");		
	}
	return 0;
}
