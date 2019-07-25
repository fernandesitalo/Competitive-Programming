#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int f(int n,int k,int at){ // n qtd de pessoas, k e o salto...
	
	vector<int> r;
	for(int i = 1 ; i <= n ; ++i) r.pb(i);
	
	while(r.size() > 1){
		int kill = (at + k%(r.size()))%(r.size());
		
		int enterra = (kill+k%(r.size())%(r.size()));
		
		cerr << "morre = " << r[kill] << " assume " << r[enterra] <<endl;
		
		swap(r[kill],r[enterra]);
		
		r.erase(r.begin() + enterra);
		
		at = kill;
	}
	
	return r[0];
}





int main(){
	
	//~ freopen("in","r",stdin);
	
	int n,k;
	
	for(;cin>>n>>k && n && k;){
		
		
		f(n,k-1,0);
		
	}
	return 0;
}
