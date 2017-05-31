/*	-= ACCEPTED =-  
 * 	UVA JUDGE 11733 - Airports  
 * 	CATEGORIA: ARVORE GERADORA MINIMA - KRUSKAL
 * 	
 * 	SOLUÇÃO: A ARVORE GERADORA MINIMA DEVE SER MONTADA ENQUANTO O PESO 
 * 	DA ARESTA FOR MENOR QUE O CUSTO DE CONSTRUIR UM NOVO AEROPORTO...
 * 	LEMBRANDO QUE O ALGORTIMO DE KRUSKAL VERIFICA AS ARESTAS EM ORDEM 
 * 	CRESCENTE, LOGO, QUANDO ENCONTRAMOS A PRIMEIRA ARESTA QUE E MAIOR
 * 	QUE O VALOR DE CONSTRUIR UM AEROPORTO, SAIMOS DO LAÇO FOR DO 
 * 	ALGORITMO DE KRUSKAL.
 *      EMAIL : italofernandes.fg@gmail.com
 *      .: BRBR
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef pair<int,ii> iii;// iii(custo da aresta, ii(incio da aresta , fim da aresta)) - kruskal
typedef vector<iii> viii; 

class UnionFind{
private:
	vi p, rank;
public:
	UnionFind(int V);
	bool isSameSet(int i, int j);
	int findSet(int i);
	void unionSet(int i, int j);
};

UnionFind::UnionFind(int V){
	p.assign(V,0);
	rank.assign(V,0);
	for(int i = 0 ; i < V ; ++i) p[i] = i;
}
int UnionFind::findSet(int i)
{ return (p[i] == i )? i : (p[i] = findSet(p[i])); }

bool UnionFind::isSameSet(int i, int j)
{ return findSet(i) == findSet(j);}

void UnionFind::unionSet(int i, int j){
	if(!isSameSet(i,j))
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


int main(){
	freopen("e","r",stdin);
	int q,a,n,m;
	scanf(" %d",&q);
	for(int ct = 1 ; ct <= q ; ++ct){
		scanf(" %d %d %d",&n,&m,&a); // n_ num de vertices 
									 // m_ num de arestas
		viii EdgesList;    			 // a_ custo para construir um aeroporto
		iii aux;
		while(m--){
			scanf(" %d %d %d",&aux.second.first,&aux.second.second,&aux.first);
			EdgesList.push_back( aux );
		}
		
		//________________________ KRUSKAL__________________________
		UnionFind UF(n+1);
		sort(EdgesList.begin() , EdgesList.end());	
		int mst_cost = 0; 		///	CUSTO DA ARVORE GERADORA MINIMA
		int NumeroDeAeroportos = n; // em todos vertices há um aeroporto no inicio		
		int E = EdgesList.size();
		for(int j = 0 ; j < E && EdgesList[j].first < a ; ++j){
			iii front = EdgesList[j];
			if(!UF.isSameSet(front.second.first,front.second.second) ){
				mst_cost += front.first;
				NumeroDeAeroportos--;
				UF.unionSet(front.second.first, front.second.second );
			}		
		}
		printf("Case #%d: %d %d\n",ct,mst_cost + a*NumeroDeAeroportos ,NumeroDeAeroportos);
	}
	return 0;
}
