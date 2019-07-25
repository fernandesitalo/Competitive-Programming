#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);

#define RAD_to_DEG(theta_) (theta_*180.0/M_PI)



#define MIN_to_DEG(theta_) (theta_/60.0);


int main(){

  // abre;

  cout << setprecision(6) << fixed;

  double s,R,a;
  string op;

  while(cin>>s>>a>>op){

    R = 6440 + s;

    if(op == "min"){
      a = MIN_to_DEG(a);
    }

    a = min(a,360.0-a);


    double Dist = 2.0*M_PI*R * (a/360.0);

    double Chord = sqrt(2 * R*R * (1 - cos(DEG_to_RAD(a))));

    cout << Dist << " " << Chord << '\n';

  }

  return 0;
}
