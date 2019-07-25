#include <bits/stdc++.h>
using namespace std;

// vector< vector<int> > W;
// int n,m;

// gerar todas possibilidades de ganho...
// mutiplicar numeradores e denominadores
// usar __gcd()
// sucesso ?


// void BK(int i, int value_win, int value_lose, vector<int> win){
  // if(i == m){
    // if(value_win > value_lose){
      // W.push_back(win);
    // }
  // }
  // win.push_back(i);
  // BK(i+1,value_win+(1<<i),value_lose,win);
  // win.pop_back();
  // BK(i+1,value_win,value_lose+(1<<i),win);
// }


/*

3 1 2 3
3 1 2 4
3 1 3 5
4 4 4 0
5 5 0 0

18 12 11 12


3/12 + 3/12*2/11 + 3/12*1/12 + 3/12*3/18 + 3/12*


*/

int q[10001][31],sum[31];

int main(){
  // freopen("in","r",stdin);

  cin.sync_with_stdio(0),cin.tie(0);
  int n,m;

  while ( cin >> n >> m , n || m){
    memset(sum,0,sizeof sum);

    for(int i = 0 ; i < n ; ++i){
      for(int j = 0 ; j < m ; ++j){
        cin>>q[i][j];
        sum[j] += q[i][j];
      }
    }

    for(int i = 0 ; i < n ; ++i){
      int g = __gcd(sum[m-1],q[i][m-1]);
      cout << q[i][m-1]/g << " / " << sum[m-1]/g << '\n';
    }
  }

  return 0;
}
