#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e5+100;

struct no{
	int kg,iq,id;
	no(){}
	no(int kg, int iq,int id) : kg(kg),iq(iq),id(id){}
	bool operator < (const no other) const{
		return (kg < other.kg || (kg == other.kg && iq < other.iq));
	}
};


bool cmp(no a, no b){
	return a.iq < b.iq;
}

int L_id[maxn];
int P[maxn];

int W[maxn];
int vis[maxn];

int main(){
	//~ freopen("in","r",stdin);
	
	vector<no> v;
	int idx = 1;
	int a,b;
	
	
	while(cin>>a>>b){
		v.push_back(no(a,b,idx));	
		idx++;
	}
	
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	for(auto i : v){
		cout << i.kg << ' ' << i.iq << '\n';
	}
	
	vector<int> L;
	int lis_end = 0;
	
	for(int i = 0 ; i < (int) v.size(); ++i){
		 
		int pos = lower_bound(L.begin(),L.end(),v[i].iq) - L.begin();
		
		if(pos == (int)L.size()){
			lis_end = i;
			L.push_back( v[i].iq );
		}else{
			L[pos] = v[i].iq;
		}
		
		L_id[pos] = i;
		P[i] = pos?L_id[pos-1]:-1;
	}
	
	vector<int> rec;
	int x = lis_end;
	for( ; P[x] >= 0 ; x = P[x]){
		rec.push_back(v[x].id);
	}
	rec.push_back(v[x].id);
	//~ reverse(rec.begin(),rec.end());
	cout << rec.size() << '\n';		
	
	for(auto i : rec){
		cout << i <<'\n';
	}
	
	
	
	return 0;
}
