#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
//	freopen("in","r",stdin); 
	bool p = false;
	int t,q,n;
	for(scanf(" %d",&t);t--;){
		if(p)puts(""); p = true;
		
		map<string,ii> m;
		string str;
		ii aux;
		scanf(" %d",&n);
		
		for(int i = 0 ; i < n ; ++i){
			cin >> str;
			scanf(" %d %d",&aux.first,&aux.second);
			m[str] = aux;
		}
		
		int temp;
		for(scanf(" %d",&q);q--;){
			scanf(" %d",&temp);			
			
			bool p = false;		
			
			int index = 0;
			for(map<string,ii>::iterator it = m.begin() ; it != m.end() ; ++it){				
				if(it->second.first <= temp && it->second.second >= temp){
					index++; p = true;
					str = it->first;
					if(index == 2){  p = false ;break; }
				}				
			}	
			if(p) printf("%s\n",str.data());
			else puts("UNDETERMINED");
		}	
	}
	return 0;
}
