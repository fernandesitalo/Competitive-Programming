/*	UVA JUDGE : 10600 - ACM contest and Blackout
 * 	CATEGORIA: ARVORE GERADORA MINIMA 2º MST DE MENOR CUSTO
 *	
 * 	SOLUCAO:  RODAR MST PELA PRIMEIRA VEZ E OBTER O PRIMEIRO MENOR CUSTO
 * 	E ARMAZENAR EM ANS1.
 * 	RODAR MST 'N' VEZES (N E NUMERO DE ARESTAS DA MST) IGNORANDO EM CADA VEZ UMA ARESTA PERTENCENTE A 
 *  1ª MST. ARMAZENAR EM ANS2 O VALOR MAIOR OU IGUAL QUE ANS1
 * 	
 * 	EMAIL : italofernandes.fg@gmail.com
 * 	BRBR
 **/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
#define INF 1000000

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
{ return (p[i] == i)? i :( p[i] = findSet(p[i]) );}

bool UnionFind::isSameSet(int i, int j)
{ return findSet(i) == findSet(j); }

void UnionFind::unionSet(int i, int j){
	if( !isSameSet(i,j) )
	{
		int x = findSet(i);
		int y = findSet(j);
		if(rank[x] > rank[y])
			p[y] = x;
		else{
			p[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
}

viii VerticesMST;

int kruskal(viii & EdgesList, int V){
	UnionFind UF(V);
	int mst_cost = 0;
	int E = EdgesList.size();
	for(int i = 0 ; i < E ; ++i){
		iii front = EdgesList[i];
		if(!UF.isSameSet(front.second.first,front.second.second) ){
			mst_cost += front.first;
			UF.unionSet(front.second.first,front.second.second);
			VerticesMST.push_back( front );
		}
	}
	return mst_cost;
}

int kruskal(viii& EdgesList, int V, iii IgnoraVtx){
	UnionFind UF(V);
	int mst_cost = 0;
	int E = EdgesList.size();
	for(int i = 0 ; i < E ; ++i){
		if( EdgesList[i] != IgnoraVtx ){
			iii front = EdgesList[i];		
			if(!UF.isSameSet(front.second.first,front.second.second) ){
				mst_cost += front.first;
				UF.unionSet( front.second.first , front.second.second );
			}
		}
	}
	return mst_cost;
}




int main(){
	//freopen("in","r",stdin);
	int q,n,m;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d %d",&n,&m);
		++n;
		viii EdgesList;		
		iii aux;
		while(m--){
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back( aux );
		}
		
		sort(EdgesList.begin(),EdgesList.end());
		VerticesMST.clear();
		int ans1 = kruskal( EdgesList ,n);
		int ans2 = INF;
		
		for(int h = 0 ; h < (int) VerticesMST.size() ; ++h){
			int resp = kruskal( EdgesList , n , VerticesMST[ h ]);
			if(resp >= ans1)
				ans2 = min(resp , ans2);
		}
		
		printf("%d %d\n",ans1,ans2);			
	}
	return 0;
}
