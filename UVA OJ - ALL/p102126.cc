#include <bits/stdc++.h>
using namespace std;


int main()
{
	//~ freopen("in","r",stdin);
	
	int f;
	string p;
	
	int i;
	
	bool b = 0;

	while(cin>>f){
		map<string,int> m;
		
		while(cin>>p, p != "EndOfText"){
			
			string aux;
			for(i = 0 ; p[i] ; ++i){
				if(isalpha(p[i])) aux.push_back(tolower(p[i]));
				else {
					if(aux.size() > 0) m[aux]++;
					aux.clear();
				}
			}
			if(isalpha(p[i-1])) if(aux.size() > 0) m[aux]++;
			
		}
		
		bool k = 0;
		if(b)puts(""); b = 1;
		
		for(auto it : m)
			if(it.second == f) cout << it.first << '\n', k = 1;	
		
		if(!k) puts("There is no such word.");
	}
	return 0;
}
