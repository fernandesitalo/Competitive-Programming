#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
typedef long long ll;
typedef pair<int,int> ii;


int const MAXN = 2123;

struct edge{
  int to,c,f;
} edges[MAXN*MAXN];

vector<int> G[MAXN];
int cur = 0,tempo,vis[MAXN],n,m,source,sink;


// source  = 0;
// m problemas de 1 a m
// n categorias , de (m+1) a (m+n)
// sink = m+n+1


void add_edge(int a,int b, int cap_ida, int cap_volta){
  edges[cur].to = b;
  edges[cur].c = cap_ida;
  edges[cur].f = 0;
  G[a].pb(cur++);
  edges[cur].to = a;
  edges[cur].c = cap_volta;
  edges[cur].f = 0;
  G[b].pb(cur++);
}

int dfs(int u, int garg){
  if(u == sink)return garg;

  vis[u] = tempo;

  for(int i = 0 ; i < (int) G[u].size() ; ++i){
    int id = G[u][i]; // indice da aresta
    if(tempo > vis[ edges[id].to ] && (edges[id].c - edges[id].f) > 0 )
      if(int a = dfs(edges[id].to,min(garg, edges[id].c - edges[id].f ))){
        edges[id].f += a;
        edges[id^1].f -= a;
        return a;
      }
  }
  return 0;
}

int MaxFlow(){ // solve
  int mf = 0;
  while(int f = dfs(source,INF))  tempo++,mf += f;
  return mf;
}


void print(){

  vector<int> ans[n+1];


  for(int u = 1 ; u <= m ; ++u){
    for(int i = 0 ; i < (int)G[u].size() ; ++i){
      int id = G[u][i];
      // cout << "> " << edges[id].to << " -- " << edges[id].f << endl;
      if(edges[id].to > m && edges[id].f == 1){ // capacidade igual a zero ou fluxo igual a 1
        ans[edges[id].to - m - 1].pb(u);
        // cout << "add " << edges[id].to - m - 1 << endl;
        break;
      }
    }
  }

  for(int i = 0 ; i < n ; ++i){
    // cout << " tam  " << ans[i].size() << endl;
    for(int j = 0 ; j < (int)ans[i].size() ; ++j){
      if(j) printf(" ");
      printf("%d",ans[i][j]);
    }puts("");
  }
}

// fluxo maximo tem de ser a soma das capacidades requeridas!


int main(){

  // freopen("in","r",stdin);

  source = 0;
  int a,qtd;

  while(scanf(" %d %d",&n,&m) == 2 && n && m){
    // n categorias m problemas
    // source  = 0; ok
    // m problemas de 1 a m
    // n categorias , de (m+1) a (m+n)
    // sink = m+n+1

    for(int i = 0 ; i <= (m+n+2) ; ++i) G[i].clear(),vis[i] = 0;
    tempo = 1;
    cur = 0;

    sink = m+n+1;
    int sum = 0;


    for(int i = 1 ; i <= n ; ++i){
      scanf(" %d",&a);
      add_edge(m+i,sink,a,0);
      sum += a;
    }

    for(int i = 1 ; i <= m ; ++i ){
      add_edge(source,i,1,0);
    }


    for(int i = 1 ; i <= m ; ++i){
      scanf(" %d",&qtd);
      for(int j = 0 ; j < qtd ; ++j){
        scanf(" %d",&a), add_edge(i,a+m,1,0);
      }
    }
    int flow = MaxFlow();

    // cout << ">>  " << flow << endl;

    if(flow == sum){
      puts("1");
      print();
    }else puts("0");

  }
  return 0;
}
