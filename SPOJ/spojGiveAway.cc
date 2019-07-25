#include <bits/stdc++.h>
using namespace std;

int const maxn = 5e5+100;
int const sqmaxn = sqrt(maxn)+100;


int sq,arr[maxn];
vector<int> block[sqmaxn];

void update(int pos, int value){
	int nb = pos/sq;
	//~ arr[pos] = value;
	int p = lower_bound(block[nb].begin(),block[nb].end(),arr[pos]) - block[nb].begin();
	arr[pos] = block[nb][p] = value;
	sort(block[nb].begin(),block[nb].end());
	//~ while((int)block[nb].size() > p+1 && block[nb][p+1] < block[nb][p]) swap(block[nb][p],block[nb][p+1]),p++;
	//~ while(p > 0 && block[nb][p] < block[nb][p-1]) swap(block[nb][p],block[nb][p-1]),p--;	
}

int query(int l, int r, int c){
	
	int bl = l/sq;
	int br = r/sq;
	int ans = 0;
	
	if(bl == br){
		for(int i = l ; i <= r ; ++i){
			if(c <= arr[i]) ans++;
		}
		return ans;
	}
	
	for(int i = sq*(bl+1)-1 ;i >= l ; --i){
		if(c <= arr[i]) ans++;
	}
	for(int i = bl+1 ; br > i ;++i){
		ans += block[i].size() - (lower_bound(block[i].begin(),block[i].end(),c) - block[i].begin());
	}
	for(int i = r ; i >= br*sq ; --i){
		if(c <= arr[i]) ans++;
	}
	return ans;
}

int main(){
	
	//~ freopen("in","r",stdin);
	
	int n;
	cin>>n;
	sq = ceil(sqrt(n));
	for(int i = 0 ; i < n ; ++i){
		cin>>arr[i];
		block[i/sq].push_back(arr[i]);
	}
	for(int i = 0 ; i <= sq ; ++i){
		sort(block[i].begin(),block[i].end());
	}
	int m;
	cin>>m;
	int op,a,b,c;
	while(m--){
		cin>>op;
		if(op == 0){
			cin>>a>>b>>c;
			--a,--b;
			cout << query(a,b,c) << '\n';
		}else{
			cin>>a>>b;
			update(a-1,b);
		}
	}

	return 0;
}
