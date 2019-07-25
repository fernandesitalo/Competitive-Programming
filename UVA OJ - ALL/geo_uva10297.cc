#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

double D,V;

double vol_castor(double d){ // volume que o castor roeu
  double R = D/2.0,r = d/2.0, h = (D-d)/2.0;

  double tc = M_PI*h/3.0*(R*R+R*r+r*r); // tronco cone;

  double cil = M_PI*r*r*d;

  return M_PI*R*R*D - (2.0*tc+cil);
}


void solve(){

  double l = 0.0,r = D;

  double dd;

  while(1){
    if(fabs(l-r) < EPS) break;

    dd = (l+r)/2.0;

    double volcast  = vol_castor(dd);

    // cout << ">>>>>>     " << volcast << '\n';

    if(fabs(volcast - V) < EPS) break;
    if(volcast < V) r = dd;
    else l = dd + EPS;

  }

  cout << dd << '\n';
}

int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(3) << fixed;

  while(cin>>D>>V,D&&V){
    solve();
  }
  return 0;
}
