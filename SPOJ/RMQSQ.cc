#include <bits/stdc++.h>
using namespace std;


int const maxn = 1e5+100;
int const lgmaxn = log2(maxn) + 1;

int st[maxn][lgmaxn];

int N;

int main(){

  scanf(" %d",&N);

  for(int i = 0 ; i < N ; ++i){
    scanf(" %d",&st[i][0]);
  }

  for(int j = 1 ; j < lgmaxn ; ++j){
    for(int i = 0 ; i + (1<<j) <= N ; ++i){
      st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
  }

  int Q,r,l;
  scanf(" %d",&Q);
  while(Q--){
    scanf(" %d %d",&l,&r);
    int j = log2(r-l+1);
    printf("%d\n",min(st[l][j],st[r - (1<<j) + 1][j]));
  }

  return 0;
}
