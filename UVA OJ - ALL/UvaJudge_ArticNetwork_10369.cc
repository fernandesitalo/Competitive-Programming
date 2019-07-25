#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<ii> vii;

class UnionFind{
private:
	vi p,rank;
public:

	//----------------------------------------------------
	UnionFind(int N){ // construtor
		p.assign(N,0);
		rank.assign(N,0);
		for(int i = 0 ; i < N ; ++i) p[i] = i;
	}
	
	//----------------------------------------------------
	int findSet(int i)
	{ return (p[i] == i)? i : ( p[i] == findSet(p[i]) ); }
	
	//----------------------------------------------------
	bool isSameSet(int i, int j)
	{ return ( findSet(i) == findSet(j) );}
	
	//----------------------------------------------------
	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x = findSet(i);
			int y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	
	
};

int s;

double kruskal(vector<dii> &edges, int V){
	
	sort( edges.begin() , edges.end() );
	
	UnionFind UF(V);
	
	for(int i = 0 ; i < (int) edges.size() ; ++i){
		dii v = edges[i];
		if( !UF.isSameSet( v.second.first , v.second.second) ){ /// verifica se os vertices desta arestas já nao pertencem ao mesmo conjunto
			s--;
			if( !s ){
				return v.first;
			}
			UF.unionSet(v.second.first  , v.second.second); /// FAZ A UNIAO DOS VERTICES
		}
	}
	return 0.1;
}





int main(){
	int q,n;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d %d",&s,&n); // s_numero de satelites    n_numero de postos avançados
		
		s = n-s;
		
		vector< dii > edges;
		map<ii,int> indice;
		int index = 0;
		vii vet; 
		
		ii aux;
		int a = n;
		while(a--){
			scanf(" %d %d",&aux.first,&aux.second);
			indice[aux] = index++;
			vet.push_back( aux );			
		}
		
		for(vii::iterator it = vet.begin() ; it != vet.end() ; ++it){
			for(vii::iterator at = vet.begin() ; at != vet.end() ; ++at){
				if(at != it){
					double d = hypot( it->first - at->first , it->second - at->second );					
					edges.push_back( dii ( d , ii(indice[*it],indice[*at]) ) );
				}
			}
		}		
		printf("%.2lf\n",kruskal( edges , n ));	
	}	
	return 0;
}
