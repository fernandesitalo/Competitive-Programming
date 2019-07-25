/**  UVA JUDGE 1208 - Oreon
 * 	 CATEGORIA: MST - ARVORE GERADORA MINIMA
 * 	
 *   SOLUCAO - APLICAÇÃO DIRETA DO ALGORITMO DE KRUSKAL,
 *   CADA ARESTA ADICIONADA NA MST É IMPRIMIDA COMO MOSTRA
 *   A SAIDA ... "INICIO-FIM CUSTO"
 * 
 *   Autor: Ítalo Fernandes
 * 	 Email: italofernandes.fg@gmail.com
 **/
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
	UnionFind(int V){
		rank.assign(V,0);
		for(int i = 0 ; i < V ; ++i) p.push_back(i);
	}
	
	int findSet(int i)
	{ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
	
	void unionSet(int i, int j){
		int x = findSet(i);
		int y = findSet(j);
		if(x != y){ // PAIS DIFERENTES	
			if(rank[x] > rank[y]) p[x] = y;
			else{
				p[y] = x; // maior recebe menor
				if(rank[x] == rank[y]) rank[y]++;
			} 
		}
	}
	
};


int main(){
	freopen("in","r",stdin);
	
	int q,ct = 1,n;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d",&n);
		
		viii EdgesList;
		iii aux;
		for(int i = 0 ; i < n ; i++){
			aux.second.first = i;
			for(int j = 0 ; j < n-1 ; ++j){
				scanf("%d%*c",&aux.first);
				if(aux.first){
					aux.second.second = j;
					EdgesList.push_back( aux );
				}
			}
			scanf(" %d",&aux.first);
			if(aux.first){
					aux.second.second = n-1;
					EdgesList.push_back( aux );
			}
			
		}
		
		printf("Case %d:\n",ct++);
		
		int pai_1,pai_2;
		//______ KRUSKAL____
		sort(EdgesList.begin(),EdgesList.end());
		UnionFind UF(n+1);
		int E = EdgesList.size();
		for(int i = 0 ; i < E ; ++i){
			iii front = EdgesList[i];
			
			pai_1 = UF.findSet(front.second.first);
			pai_2 = UF.findSet(front.second.second);
			
			if(pai_1 != pai_2){
				printf("%c-%c %d\n",front.second.first + 'A',front.second.second + 'A',front.first);
				UF.unionSet(front.second.first,front.second.second);
			}		
		}	
	}
	return 0;
}
