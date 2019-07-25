#include <bits/stdc++.h>
using namespace std;

int main(){

	int t,g,l;
	for(cin>>t;t--;){
		cin>>g>>l;
		if(l%g == 0) printf("%d %d\n",g,l);
		else puts("-1");
	}
	return 0;
}
