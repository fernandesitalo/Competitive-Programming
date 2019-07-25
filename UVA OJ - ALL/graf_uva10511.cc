#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back


int const MAXN = 10000;

struct edge{
  int to,c,f;
} edges[MAXN*50];

vector<int> G[MAXN];
int sink,source,tempo,cur,vis[MAXN];


map<string,int> membro,clubes,partidos;
map<int,string> dic_membro,dic_clubes,dic_partidos;


void add_edge(int a,int b, int cap_ida, int cap_volta){

  // cout << "ARESTA: " << a << " -> " << b << endl;

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
  if(u == sink) return garg;
  vis[u] = tempo;
  for(int i = 0 ; i < (int)G[u].size() ; ++i){
    int id = G[u][i];
    if(tempo > vis[ edges[id].to ] && (edges[id].c - edges[id].f) > 0){
      if(int a  = dfs(edges[id].to,min(garg,(edges[id].c - edges[id].f)))){
        edges[id].f += a;
        edges[id^1].f -= a;
        return a;
      }
    }
  }
  return 0;
}

int MaxFlow(){
  int mf = 0;
  while(int f = dfs(source,INF)) mf += f,tempo++;
  return mf;
}

void printSolution(){
  for(map<int,string>::iterator it = dic_membro.begin(); it != dic_membro.end() ; ++it){
    int u = it->first;
    for(int i = 0 ; i < (int)G[u].size() ; ++i){
      int id = G[u][i];
      if(edges[id].f == 1){
        cout << dic_membro[u] << " " << dic_clubes[ edges[id].to ] << '\n';
        break;
      }
    }
  }
}



int main(){

  freopen("in","r",stdin);

  int n;

  cin >> n;

  getchar();
  while(n--){

    getchar();

    membro.clear(),clubes.clear(),partidos.clear(),dic_membro.clear(),dic_clubes.clear(),dic_partidos.clear();
    for(int i = 0 ; i < MAXN ;++i) G[i].clear(),vis[i] = 0;
    cur  = 0, tempo = 1;

    source = 0;

    int cont = 1;

    string nome,partido,aux,fr;

    while(getline(cin,fr), fr[0] != '\0'){

      stringstream ss(fr);

      // cout <<">>>>>>   " <<  fr << endl;

      ss>>nome>>partido;

      if(membro.find(nome) == membro.end()){
        membro[nome] = cont;
        dic_membro[cont] = nome;
        cont++;
      }
      add_edge(source,membro[nome],1,0); // aresta


      if(partidos.find(partido) == partidos.end()){
        partidos[partido] = cont;
        dic_partidos[cont] = partido;
        cont++;
      }

      while(ss>>aux){
        if(clubes.find(aux) == clubes.end()){
          clubes[aux] = cont;
          dic_clubes[cont] = aux;
          cont++;
        }
        add_edge(membro[nome],clubes[aux],1,0);
        add_edge(clubes[aux],partidos[partido],1,0);
      }
    }

      sink = cont++;

      for(map<string,int>::iterator it = partidos.begin() ; it != partidos.end() ; ++it){
        int p = it->second;
        add_edge(p,sink,1,0);
      }

      // cout << cur << endl;
      // cout << "----------------------------------" << endl;

      int flow = MaxFlow();

      // cout << "FLOW:   " << flow << endl;

      if(flow == (int)partidos.size()){
        printSolution();
      }else puts("Impossible");

      if(n) puts("");

      // cout << "    >>    " << cont << endl;

  }
  return 0;
}
