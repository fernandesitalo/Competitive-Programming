#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	double d,u,v;
	scanf(" %d",&q);
	for(int ct = 1 ; ct <= q ; ++ct){		
		scanf("%lf %lf %lf",&d,&v,&u);
		printf("Case %d: ",ct);
		if(!v || !u || v >= u) {puts("can't determine");continue;}	
		double t1 = d/u;
		double t2 = d/(sqrt(u*u - v*v));
		printf("%.3lf\n",fabs(t1-t2));
	}
	return 0;
}
