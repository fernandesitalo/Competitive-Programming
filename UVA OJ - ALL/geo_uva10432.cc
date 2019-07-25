#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);


int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(3) <<  fixed;
  double r,nl;
  // abre;

  while(cin>>r>>nl){
    double theta = 360.0/nl;

    double angle = (180 - theta)/2.0;

    angle = DEG_to_RAD(angle);

    double h = sin(angle)*r;
    double b = cos(angle)*r;

    double area = (b+b)*h/2.0;
    double areaTot = area*nl;

    cout << areaTot << '\n';
  }


  return 0;
}
