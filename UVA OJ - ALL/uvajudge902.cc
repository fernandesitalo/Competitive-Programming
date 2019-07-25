#include <bits/stdc++.h>
using namespace std;


int main(){

	int n;
	string fr;
	
	//~ freopen("in","r",stdin);
	
	while(cin >> n){
		unordered_map<string,int> m;
		string ans;
		cin >> fr;
		
		int t = fr.size();
		
		for(int i = 0 ; i < t-n ; ++i){
			m[string(fr.begin()+i,fr.begin()+i+n)]++;
		}
		
		int maior = 0;
		
		for(auto it : m){
			if(it.second >= maior){
				maior = it.second;
				ans = it.first;
			}
		}
		printf("%s\n",ans.data());	
	}
	
	return 0;
}
