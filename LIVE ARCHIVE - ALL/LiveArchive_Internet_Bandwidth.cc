#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 1009
#define pb push_back
#define abre(str) freopen(str,"r",stdin)


int fluxo[MAXN][MAXN],vis[MAXN] = {0},pai[MAXN];
int sink,source,tempo = 0;
vector<int> G[MAXN];

int n;

//  estilo cp3

int bfs(){
  tempo++;
  vis[source] = tempo;
  queue<int> q;
  q.push(source);
  pai[source] = source;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    if(u == sink){
      int garg = INF;
      while(u != source){
        garg = min(garg,fluxo[pai[u]][u]);
        u = pai[u];
      }
      return garg;
    }

    for(int i = 0 ; i < (int)G[u].size() ; ++i){
      int v = G[u][i];
      if(tempo > vis[v] && fluxo[u][v] > 0) {
        vis[v] = tempo;
        pai[v] = u;
        q.push(v);
      }
    }
  }
  return 0;
}

int MaxFlow(){
  int mf = 0;
  while(int f = bfs()){
    int u = sink;

    while(u != source){
      fluxo[pai[u]][u] -= f;
      fluxo[u][pai[u]] += f;
      u = pai[u];
    }
    mf += f;
  }
  return mf;
}


int main(){
  // abre("in");
  int a,b,c,m,ct = 1;
  while(cin>>n,n){
    for(int i = 1 ; i <= n ; ++i){
      G[i].clear();
      for(int j = 1 ; j <= n ; ++j) fluxo[i][j] = 0;
    }
    scanf(" %d %d %d",&source,&sink,&m);
    for(int i = 0 ; i < m ; ++i){
      scanf(" %d %d %d",&a,&b,&c);
      G[a].pb(b);
      G[b].pb(a);
      fluxo[a][b] += c;
      fluxo[b][a] += c;
    }
    printf("Network %d\n",ct++);
    printf("The bandwidth is %d.\n\n",MaxFlow());
  }
  return 0;
}
