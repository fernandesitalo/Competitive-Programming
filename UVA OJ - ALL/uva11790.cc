#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5+100;


int ft[maxn];

int N;

int query(int i){
	int r = 0;
	for(; i ; i -= i&-i){
		r = max(r,ft[i]);
	}
	return r;
}
void update(int i,int value){
	for(; N > i ; i += i&-i){
		ft[i] = max(ft[i],value);
	}
}

int main(){
	//~ freopen("in","r",stdin);
	
	int t;
	cin>>t;
	int ct =  1;
	while(t--){
		int n;
		cin>>n;
		vector<int> h(n),w(n);
		set<int> s;
		
		for(int i = 0 ; i < n ; ++i){
			cin>>h[i];
			s.insert(h[i]);
		}
		
		for(int i = 0 ; i < n ; ++i){
			cin>>w[i];
		}
		
		map<int,int> mp;
		int cnt = 1;
		for(auto i : s){
			mp[i] = cnt++;
		}
		N = cnt + 10;
		for(int i = 0 ; i < n ; ++i){
			h[i] = mp[h[i]];
		}
		memset(ft,0,sizeof ft);
		long long incr = 0;
		for(int i = 0 ; i < n ; ++i){
			long long temp = query(h[i]-1) + w[i];
			incr = max(incr,temp);
			update(h[i],temp);
		}
		
		reverse(h.begin(),h.end());
		reverse(w.begin(),w.end());
		
		memset(ft,0,sizeof ft);
		long long decr = 0;
		for(int i = 0 ; i < n ; ++i){
			long long temp = query(h[i]-1) + w[i];
			decr = max(decr,temp);
			update(h[i],temp);
		}
		
		if(incr >= decr){
			printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",ct++,incr,decr);
		}else{
			printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",ct++,decr,incr	);
		}
	}
	return 0;
}
