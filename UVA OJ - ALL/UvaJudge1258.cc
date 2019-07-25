#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> p;
#define f first
#define s second 
ull M; // maximo
ull seq[1000];
vector<p> ans;

void F(ull number){
	ull sum = number;
	for(int i = M ; i > 0 ; --i){
		if(seq[i]<= sum){
			sum -= seq[i];
			ans.push_back(p(i,seq[i]));
			if(!sum) return;
		}
	}
}



int main(){

	
	seq[1] = 1,seq[2] = 2;
	M = 90;
	for(int i = 3 ; i < 91 ; ++i){
		seq[i] = seq[i-1] + seq[i-2];
	}	
	ull n;
	while(cin>>n){
		ans.clear();
		F(n);
		cout << n << '\n';		
		for(int i = 0 ; i < (int)ans.size() ; ++i){
			cout << ans[i].f<< " ";
		}cout << '\n';
		for(int i = 0 ; i < (int)ans.size() ; ++i){
			cout << ans[i].s << " ";
		}cout << "\n\n";
	}
	
	

	
	return 0;
}
