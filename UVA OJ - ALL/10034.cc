#include <bits/stdc++.h>
using namespace std;

typedef pair< float , float > ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
priority_queue<ii> pq;
vi taken;

void process (int vtx){
	taken[vtx] = 1;
	
	for(int j = 0 ; j < (int) adj[vtx].size() ; ++j){
		ii v = adj[vtx][j];
		if(!taken[v.first]) pq.push( ii(  - v.second , - v.first ) );
	}
}

float dist (ii a, ii b) {
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){	
	//freopen("e","r",stdin);
	int q,n;
	
	scanf(" %d",&q);
	
	while(q--){
		scanf(" %d",&n);		
		adj.assign(n+5,vii());
		taken.assign(n+5,0);
		
		vii vet;
		ii aux;		
		map<ii,int> indice;
		float mst_cost = 0;
		int index = 0;
		
		while(n--){
			scanf(" %f %f",&aux.first,&aux.second);			
			if(indice.find(aux) == indice.end()){
				indice[aux] = index++;
			}			
			vet.push_back(aux);			
		}
		
		for(vii::iterator it = vet.begin() ; it != vet.end() ; ++it){
			for(vii::iterator at = vet.begin() ; at != vet.end() ; ++at){
				if(*at != *it){
					adj[ indice[*at] ].push_back( ii(indice[*it], dist(*at,*it) ) ); 
				}
			}			
		}		
		process(0);
		
		while(!pq.empty()){
			float u = - pq.top().second;
			float w = - pq.top().first;
			pq.pop();
						
			if( !taken[u] ) process(u),mst_cost += w;			
		}	
		
		
			
		printf("%.2f\n",mst_cost);		
		
		if(q)puts("");
	}
	
	return 0;
}
