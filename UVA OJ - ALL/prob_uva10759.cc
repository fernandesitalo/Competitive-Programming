#include <bits/stdc++.h>
using namespace std;



typedef unsigned long long ull;

ull dp[25][160];
bool vis[25][160];


int N,x;

ull num(int dado,int soma){

  if(dado == N){
    return (soma >= x);
  }

  if(vis[dado][soma]) return dp[dado][soma];

  vis[dado][soma] = true;

  ull r = 0;

  for(int i = 1 ; i <= 6 ; ++i){
    r += num(dado+1,soma+i);
  }
  return dp[dado][soma] = r;
}


int main(){

  // cout << 24*6 << endl;

  while (cin>>N>>x,N||x){

    memset(vis,false,sizeof vis);

    ull nume = num(0,0);
    ull deno = pow(6,N);

    if(nume == 0) cout << "0\n";
    else if(nume == deno) cout <<"1\n";
    else{
      ull g = __gcd(nume,deno);
      cout << (nume/g) << "/" << deno/g << '\n';
    }
  }

  return 0;
}
