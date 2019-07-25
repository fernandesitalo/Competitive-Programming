#include <bits/stdc++.h>
using namespace std;
int const maxn = 10090;
#define pb push_back
#define INF 0x3f3f3f3f
vector<int> G[maxn];
int t,n,m;
bitset<1000001> vis;

int chamada;

void dfs(int u){
  // cout <<chamada << "-> " << u << '\n';
  vis[u] = 0;
  for(auto i : G[u]) if(vis[i]) dfs(i);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>t;
  for(int i = 1; i <= t ; ++i){
    cin>>n>>m;
    vis.set();
    for(int x = 1 ; x <= n ;++x) G[x].clear();
    for(int a,b;m--;)cin>>a>>b,G[a].pb(b),G[b].pb(a);

    chamada = 0;

    dfs(1);
    int qtd = 0;
    for(int x = 2 ; x <= n ; ++x){
      if(vis[x]){
        chamada++;
        dfs(x);
        qtd++;
      }
    }
    cout << "Caso #"<<i<<": ";
    if(qtd == 0) cout << "a promessa foi cumprida\n";
    else cout << "ainda falta(m) "<<qtd<<" estrada(s)\n";
  }
  return 0;
}
