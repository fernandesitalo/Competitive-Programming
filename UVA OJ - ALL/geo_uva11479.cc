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
  cin.sync_with_stdio(0),cin.tie(0);
  // abre;
  int t;
  cin>>t;
  ll l1,l2,l3;
  for(int ct = 1; ct <= t ; ++ct){
    cin>>l1>>l2>>l3;
    cout << "Case "<<ct<<": ";
    if(ValidaTriangulo(l1,l2,l3) == false) cout <<"Invalid\n";
    else if(l1 == l2 && l2 == l3) cout << "Equilateral\n";
    else if(l1 == l2 || l1 == l3 || l2 == l3) cout << "Isosceles\n";
    else cout << "Scalene\n";
  }
  return 0;
}
