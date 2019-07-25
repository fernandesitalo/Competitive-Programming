#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);


typedef long long ll;

bool ValidaTriangulo(ll l1,ll l2,ll l3){ // condicao de existencia do triangulo
  return (l1 > abs(l3-l2) && (l3+l2) > l1 &&
    l2 > abs(l1-l3) && (l1+l3) > l2 &&
    l3 > abs(l2-l1) && (l2+l1) > l3);
}


int main(){
  abre;
  int t;
  cin>>t;
  ll a,b,c;
  while(t--){
    cin>>a>>b>>c;
    if(ValidaTriangulo(a,b,c)) cout << "OK\n";
    else cout << "Wrong!!\n";
  }
  return 0;
}
