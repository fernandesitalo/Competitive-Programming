#include <bits/stdc++.h>
using namespace std;

int main(){

  int a,b,c;

  while(cin>>a,a){
    cin>>b>>c;
    cout << (int)sqrt(a*b*100.0/(double)c) << '\n';
  }

  return 0;
}
