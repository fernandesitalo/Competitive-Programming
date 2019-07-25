#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<iii> viii;

class UnionFind{
private:
	vi p,rank;
public:
	UnionFind(int V);
	int findSet(int i);
	bool isSameSet(int i, int j);
	void unionSet(int i, int j);
};

UnionFind::UnionFind(int V){
	p.assign(V,0);
	rank.assign(V,0);
	for(int i = 0 ; i < V ; ++i) p[i] = i;
}

int UnionFind::findSet(int i)
{ return (p[i] == i)? i : (p[i] = findSet(p[i]));}

bool UnionFind::isSameSet(int i, int j)
{ return findSet(i) == findSet(j);}

void UnionFind::unionSet(int i, int j){
	if( !isSameSet(i,j) ){
		int x = findSet(i);
		int y = findSet(j);
		if(rank[x] > rank[y])
			p[x] = y;
		else{
			p[y] = x;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
}

int main(){
	freopen("in","r",stdin);
	int q,n,m;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d %d",&n,&m);
		viii EdgesList;
		iii aux;
		
		while(m--){
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back( aux );
		}
		// __________________________KRUSKAL_______________________________
		sort(EdgesList.rbegin() , EdgesList.rend() );
		int mst_cost = 0;
		UnionFind UF(n+1);
		int E = EdgesList.size();
		for(int i = 0 ; i < E ; ++i){
			iii front = EdgesList[i];
			if(!UF.isSameSet(front.second.first,front.second.second) ){
				UF.unionSet(front.second.first,front.second.second);
			}
			else mst_cost += front.first;
		}
		printf("%d\n",mst_cost);
	}
	scanf("%*d");
	return 0;
}
