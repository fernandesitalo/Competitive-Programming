#include <bits/stdc++.h>
using namespace std;


int const maxn = 1e5+100;
typedef pair<int,int> ii;

int main(){
	freopen("in","r",stdin);
	
	
	int n;
	while(cin>>n){
		
		vector<int> v(n);
		for(int i = 0 ; i < n ; ++i){
			cin>>v[i];
		}
		
		
		map< int , set<int> > mp;
		vector<int> L;
		
		vector<int> go(n);
		
		for(int i = 0 ; i < n ; ++i){
			int pos = lower_bound(L.begin(),L.end(),v[i]) - L.begin();		
			if(pos == (int)L.size()){
				L.push_back(v[i]);
				mp[(int)L.size()].insert( i );
			}else{
				L[pos] = v[i];
			}
			
			go[i] = L.size();
		}
		
		vector<int> back(n);
		
		L.clear();
		reverse(v.begin(),v.end());
		for(int i = 0 ; i < n ; ++i){
			int pos = lower_bound(L.begin(),L.end(),v[i]) - L.begin();
			if(pos == (int)L.size()){
				L.push_back(v[i]);
				
			}else{
				L[pos] = v[i];
			}
			
			back[n-1-i] = L.size();
		}
		int ans = 0;
		for(int i = 0 ; i < n ; ++i){
			
			ans = max(ans,min(go[i],back[i])*2-1);
			
		}
		
		cout << ans << '\n';
	}	
	return 0;
}
