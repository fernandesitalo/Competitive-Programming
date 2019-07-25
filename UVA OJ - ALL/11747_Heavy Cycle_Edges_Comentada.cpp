/*	UVA JUDGE : 11747 - Heavy Cycle Edges
 * 	CATEGORIA : ARVORE GERADORA MINIMA - KRUSKAL
 * 	
 * 	REQUISITOS: UNION FIND/ KRUSKAL/ MST
 * 
 * 
 * 	SOLUCAO : APLICAÇÃO DIRETA DO ALGORITMO DE KRUSKAL
 * 	IMPRESSAO DAS ARESTAS QUE NAO ESTAO NA MST...
 * 	DEVE-SE IMPRIMIR EM ORDEM CRESCENTE, DE ACORDO COM QUE 
 * 	O ALGORITMO FUNCIONA, ELE DESCARTA AS ARESTAS QUE NAO ESTAO NA 
 * 	MST, ENTAO E SO IMPRIMI-LAS!... CASO NAO TEHA NENHUMA ARESTA
 * 	IMPRIMIR 'forest'. 
 * 	
 * */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii > iii;

class UnionFind{
private:
	vi p,rank;
public:
	
	UnionFind(int N){
		p.assign(N,0);
		rank.assign(N,0);
		for(int i = 0 ; i < N ; ++i) p[i] = i;
	}
	
	int findSet(int i)
	{ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	
	bool isSameSet(int i , int j)
	{ return findSet(i) == findSet(j);}
	
	void unionSet(int i, int j){
		if(!isSameSet(i,j))
		{
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




int main(){
	int n,m;
	while(scanf(" %d %d",&n,&m), n||m){
		
		vector<iii> EdgesList;
		
		iii aux;
		for(int y = 0 ; y < m ; ++y){	
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back(aux);
		}
		
		/// kruskal begin
		bool alface = true;
		UnionFind UF(n);
		int mst_cost = 0;
		sort(EdgesList.begin(), EdgesList.end());
		int E = EdgesList.size();
		for(int i = 0 ; i < E ; ++i){
			iii front = EdgesList[i];
			if(!UF.isSameSet(front.second.first,front.second.second))
			{
				mst_cost += front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
			else{
				if(!alface) printf(" ");
				
				printf("%d",front.first);
				alface = false;
			}
		}
		
		if (alface) puts("forest");
		else puts("");
	}
	return 0;
}
