#include <bits/stdc++.h>
using namespace std;

int const maxn = 31;

vector<int> box[maxn];

vector<int> dag[maxn];

int degree[maxn]; // grau de entrada

int n,k; // k boxes of n-dimension

bool can(int at,int to){
	for(int i = 0 ; i < n ; ++i){
		if(box[to][i] <= box[at][i]) return false;
	}
	return true;
}

void buildDag(){
	for(int i = 0 ; i < k; ++i){
		for(int j = 0 ; j < k ; ++j){
			if(i!=j){
				if(can(i,j)){
					dag[i].push_back(j);
					degree[j]++;
				}
			}
		}
	}
}

vector<int> ts;
int vis[maxn];

void tps(int u){
	vis[u] = 1;
	for(auto v : dag[u]){
		if(vis[v] == -1){
			tps(v);
		}
	}
	ts.push_back(u);
}

int pai[maxn];
int dist[maxn];

int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	
	while(cin>>k>>n){
		for(int i= 0 ;i < k ; ++i){
			box[i].clear();
			for(int j = 0 ; j < n ; ++j){
				int x;
				cin>>x;
				box[i].push_back(x);
			}
			sort(box[i].begin(),box[i].end());
			degree[i] = 0;
			pai[i] = -1;
			vis[i] = -1;
			dag[i].clear();
			dist[i] = 10000;
		}
		buildDag();
		
		vector<int> source;
		
		for(int i = 0 ; i < k ; ++i){
			if(degree[i] == 0){
				source.push_back(i);
			}
			//~ cout <<"degree["<< i << "]  = " << degree[i] << '\n';
		}
		
		vector<int> ans;
		int maxans = -1;
		for(auto u:source){
			for(int i = 0 ; i < k ; ++i) dist[i] = 10000,vis[i] = -1,pai[i]=-1;
			ts.clear();
			tps(u);
			
			reverse(ts.begin(),ts.end());
			
			int maxdist = 0;
			int id = 0;
			
			dist[u] = 0;
			//~ cout << "tps   :";
			//~ for(auto i : ts){
				//~ cout << i << " " ;
			//~ }
			//~ cout << endl;
			for(int i = 0 ; i < (int)ts.size() ; ++i){
				int at = ts[i];
				
				for(auto v : dag[at]){
					if(dist[v] > dist[at]-1){
						pai[v] = at;
						dist[v] = dist[at]-1;
					}
				}
			}
		
			//~ for(int i = 0 ; i < k ; ++i){
				//~ cout << "dist["<<i<<"] = " << dist[i] << '\n';
			//~ }
			
			for(int i = 0 ; i < k ; ++i){
				if(dist[i] != 10000 && -dist[i] > maxdist){
					maxdist = -dist[i];
					id = i;
				}
			}
			
			if(maxdist > maxans){
				ans.clear();
				for(int at = id ; at != u ; at = pai[at]){
					ans.push_back(at);
				}ans.push_back(u);
				maxans = maxdist;
			}
		}
		
		reverse(ans.begin(),ans.end());
		
		//~ cout << "K " << k << n <<"\n";
		cout << ans.size() << '\n';
		for(int i = 0 ;i < (int)ans.size() ; ++i){
			if(i) cout << " ";
			cout << ans[i]+1;
		}cout << '\n';
	}
	
	return 0;
}
