#include <bits/stdc++.h>
using namespace std;



int main(){

  // freopen("in","r",stdin);

  cout << setprecision(4) << fixed ;

  int t;
  cin>> t;

  while(t--){

    double p;
    int n,i;
    cin>>n>>p>>i;

    double q = 1.0 - p;

    double ans = p;

    double R = 1.0; // R = probabilidade dos i-1 primeiros errarem .: q^(i-1)
    for(int k = 1 ; k < i ; ++k) ans *=q,R*=q;  // ans = probabilidade de todos ate i-1 'errarem' e i 'acertar' .: p*q^(i-1)


    double N = 1.0; // N = probabilidade de percorrer todo mundo e ninguem ter acertado a face correta .: q^(n)
    for(int k = 0 ; k < n ; ++k){
      N *=q;
    }

    double T = N;

    double ant = 2.0;

      for(int j = 1 ; fabs(ans - ant) > 1e-9 ; ++j){
        ant = ans;
        ans += (R*N) * p; // prababilidade dos (i-1 + n*k) errarem e o iesimo cara acertar, k é uma constante inteira
        N*=T; // .: q^(n)*q^(n) = q^(2n) (soma de expoente)
      }
    cout << ans << endl;
  }
  return 0;
}
