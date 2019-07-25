#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
priority_queue<ii,vector<ii>,greater<ii> > pq;
vi vis;

void process(int vtx){
	//vis[vtx] = 2; testando commit git - esta eh uma alteracao
	vis[vtx] = 1;
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!vis[v.first]) pq.push( ii(v.second,v.first) );
 	}
}

inline double dist(ii a, ii b){ return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) ); }

int main(){
	//freopen("j","r",stdin);
	
	int n;
	double v1,v2;
	
	while(scanf(" %d",&n)!= EOF){
		
		adj.assign(n+3,vii());
		vis.assign(n+3,0);
		map<ii,int> indice;
		int index = 0;	
		
		ii aux;
		
		vector<ii> vet;
		
		while(n--){
			scanf(" %lf %lf",&aux.first,&aux.second);
			indice[aux] = index++;
			vet.push_back( aux );
			
		}
		
		scanf(" %d",&n);
		while(n--){
			scanf("%lf %lf",&v1,&v2);
			adj[v1-1].push_back( ii(v2-1,0) );
			adj[v2-1].push_back( ii(v1-1,0) );
		}
		
		for(vii::iterator it = vet.begin() ; it!=vet.end() ;++it){
			for(vii::iterator at = vet.begin() ; at!= vet.end() ;++at){
				if(at != it){
					double d = dist(*it,*at);
					adj[ indice[*it] ].push_back( ii(indice[*at], d) );
					adj[ indice[*at] ].push_back( ii(indice[*it], d) );
				}				
			}
		}
		
		process(0);
	
		double mst_cost = 0; 
		while(!pq.empty()){
			double d = pq.top().first;
			double u = pq.top().second;
			pq.pop();
			if(!vis[u]){
				process(u);
				mst_cost += d;
			}
		}
		
		
		printf("%.2lf\n",mst_cost);
		
		
	}



}
