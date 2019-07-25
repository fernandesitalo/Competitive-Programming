#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ii pair<int,int>
#define tri pair<double, ii>
#define vtri vector<tri>

class UnionFind {
private:
    vector<int> p, rank;
public:
   
    UnionFind( int N ) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    
    int findSet(int i)  /// QUAL O PAI DA ARESTA 'i' ??
    {
        return (p[i] == i) ? i : ( p[i] = findSet(p[i]) );
    }
    
    bool isSameSet(int i, int j) /// AS ARESTAS I E J PERTENCEM AO MESMO CONJUNTO ?
    {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) /// UNIAO DE DUAS ARESTAS...
    {
        if ( !isSameSet(i, j) )  /// SO VAI UNIR ESTAS DUAS ARESTAS SE ELAS PERTENCEREM A CONJUNTOS DIFERENTES 
        {
            int x = findSet(i), y = findSet(j); /// ACHA O PAI DE CADA ARESTA A SER UNIDA
            
			/// A UNIAO SERA FEITA PEGANDO SEMPRE O MENOR PAI E UNINDU-O AO MAIOR PAI....
            if (rank[x] > rank[y]) 
            {
				p[y] = x;	
			} 
            else 
            { // rank[y] > rank[x]
                p[x] = y;
                
                if ( rank[x] == rank[y] )
                    rank[y]++;
            }
            
        }
    }
};



inline double Kruskal(vtri &EdgeList, int V){
   
    sort(EdgeList.begin(), EdgeList.end()); /// ordena arestas para o procedimento que o algoritmo precisa
   
    double mst_cost = 0; /// CUSTO DA ARVORE GERADORA MINIMA
   
    UnionFind UF(V); /// INICIALIZA A FUNÇÃO RESERVANDO UM TAMANHO DE 'V' CELULAAS PARA A UNION FIND 
   
    int E = EdgeList.size(); /// QUANTIDADE DE ARESTAS
    
    for (int i = 0; i < E; i++) 
    { 
        pair<double, ii> front = EdgeList[i]; /// < CUSTO DA ARESTA, VERTICES QUE A ARESTA LIGA >
        
        if (!UF.isSameSet(front.second.first, front.second.second)) 
        { 
            mst_cost += front.first; /// SOMA A ARESTA PQ VAI FAZER PARTE DA ARVORE GERADORA MINIMA
            UF.unionSet(front.second.first, front.second.second);/// LIGA OS VERTICES NA UNION FIND
        }
        
    }
    return mst_cost;
}
