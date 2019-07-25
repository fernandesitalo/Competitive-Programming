#include <bits/stdc++.h>
using namespace std;

int main(){

  long long a,b;
  int ct = 1;
  while(cin>>a>>b,a||b){

    double p1 = b/(double)a, p2 = (b-1)/(double)(a-1);

    // cout << p1 << "  "  << p2 << endl;

    cout << "Case " << ct++ << ": ";
    if(a <= 1){
      cout << ":-\\\n";
    }else if(b >= a){
      cout << ":-|\n";
    }else if(p1 > p2){
      cout << ":-(\n";
    }else cout << ":-)\n";
  }

  return 0;
}
