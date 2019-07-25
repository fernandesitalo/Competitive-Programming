#include <bits/stdc++.h>
using namespace std;


int main(){
	
	freopen("in","r",stdin);
	
	int i,t,n,pos;
	
	bool p = 0;
	string s;
	for(cin>>t;t--;){
		
		cin>>n;
		
		cin.ignore(100,'\n');

		vector<string> v;
		string r;
		while(getline(cin,r)){
			s += r;
			if(s.size() >= n) break;
		}
		
		if(n == 1){
			cout << n << '\n' << s<<'\n';
			continue; 
		}
		
		
		for(i = 0 ; i < n ; ++i){
			string aux = s;
			aux.erase(aux.begin(),aux.begin()+i);
			aux += string(s.begin(),s.begin()+i);
			v.push_back(aux);
		}
	
		//~ cout << ">>> " << n << endl;
		
		string a = v[1];
	
		sort(v.begin(),v.end());
		
			
		
		for(pos = 0 ; pos < n &&  v[pos] != a; ++pos)
		
		
		
		if(p) puts(""); p = 1;
		cout << pos <<'\n';
		
		for(i = 0 ; i < n ; ++i) {
			
			if (i > 0 && i % 50 == 0 && i != n - 1) cout << endl;
			
			cout << v[i][n-1];
    }
    cout << endl;
	}
	
	
	
	
	
	
	
	
	return 0;
}
