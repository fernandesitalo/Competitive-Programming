#include <bits/stdc++.h>
using namespace std;

int memo[110];

int f91(int n){
  if(n >= 101) return n-10;
  int &ref = memo[n];
  if(ref != -1) return ref;
  return ref = f91(f91(n+11));
}


int main(){
  memset(memo,-1,sizeof memo);
  int n;
  while(cin>>n,n){
    cout <<"f91("<<n<<") = "<<f91(n) << '\n';
  }
  return 0;
}
