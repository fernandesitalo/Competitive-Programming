#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e5+100;

int v[maxn];
int L_id[maxn];
int P[maxn];


int main(){
	//~ freopen("in","r",stdin);
	int t;
	cin>>t;
	getchar();
	getchar();
	
	string s;
	int x;
	
	bool p = 0;
	while(t--){
		
		
		if(p){
			cout <<'\n';
		}
		p = 1;
		
		int n = 0;
		
		while(getline(cin,s),s[0] != '\0'){
			stringstream ss(s);
			ss>>x;
			//~ cout << x << '\n';
			v[n++] = x;
		}
		
		//~ cout << " :: " << n << '\n';
		
		vector<int> L;
		
		int lis_end = 0;
		
		for(int i = 0 ; i < n ; ++i){
			int pos = lower_bound(L.begin(),L.end(),v[i]) - L.begin();
			
			if(pos == (int)L.size()){
				L.push_back(v[i]);
				lis_end = i;
			}else{
				L[pos] = v[i]; 
			}
			
			L_id[pos] = i;
			
			P[i] = pos? L_id[pos-1] : -1; 
		}
		
		vector<int> rec;
		for(x = lis_end ; P[x] >= 0 ; x = P[x]){
			rec.push_back(v[x]);
		}
		rec.push_back(v[x]);
		reverse(rec.begin(),rec.end());
		cout <<"Max hits: " << rec.size() << '\n';
		for(auto i : rec){
			cout << i << '\n';
		}
	}
	return 0;
}
