#include <bits/stdc++.h>
using namespace std;


int main(){

	long long v[100];
	v[1] = v[2] = v[3] = 1;
	
	for(int i = 4 ; i < 65 ; ++i){
		v[i] = v[i-1]+v[i-2]+v[i-3];
	}
	
	int ct  = 1;
	int n;
	while(cin>>n,n){
		
		cout << "Case " << ct++ << ": " << v[n] << '\n';
	}
	
	return 0;
}
