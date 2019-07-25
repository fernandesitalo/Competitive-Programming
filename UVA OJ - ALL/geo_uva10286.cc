#include <bits/stdc++.h>
using namespace std;

#define deg_to_rad(th) th*M_PI/180.0

int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(10) << fixed;
  long double L;
  while(cin>>L){
    long double  co = sin(deg_to_rad(9.0))*L;
    cout << L*cos(deg_to_rad(9.0)) + co*tan(deg_to_rad(27.0)) << '\n';
  }
  return 0;
}
