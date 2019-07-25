/*	UVA JUDGE 10369 - Arctic Network
 * 	CATEGORIA DO PROBLEMA: MINIMUM SPANNING FOREST
 * 
 * 	PROBLEMA: DADO O NUMERO DE POSTOS AVANÇADOS COM CANAL VIA SATELITE
 * 	DEVEMOS DETERMINAR D, A DISTANCIA MINIMA PARA A LIGAÇÃO DE RADIO...
 * 	
 * 	SOLUCAO: KRUSKAL. NO INICIO DO ALGORITMO DE KRUSKAL, CADA VERTICE 
 * 	IRÁ REPRESENTAR UMA COMPONENTE CONEXA, A CADA UNIAO FEITA 
 * 	(DENTRO DO LAÇO FOR DO ALGORITMO DE KRUSKAL) DIMINUI-SE UMA COMPONENTE
 * 	CONEXA...
 * 	LOGO, QNDO SE RESTANREM 's' VERTICES, OU MELHOR, 's' COMPONENTES
 * 	CONEXAS, PARAMOS DE EXECULTAR O ALGORITMO DE KRUSKAL, E A RESPOSTA SERÁ
 * 	O VERTICE ATUAL...
 * 	COMO E DADO O NUMERO TOTAL DE VERTICES, E O NUMERO DE COMPONENTES QUE 
 * 	QUEREMOS, DESCOBRIMOS O VALOR DE 's' da seguinte maneira:
 * 	's' = NUM TOTAL DE VERTICES - NUM DE COMPONENTES...
 * 	PORTANTO, REALIZAREMOS 's' UNIOES, ATE QUE SE CHEGUE A RESPOSTA COM O
 * 	NUMERO DESEJADO DE COMPONENTES CONEXAS
 * 
 * 	Autor: Ítalo Fernandes Gonçalves
 * 	Email: italofernandes.fg@gmail.com  	 
 * */


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
	UnionFind(int N){ // construtor
		p.assign(N,0);
		rank.assign(N,0);
		for(int i = 0 ; i < N ; ++i) p[i] = i;
	}
	
	int findSet(int i)
	{ return (p[i] == i)? i : ( p[i] = findSet(p[i]) ); }
	
	bool isSameSet(int i, int j)
	{ return (findSet(i) == findSet(j)); }
	
	void unionSet(int i, int j){
		if( !isSameSet(i,j) )
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

double kruskal(vector<dii> &edges, int V, int var){
	sort(edges.begin(),edges.end());
	UnionFind UF(V);
	double ans = 0;
	for(int i = 0 ; i < (int) edges.size() ; ++i){
		dii v = edges[i];
		if( !UF.isSameSet( v.second.first , v.second.second) ){ // SE OS PAIS FOREM DIFERENTES, TACA NA MST...
			
			var--;
			if(!var) return v.first;
			
			ans = v.first;
			UF.unionSet(v.second.first  , v.second.second); 
		}
	}
	return ans;
}

int main(){
	int q,s,p;
	scanf(" %d",&q);
	while(q--){
		scanf(" %d %d",&s,&p); // s_numero de satelites    p_numero de postos avançados		
		vector< dii > edges; 
		vii vet; // poderia armazenar numa matriz[n][2]... acesso mais rapido e menos confuso 		 
		ii aux;
		for(int i = 0 ; i < p ; ++i){ // leitura das arestas
			scanf(" %d %d",&aux.first,&aux.second); 
			vet.push_back( aux );			
		}
		
		// modelando o grafo para o kruskal, .: vector<dii(peso da aresta, ii( inicio da aresta, fim da aresta))>
		for(int i = 0 ; i < p ; ++i)
			for(int j = i+1 ; j < p ; ++j){
				double w = hypot(vet[i].first - vet[j].first , vet[i].second - vet[j].second );
				edges.push_back( dii( w , ii(i,j) ) );
			}
						
		printf("%.2lf\n",kruskal( edges ,p , p - s ));	
	}	
	return 0;
}
