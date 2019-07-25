#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
priority_queue< ii, vector<ii> ,greater<ii> > pq;
vi vis;

void process(int vtx){
	vis[vtx] = 1;
	
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[ vtx ][ j ];
		if(! vis[v.first] ) pq.push( ii(v.second,v.first) ); 
	}
} 

inline float dist(ii a, ii b){
	return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){
	//freopen("e","r",stdin);
	
	int q,n,r,ct = 1;
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d %d",&n,&r);
		
		adj.assign(n+10, vii());
		vis.assign(n+10,0);
		vi Est(n+10,-1);
		
		ii aux;
		vii vet;
	
		
		map<ii,int> indice;
		int index = 0;
		
		while(n--){
			scanf(" %lf %lf",&aux.first,&aux.second);
			
			if(indice.find(aux) == indice.end() ) 
				indice[aux] = index++;			
			vet.push_back( aux );
		}
		
		
		int estados = 0;
		
		for(vii::iterator it = vet.begin() ; it != vet.end() ; ++it){
			for(vii::iterator at = vet.begin() ; at != vet.end() ; ++at){
				if(at != it){
					float d = dist(*at,*it);
					adj[ indice[*at] ].push_back( ii(indice[*it],d) );
					adj[ indice[*it] ].push_back( ii(indice[*at],d) );					
				}
			}
		}
		
		process(0);
		
		double cost_estradas = 0;
		double cost_ferrovias = 0;
		
		int anterior = 0;
		
		while(!pq.empty()){
			double d = pq.top().first;
			double u = pq.top().second;
			pq.pop();
			
			if( !vis[u] ){
				if(d <= r) cost_estradas += d;
				else cost_ferrovias += d;
				
				if(d <= r){
					if( Est[ anterior ] != -1 ){
						Est[ u ] = Est[ anterior ];
					}
					else if(Est[ u] != -1){
							Est[anterior] = Est[ u ];	
						}
					else Est[ anterior ] = Est[ u ] = estados++;						 								 										
				}	
				else{
					if( Est[ anterior ] == -1) Est[ anterior ] = estados++;
					if( Est[ u ] == -1) Est[ u ] = estados++;
				}		
				anterior = u;
				process(u);
			} 
		}		
		printf("Case #%d: %d %.lf %.lf\n",ct++,estados,cost_estradas,cost_ferrovias);		
	}
	return 0;
}
