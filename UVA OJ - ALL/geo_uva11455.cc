#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-15
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)


int main(){
  abre;
  int t;
  cin>>t;
  while(t--){
    vector<int> v;
    int x;
    for(int i = 0 ; i < 4 ; ++i) cin>>x,v.pb(x);
    sort(v.begin(),v.end());
    if(v[0] == v[3]) cout << "quadrangle\n";
    else if(v[0] == v[1] && v[2] == v[3]) cout << "rectangle\n";
    else if(v[3]< v[0]+v[1]+v[2]) cout <<"square\n";
    else cout << "banana\n";
  }

  return 0;
}
