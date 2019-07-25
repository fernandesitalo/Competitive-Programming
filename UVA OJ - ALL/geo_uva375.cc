#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)



int main(){
  // cin.sync_with_stdio(0),cin.tie(0);
  // cout << setprecision(7) << fixed;


  // abre;
  int t;
  cin>>t;

  double b,h,l;

  while(t--){
    double C = 0;
    cin>>b>>h;


    while(1){
      l = sqrt((b/2.0)*(b/2.0) + h*h);

      // 2lr + rb = bh
      double R = (b*h)/(2*l+b);

      // b é base
      // h é altura
      // R e raio... que é tangente a base..
      //.: 2lr + br = bh ......

      // triangulo de base l e altura r
      // triangulo de base b e altura r
      // triangulo de base b e altura h


      if(R < 0.000001) break;

      double H = h;
      h -= R*2;
      b = b*h/H;

      C += (2.0 * PI * R);
    }

    printf("%13.6lf\n",C);
    if(t) puts("");

  }


  return 0;
}
