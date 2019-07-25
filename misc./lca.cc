#include <bits/stdc++.h>
using namespace std;
#define maxn 50001
#define log_maxn 30
#define pb push_back
#define abre freopen("in","r",stdin);
#define sz(y_) (int) y_.size()
vector<int> G[maxn];

int h[maxn];// altura de cada vertice
int pai[maxn][log_maxn];
int N; // numero de vertices

void dfs(int u, int p){
	pai[u][0] = p; // pai do vertice u a uma altura de 2⁰ = 1;
	for(int i = 0 ; i < sz(G[u]) ; ++i){
		int v = G[u][i];
		if(v != p){
			h[v] = h[u] + 1;
			dfs(v,u);
		}
	}	
}

void calc(){
	// i = 0   .:  2⁰ = 1    meu pai a uma altura 1
	// i = 1   .:  2¹ = 2		' '				  2
	// i = 2   .:  2² = 4       ' '				  4
	for(int i = 1 ; i < log_maxn ; ++i){
		for(int u = 0 ; u < N ; ++u){ //  N e o numero de vertices
			int p1 = pai[u][i-1];      
			int p2 = pai[ p1 ][ i-1 ]; // O pai do meu pai.... meu pai é 'pai[u][i-1]', o pai dele é pai[ pai[u][i-1] ][i-1].....
			pai[u][i] = p2;   /// logo esse e meu pai a uma altura (2^i)
		}
	}
}


int lca(int x, int y){ // lca do vertice x e do vertice y
	
	// x sempre vai ter a altura maior
	
	if(h[y] > h[x]) swap(x,y);
	
	
	int dist = h[x] - h[y]; // essa e a diferença de altura entre os vertices
	
	// vamos subir o vertice x ate a altura h[y]... imaginemos a arvore de cabeça para baixoooo sempre
	
	for(int i = 0 ; i < log_maxn ; ++i){
		if(dist & (1<<i)){ // vamos subir o log da distancia... ou seja... os  bits ativos da distancia
			x = pai[x][i];
		}
	}
	
	if(x == y) return x; // y era mais alto que x e era ancestral de x.. logo ele e o proprio lca..
	
	
	
	// enquanto for diferente, vamos subir o vertice...
	// se for igual.. tamo no caminho certo
	// primeiro sobe para o pai a uma altura 2^i
	// dele podemos subir para o pai dele que esta a uma altira 2^(i-1)
	// assim por diante ate parar em um nivel abaixo do lca de (x,y)
	
	for(int i = (log_maxn-1) ; i > -1; --i){
		if(pai[x][i] != pai[y][i]){ //  x e y vao estar no primeiro nivel abaixo de seu lca....
			x = pai[x][i];			// .: temos que retornar o pai desse nivel....
			y = pai[y][i];
		}
	}
	return pai[x][0];
}


int raio[maxn]; //raio acumulado 
int ans[maxn];

int dfs_ans(int u, int p){
	int att = raio[u];
	for(int i = 0 ; i < sz(G[u]) ; ++i){
		int v = G[u][i];
		if(v != p){
			att += dfs_ans(v,u);
		}
	}
	return ans[u] = att;
}

/*
1
9
0 1
1 2
2 3
2 4
2 7
7 8
7 6
6 5
5
1 4 10
3 5 3
0 8 5
1 6 10
4 4 100
*/


int main(){
	
	abre;

	int t;
	int ct = 1;
	for(cin>>t;t--;){
		
		cin>>N;
		
		for(int i = 0 ; i < N ; ++i) G[i].clear(),raio[i] = 0;
		
		int a,b;
		
		for(int i = 1 ; i < N ; ++i){
			scanf(" %d %d",&a,&b);
			G[a].pb(b);
			G[b].pb(a);
		}
		
		dfs(0,0);
		calc();
		
		int q;
		for(cin>>q;q--;){
			int r;
			scanf(" %d %d %d",&a,&b,&r);
			
			int lca_ = lca(a,b);
			
			raio[a] += r;
			raio[b] += r;
			raio[lca_] += -r;
			
			//~ cout << lca_ << "  " << a<< "  " << b << endl;
			
			if(lca_ != 0){
				raio [ pai[lca_][0] ] += -r;
			}
		}
		
		dfs_ans(0,0);
		
		printf("Case #%d:\n",ct++);
		for(int i = 0 ; i < N ; ++i){
			printf("%d\n",ans[i]);
		}
	}





	return 0;
}
