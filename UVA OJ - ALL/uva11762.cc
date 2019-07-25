#include <bits/stdc++.h>
using namespace std;

#define maxn 1000001
bitset<10000000> bs;
vector<int> primes;

typedef long long ll;
void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;

  for(ll i = 2 ; i < maxn ; i++){
    if(bs[i]){
      for(ll j = i*i ; j< maxn ; j+=i) bs[j] = 0;
      primes.push_back(i);
    }
  }
}

map<int,double>memo;


double E(int d){

  if(d == 1) return 0;

  if(memo.find(d) != memo.end()) return memo[d];

  double passos = 0;
  int tot = 0,deubom = 0;
  for(int i = 0 ; (int)primes.size() > i && d >= primes[i] ; ++i){

    if(d%primes[i] == 0){
      deubom++;
      passos += E(d/primes[i]);
    }

    tot++;
  }

  cout << passos <<  " "  << deubom << " " << tot << endl;
  return memo[d] = (passos + tot) * 1. / deubom;

}

int main(){


  cout << setprecision(7) << fixed;
  sieve();


  // cout << get_id(13) << endl;

  // return 0;
  // for(int i = 0 ; i < 11 ; ++i) cout << primes[i] << ' ' ;
  // cout << endl;

  int t;
  cin>>t;
  int ct = 1;
  while(t--){
      int n;
      cin>>n;
      memo.clear();
      cout << "Case " << ct++ << ": "<< E(n) << '\n';
  }
  return 0;
}
