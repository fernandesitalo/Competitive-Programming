#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("in","r",stdin);

	int i,n,k,aux;
	string m;
	while(cin>>n,n){
		int v[n+1];
		for(i = 0 ; i < n ; ++i) scanf(" %d",&aux),v[aux-1] = i;
		
		while(scanf(" "),getline(cin,m),m[0] != '0'){
			
			k = 0;
			
			for(i = 0 ; m[i] != ' ' ; ++i) k*=10,k+=m[i]-'0';

			string ax;
			for(int j = i+1 ; m[j] ; ++j) ax.push_back(m[j]);
			m = ax;
			
			for(i = m.size() ; i < n ; ++i)  m.push_back(' ');
			
			int cont = 1;
			
			set<string> s;
			
			string cnj[n+2000];
			cnj[0] = m;
			s.insert(m);
			
			int tam = k;
			
			while(k--){
				string mx;
				for(i = 0 ; i < n ; ++i) mx.push_back(' ');
				for(i = 0 ; i < n ; ++i) mx[i] = m[v[i]];				
				m = mx;
				//~ cout << m << endl;
				if(s.find(m) != s.end()) break;
				
				s.insert(mx);
				cnj[cont++] = m;
			}
			
			if(k == 0) cout << m << endl;
			else{
			
				k = tam%s.size();
				cout << "::::::::::: "  << tam <<" " << s.size() << " "<<  k << endl;
				cout << cnj[k] <<endl;
				
			}
			
		}
		cout << '\n';
	}

	return 0;
}
