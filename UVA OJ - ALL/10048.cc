#include <bits/stdc++.h>
using namespace std;

//#define rep(i_,TAM) for(int i_ = 0 ; i_ < TAM ; ++i_)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;



vector<vii> adj; 
priority_queue<ii,vector<ii>,greater<ii> > pq;
vi vis;


void process(int vtx){
	vis[vtx] = 1;
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!vis[v.first]) pq.push( ii(v.second,v.first) );
		else{
			adj[vtx].erase(adj[vtx].begin() + j);
			--j;
			for(int i = 0 ; i < (int) adj[j].size() ; ++i){
				if(adj[j][i].first == vtx){
					adj[j].erase(adj[j].begin()+i);
					break;
				}
			}
		}
	}
}


int main(){
	int ct = 1,c,s,q;
	
	while(scanf(" %d %d %d",&c,&s,&q),c||s||q){
		adj.assign(c+10,vii());
		vis.assign(c+10,0);
		
		int v1,v2,cost;
		while(s--){
			scanf("%d %d %d",&v1,&v2,&cost);
			adj[v1].push_back( ii(v2,cost) );
			adj[v2].push_back( ii(v1,cost) );
		}
	}
	

	return 0;
}
