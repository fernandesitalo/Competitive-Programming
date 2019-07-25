#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-8
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back


/*
        double D, L, a, b, c;
        scanf("%lf %lf", &D, &L);
        D /= 2, L /= 2;
        c = D, a = L;
        b = sqrt(a*a-c*c);
        printf("%.3lf\n", pi*a*b);

*/

int main(){
  cout << setprecision(3) << fixed ;
  double D,L;
  abre;
  int n;
  cin>>n;
  while(n--){
    cin>>D>>L;
    D /= 2, L /= 2;
    double c = D, a = L;
    double b = sqrt(a*a-c*c);
    cout << M_PI*a*b << '\n';

  }




  return 0;
}
