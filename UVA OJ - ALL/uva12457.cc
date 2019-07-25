#include<bits/stdc++.h>
using namespace std;

int n;
double p,q;

typedef pair<int,int> ii;
map<ii,double> memo;

double F(int idx, int win){
  if(win >= n) return 1.0;
  if(idx == 2*n-1) return 0.0;
  ii pos(idx,win);
  if(memo.find(pos) != memo.end()) return memo[pos];
  return memo[pos] = F(idx+1,win+1)*p + F(idx+1,win)*q;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(2) << fixed;
  int t;
  cin>>t;

  while(t--){
    memo.clear();
    cin>>n>>p; q = 1.0-p;
    cout << F(0,0) <<endl;
  }
  return 0;
}
