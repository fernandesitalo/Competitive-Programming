#include <bits/stdc++.h>
using namespace std;

int pd[600][600];

int C(int n,int k){
  if(n == k || k == 0) return 1;
  int &ref = pd[n][k];
  if(ref != -1) return ref;
  return ref = (C(n-1,k-1)+C(n-1,k));
}




int main(){
  memset(pd,-1,sizeof pd);


  int n; double p;

  for(;cin>>n>>p,n||p;){
    double Ex = 0;

    double q = 1.0-p;
    double P = 1.0;

    for(int i = 0 ; i <= n ; ++i){
      Ex += i*C(n,i)*P*pow(q,n-i);

      cout << P*pow(q,n-i) << "  " << i << "    " << C(n,i) << endl;

      P *= p;

      // cout << "C(" << n << "," << i << ") = " << C(n,i) << " \n";
    }

    cout << "\n";

    cout <<setprecision(20) << fixed <<  Ex << '\n';

  }





  return 0;
}
