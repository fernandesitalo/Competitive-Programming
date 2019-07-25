#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define MAXN 123

struct E{
  int to,f,cp;// to -> para onde, f -> fluxo ,  cp -> capacidade da aresta
} edges[MAXN*MAXN];

vector<int> G[MAXN];

int sink,source,n,time_ = 1,vis[MAXN] = {0},cur;


void add_edge(int a, int b, int cap_ida, int cap_volta){

  edges[cur].to = b;
  edges[cur].f  = 0;
  edges[cur].cp = cap_ida;
  G[a].pb(cur++);

  edges[cur].to = a;
  edges[cur].f  = 0;
  edges[cur].cp = cap_volta;
  G[b].pb(cur++);
}

int dfs(int u,int garg){

  if(u == sink){
    return garg;
  }
  vis[u] = time_;

  for(int i = 0 ; i < (int) G[u].size() ; ++i){
    int v = G[u][i];

    if(time_ > vis[  edges[v].to  ] && (edges[v].cp  - edges[v].f) > 0)
      if(int a = dfs(edges[v].to,min(garg ,edges[v].cp  - edges[v].f)) ){
        edges[v].f += a;
        edges[v^1].f -= a; // traquinagem
        return a;
      }
  }
  return 0;
}


int MaxFlow(){
  int mf = 0;
  while(int a = dfs(source,INF)){
    time_++,mf += a;
  }
  return mf;
}

int main(){

  // freopen("in","r",stdin);


  int a,b,c,m,ct = 1;
  while(cin>>n,n){
    for(int i = 0 ; i <= n ; ++i) G[i].clear();

    cur = 0;
    for(int i = 0 ; i <= n ; ++i) vis[i] = 0;
    time_ = 1;
    scanf(" %d %d %d",&source,&sink,&m);
    for(int i = 0 ; i < m ; ++i){
      scanf(" %d %d %d",&a,&b,&c);
      add_edge(a,b,c,c);
    }

    printf("Network %d\n",ct++);
    printf("The bandwidth is %d.\n\n",MaxFlow());
  }
  return 0;
}
