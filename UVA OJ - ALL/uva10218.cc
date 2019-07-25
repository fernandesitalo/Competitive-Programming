#include <bits/stdc++.h>
using namespace std;



long double p,q,dp[110][1002];
int m,w,c;
double F(int doces, int h){
  if(doces == 0) return 1.*!(h%2);
  long double &ref = dp[doces][h];
  if(ref >= 0) return ref;
  return ref = F(doces-1,h+1)*p + F(doces-1,h)*q;
}

int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(7) << fixed ;
  while(cin>>m>>w>>c,m || w){
    for(int i = 0 ; i <= c ; ++i)for(int j = 0 ; j < 1002  ; ++j) dp[i][j] = -1;
    p = m*1./(m+w+0.0);
    q = w*1./(m+w+0.0);
    cout << F(c,0) << '\n';
  }
  return 0;
}
