#include <bits/stdc++.h>
using namespace std;

int const maxn = 3e5 + 100;
int const sqmaxn = sqrt(maxn)+100;

vector<int> block[sqmaxn];
int arr[maxn];

int SQ;

inline void update(int pos, int value){
	int nb = pos/SQ;
	int p = lower_bound(block[nb].begin(),block[nb].end(),arr[pos]) - block[nb].begin();
	block[nb][p] = arr[pos] = value;
	sort(block[nb].begin(),block[nb].end());
}

int query(int l, int r, int v){
	int bl = l/SQ;
	int br = r/SQ;
	int ans = 0;
	
	if(bl == br){
		for(int i = l ; i <= r ; ++i){
			if(arr[i] < v) ans++;
		}
		return ans;
	}
	
	int Li = (bl+1)*SQ;
	
	for(int i = Li-1 ; i >= l ; --i){
		if(arr[i] < v) ans++;
	}
	
	for(int i = bl+1 ; br > i ; ++i){
		
		auto it = block[i].size() - (block[i].size() - (lower_bound( block[i].begin() , block[i].end(),v) - block[i].begin())); 
		 // qtd = tam - (tam - pos)
		ans += (it);
	}
	
	Li = br*SQ;
	for(int i = r ; i >= Li ; --i){
		if(arr[i] < v) ans++;
	}
	return ans;
}


int main(){
	//~ freopen("in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0);
	int n,m,u;
	
	cin>>n>>m>>u;
	
	//~ n = 3e5;
	//~ m = 50000;
	//~ u = 100;
	
	SQ = ceil(sqrt(n));
	
	for(int i = 0 ; i < n ; ++i){
		cin>>arr[i];
		block[i/SQ].push_back(arr[i]);
	}
	for(int i = 0 ; i <= SQ ; ++i){
		sort(block[i].begin(),block[i].end()); // last block
	}
	int l,r,v,p;
	while(m--){
		cin >> l >> r >> v >> p ;
		//~ l = rand()%n;
		//~ r = rand()%n;
		//~ v = rand()%u;
		//~ p = rand()%n;
		if(l > r) swap(l,r);
		
		--l,--r,--p;		
		update(p,(long long) u * query(l,r,v) / (r-l+1));
	} 
	for(int i = 0 ; i < n ; ++i){
		cout << arr[i] << '\n'; 
	}
	return 0;
}
