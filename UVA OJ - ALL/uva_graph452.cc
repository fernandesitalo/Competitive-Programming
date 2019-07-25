#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int const maxn = 300;
vector<int> g[maxn];
int dist[maxn];
int tempo[maxn];

/*
	quero achar qnto tempo gasto para "processar"(da questao) o DAG da entrada
	posso processar as folhas do DAG paralelamente (B->A e C->A, entao posso realizar a tarefa B e C paralelamente)
	se a gente parar pra pensar, este tempo, vai ser o tempo do maior caminho do DAG
	fazemos TOPOSORT, obtemos a ordem de relachamento dos vertices (como se fosse bottom-up), processamos e pegamos a resposta otima!
*/

int vis;
vector<int> ts;
void dfs(int u){
	vis = vis|(1<<(u-'A'));
	for(auto v : g[u]){
		if(!(vis & (1<<(v-'A')))){
			dfs(v);
		}
	}
	ts.push_back(u);
}

int main(){
	//~ freopen("in","r",stdin);
	string line;
	int t;
	cin>>t;
	getchar(); // enter
	getchar(); // enter
	bool isfirst = true;
	while(t--){
		
		if(!isfirst)cout << "\n";
		isfirst = false;
		int ini;
		
		for(int i = 'A' ; i <= 'Z' ; ++i) g[i].clear(),dist[i] = inf;
		
		line = "";
		while(getline(cin,line) && line[0] != '\0'){
			int a = line[0];
			int number= 0;
			int i = 2;
			while(line[i] >= '0' && line[i] <= '9'){
				number *=10;
				number += line[i]-'0';
				i++;
			}
			tempo[a] = -number;
			//~ cout << (char)(a) << "   " << number <<"  "; 
			i++;
			if(i >= (int)line.size()){
				ini = a;
			}
			
			while((int)line.size() > i){
				int b = line[i];
				//~ cout << (char) (b) << ' ';
				g[b].push_back(a);
				i++;
			}
			//~ cout <<endl;
			line = "";
		}
		//~ cout << "ini " << (char)ini << '\n';
		vis = 0;
		ts.clear();
		dfs(ini);
		reverse(ts.begin(),ts.end());
		//~ cout << "tps:   ";for(auto i : ts){
			//~ cout << i << ' ';
		//~ }cout << endl;
		dist[ini] = tempo[ini];
		for(auto at : ts){
			for(auto v : g[at]){
				if(dist[v] > dist[at]+tempo[v]){
					dist[v] = dist[at]+tempo[v];
				}
			}
		}
		int ans = 0;
		for(int i= 'A' ; i <= 'Z'; ++i){
			ans= max(ans,-dist[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
