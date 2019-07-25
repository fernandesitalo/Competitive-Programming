#include <bits/stdc++.h>
using namespace std;


double solve(int a, int b){

  // case 1 :
  double temp1 = max(a,b)/4.0;
  double temp2 = min(a,b);
  double ans = min(temp1,temp2);

  // case 2:
  temp1 = min(a,b)/2.0;

  return max(ans,temp1);
}

#define EPS 1e-9

int main(){

  // freopen("in","r",stdin);

  int t,a,b;

  while(cin>>t,t){
    double tamAns = -1;
    int idxAns = 0;
    for(int i = 1 ; i <= t ; ++i){
      cin>>a>>b;
      double temp = solve(a,b);
      if(temp > tamAns+EPS){
        tamAns = temp;
        idxAns = i;
      }
    }
    cout << idxAns << '\n';
  }

  return 0;
}
