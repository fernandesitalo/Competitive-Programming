#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);


int main(){

  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(2) << fixed ;

  double L;

  int t;
  cin>>t;
  while(t--){
    cin>>L;
    double R = L/5.0;
    double C = L*6.0/10.0;
    double red = M_PI*R*R;
    double green = L*C - red;
    cout << red << " " << green << endl;
  }
  return 0;
}
