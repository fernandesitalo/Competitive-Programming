#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn (1<<7)+10

double memo[maxn][maxn][maxn];
double p[maxn][maxn];
int N;
// twin -> time vencedor

double P(int twin, int l, int r){

  if(abs(l-r) == 1) return p[twin][l == twin?r:l];

  double &ref = memo[twin][l][r];

  if(ref >= 0) return ref;

  ref = 0;

  if(twin > (l+r)/2){

    for(int i = l ; i <= (l+r)/2 ; ++i){
      ref += P(i,l,(l+r)/2) * p[twin][i];
    }
    ref*= P(twin,(l+r)/2+1,r);

  }else{

    for(int i = (l+r)/2 + 1 ; i <= r ; ++i){
      ref += P(i,(l+r)/2 + 1,r) * p[twin][i];
    }
    ref*= P(twin,l,(l+r)/2);
  }

  return ref;
}



int main(){
  // freopen("in","r",stdin);
  int n;
  while(cin>>n, n != -1){

    int N = (1<<n);

    for(int i = 0 ; i < N ; ++i)
    for(int j = 0 ; j < N ; ++j) cin>>p[i][j];

    for(int i = 0 ; i < N ; ++i)
    for(int j = 0 ; j < N ; ++j)
    for(int k = 0 ; k < N ; ++k)
    memo[i][j][k] = -1;

    int ans = 0;
    double pans = 0;
    for(int i = 0 ; i < N ; ++i){
      double pp = P(i,0,N-1);
      if(pp > pans) pans = pp, ans = i+1;
    }
    // cout << pans << endl;
    cout << ans << '\n';
  }
  return 0;
}
