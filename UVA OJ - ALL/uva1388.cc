#include <bits/stdc++.h>
using namespace std;


int main(){
	
	cout << setprecision(4) << fixed;
	
	int n,m;
	while(cin>>n>>m){
		
		double setor1 = 360.0/n;
		double setor2 = 360.0/(n+m);
		
		double ans = 0.0;
		
		double q = setor1;
		for(double  p = setor2 ; p < 360 ; p += setor2){
			if(p == q) q += setor1;
			else if(p != q && p > q){
				ans += min(fabs(p-q),fabs(p-setor2-q))*10000.0/360.0;
				
				q += setor1;
			}
		}
		cout << ans << '\n';
	}	
	return 0;
}
