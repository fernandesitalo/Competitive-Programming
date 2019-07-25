#include <bits/stdc++.h>
using namespace std;
int const maxn = 5e4+100;
int const lgmaxn = log2(maxn)+1;

int st[maxn][lgmaxn];

int main(){

  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0 ; i < n ; ++i) scanf("%d",&st[i][0]);

  for(int j = 1; j < lgmaxn ; ++j){
    for(int i = 0 ; i + (1<<j) <= n ; ++i){
      st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
  }
  int l,r,ans = 0;
  while(m--){
    scanf("%d%d",&l,&r);

    if(l > r) swap(r,l);
  --l,--r,--r;
    int j = log2(r-l+1);
    ans += (st[l][0] >= max(st[l][j],st[r-(1<<j)+1][j])) ;
  }

  return !printf("%d\n",ans);
}
