#include <bits/stdc++.h>
using namespace std;

bool g[100][100];
int L,C;
int dl[] = {0,-1, 0,1};
int dc[] = {1, 0,-1,0};
int direita[] = {3,0,1,2};
int vis[100][100];

inline bool check(int l, int c){
  return l > -1 && c > -1 && L > l && C > c && g[l][c];
}


void go(int l, int c, int dir, bool at){
  if(l == L-1 && c == 0 && !at) return;
  int li = l + dl[direita[dir]];
  int ci = c + dc[direita[dir]];
  if(check(li,ci)){ // a direita esta livre
    vis[l][c]++;
    go(li,ci,direita[dir],0);
    return;
  }
  li = l + dl[dir];
  ci = c + dc[dir];
  if(check(li,ci)){ //  a frente esta livre
    vis[l][c]++;
    go(li,ci,dir,0);
    return;
  }
  go(l,c,(dir+1)%4,0); //  gira
  return;
}


int ans[5];
int main(){
  // freopen("in","r",stdin);
  string s;
  while(cin>>L>>C, L || C){
    int tot = 0;
    for(int i = 0 ; i < L ; ++i){
      cin>>s;
      for(int j = 0 ; j < C ; ++j){
        g[i][j] = (s[j]=='0');
        tot += g[i][j];
      }
    }


    // for(int i = 0 ; i < L ; ++i){
      // for(int j = 0 ; j < C ; ++j){
        // cout << g[i][j] << ' ';
      // }cout <<endl;
    // }


    memset(vis,0,sizeof vis);
    memset(ans,0,sizeof ans);
    go(L-1,0,0,1);
    // cout << " :: " << tot << endl;
    for(int i = 0 ; i < L ; ++i){
      for(int j = 0 ; j < C ; ++j){
        if(g[i][j]){
          ans[vis[i][j]]++;
        }
      }
    }
    printf("%3d%3d%3d%3d%3d\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
  }



}
