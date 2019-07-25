#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

bool cmp(ii a, ii b){
	if(a.second == b.second) return (a.first > b.first);
	return (a.second < b.second);
}

int main(){
	//~ freopen("in","r",stdin);

	string s;
	int i,p = 0;
	
	while(getline(cin,s)){
		if(p) puts(""); p = 1;
		
		map<int,int> m;
		
		for(i = 0 ; s[i] ; ++i)	m[s[i]]++;
		
		vector<ii> f;
		for(map<int,int>::iterator it = m.begin() ; it != m.end() ; ++it){
			f.push_back(ii(it->first,it->second));
		}
		
		sort(f.begin(),f.end(),cmp);
		
		for(i = 0 ; i < (int) f.size() ; ++i){
			cout << f[i].first << " " << f[i].second << '\n';
		}
	}
	
	return 0;
}
