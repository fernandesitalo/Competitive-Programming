/** Autor: Ítalo Fernandes Gonçalves
 * 
 * 	UVA JUDGE 908 - Re-connecting Computer Sites
 *  CATEGORIA: ARVORE GERADORA MINIMA
 * 
 * 	SOLUCAO: INTERPLETACAO DO PROBLEMA SEGUIDO DE APLICAÇÃO DIRETA DE MST
 * 	SERVE TANTO KRUSKAL COMO O PROPRIO PRIM.
 * 
 * 	Email: italofernandes.fg@gmail.com
 **/
 
#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

struct UnionFind{
private:
	vi p,rank;
public:
	UnionFind( int V);
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
{ return (p[i] == i)? i: (p[i] = findSet(p[i])); }

bool UnionFind::isSameSet(int i, int j)
{ return findSet(i) == findSet(j);}

void UnionFind::unionSet(int i, int j){
	if(!isSameSet(i,j)){
		int x = findSet(i);
		int y = findSet(j);
		if(rank[x] > rank[y])	
			p[x] = y;
		else{
			p[y] = x;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
}


int kruskal(viii&EdgesList, int V){
	sort(EdgesList.begin(), EdgesList.end());
	int mst_cost = 0;
	UnionFind UF(V);
	int E = EdgesList.size();
	for(int i = 0 ; i < E ; i++){
		iii front = EdgesList[i];
		if(!UF.isSameSet(front.second.first,front.second.second)){
			mst_cost += front.first;
			UF.unionSet(front.second.first,front.second.second);
		}
	}
	return mst_cost;
}



int main(){
	//freopen("in","r",stdin);
	
	bool line = false;
	iii aux;
	int q,cost,ans1,ans2,K,M,qtdVertices;
	while(scanf(" %d",&q)!= EOF){  // primeiro conjunto T , a arvore geradora minima inicial
		ans1 = 0;
		for(int i = 1 ; i < q ; ++i){
			scanf("%*d %*d %d",&cost); // .: Somar os custos e temos a MST
			ans1 += cost;
		}
		
		if(line) puts("");
		line = true;
		
		scanf(" %d",&K);
		qtdVertices = K;
		viii EdgesList;
		for(int i = 0 ; i < q ; ++i){ // conjunto de K novas arestas 
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back(aux);
		}
		scanf(" %d",&M);
		qtdVertices += M;
		for(int i = 0 ; i < M ; ++i){ // conjunto de M arestas originalmentes pertencentes a grafo
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back(aux);
		}
		
		ans2 = kruskal(EdgesList,qtdVertices+1); // execulta Kruskal... aplicação direta
		printf("%d\n%d\n",ans1,ans2);
				
	}

	return 0;
}
