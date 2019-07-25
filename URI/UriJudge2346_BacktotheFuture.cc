#include <bits/stdc++.h>
#define deb puts("debug")
using namespace std;

typedef pair<int,int> ii;

/*
	URI 2346 -- BACK THE FUTURE
	
	e dada uma descricao onde metais sao combinados....
	pra ser valido um metal, ele deve ser compativel com pelo menos 'A' metais 
	e ser incompativel com pelo menos 'B' metais
	
	a jogada mestra e fazer um set <grau,node> entao vamos pegando os primeiros ate nao dar 
	para pegar mais... e dps vamos pegandos os ultimos ate nao dar para pegar mais
	
	os primeiros vamos verificar se seu grau e menor que 'A'
	
	os ultimos vamos verificaer se (NumVertices-1)-seu grau e menor que 'B'
	* sendo (NumVertices-1) a quantidade de incompatibilidades possiveis e 'seu grau' o numero de compatibilidades possiveis
	
	estaremos fazendo o seguinte : detectando e excluindo todos os vértices inválidos.
*/



int main(){
	
	//~ freopen("in","r",stdin);
	
	int a,b,i,n,m,u,v;
	
	scanf(" %d %d %d %d",&n,&m,&a,&b);
	
	set<int> G[n+1]; // meu grafo
	
	while(m--){
		scanf(" %d %d",&u,&v);
		G[u-1].insert(v-1); 
		G[v-1].insert(u-1);
	}
	
	set<ii> s; // otimizacao <grau,no do grau>.. set de ordenacao pelo grau
	
	for(i = 0 ; i < n ; ++i){
		if(G[i].size() > 0)
			s.insert(ii( G[i].size() , i ));
	}
	
	while(s.size() > 0){ // verifica os menores graus... vamos tirar todos que tem grau menor que 'A'
		
		ii x = *s.begin(); //< grau,node>

		if( a > x.first){ // deletar esse vertice 
			s.erase(x);
			
			for(auto it : G[x.second] ){ // passa por todos vizinhos excluindo os que nao sao de interesse 
				int v = it; 
				
				s.erase(ii(G[v].size(),v));
				G[v].erase(x.second);
				
				if((int)G[v].size() > 0){
					s.insert(ii(G[v].size(),v));
				}
			}			
			G[x.second].clear();	
		}else break;
	}
		
	while(s.size() > 0){
		ii x = *s.rbegin();
		
		int nv = s.size(); // numero de vertices .. nv-1 e a quantidade de incompatibilidades possivel
		
		if(b > (nv-1-x.first)){ // temos que retirar esse vertice
				s.erase(x);

				for(auto it : G[x.second] ){ // passa por todos vizinhos excluindo os que nao sao de interesse 
					int v = it;
					
					s.erase(ii(G[v].size(),v));
					G[v].erase(x.second);
					
					if(G[v].size() > 0){
						s.insert(ii(G[v].size(),v)); // coloco dnv se seu grau ainda e valido, isto é maior que zero
					}					
				}
				G[x.second].clear(); // zera o vertice pq exclui ele
		}else break;	
	}
	
	cout << s.size() << '\n';
	
	return 0;
}
