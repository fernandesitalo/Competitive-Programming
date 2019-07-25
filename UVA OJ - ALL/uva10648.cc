#include <bits/stdc++.h>
using namespace std;



typedef pair<double,double> dd;
typedef pair<int,int> ii;

map<vector<int>,dd> memo;


dd F(vector<int> V,int c, int q, bool vazio){

  if(c == 0){
    if(q > 0 && vazio == false) return dd(1.0,1.0);
    return dd(0.0,1.0);
  }

  if(memo.find(V) != memo.end()) return memo[V];


  dd r = F(V,c-1,q,true);

  for(int i = q ; i > 0 ; --i){
    V[c] += i;
    dd aux = F(V,c-1,q-i,vazio);
    V[c] -= i;
    r.first  += aux.first;
    r.second += aux.second;
  }

  return memo[V] = r;
}


int main(){

  cout << setprecision(7) << fixed ;

  vector<int> caixa(13,0);
  dd ans = F(caixa,12,50,false);

  cout <<   ans.first << "   "  << ans.second  << endl;



  return 0;
}
