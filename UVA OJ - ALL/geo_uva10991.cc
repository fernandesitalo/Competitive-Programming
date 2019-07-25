#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);

#define RAD_to_DEG(theta_) (theta_*180.0/M_PI)

#define TwoPI 2*M_PI

int main(){

  cout << setprecision(4) << fixed;
  abre;
  int t;
  cin>>t;
  double R1,R2,R3;
  while(t--){
    cin>>R1>>R2>>R3;

    double a = R2+R1;
    double b = R1+R3;
    double c = R2+R3;

    double sp = (a+b+c)*0.5;

    double AreaTriangulo = sqrt(sp*(sp-a)*(sp-b)*(sp-c));

    double h = 2.0*AreaTriangulo/a;

    double beta = asin(h/c) - M_PI/2.0;


    double gama = asin(h/b)- M_PI/2.0;

    double alfa = M_PI - (beta + gama);

    double setor1 = M_PI*R1*R1 * (RAD_to_DEG(gama)/360.0);
    double setor2 = M_PI*R2*R2 * (RAD_to_DEG(beta)/360.0);
    double setor3 = M_PI*R3*R3 * (RAD_to_DEG(alfa)/360.0);

    cout << "setor1   " << setor1 << endl;
    cout << "setor2   " << setor2 << endl;
    cout << "setor3   " << setor3 << endl;
    cout << AreaTriangulo  - (setor1+setor2+setor3) << endl;
  }


  return 0;
}
