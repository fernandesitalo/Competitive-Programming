#include <bits/stdc++.h>
using namespace std;

int n;

typedef long long ll;

int a[1123];
int d;

// fiz o bk pra testar e toda probabilidade se resume em "1/2\n" ..

ll bk(int i){

  if(i == n-1){
    cout << ":::::" << endl;
    d++;

    if(a[i] == -1) return 0;
    return 1;
  }

  ll ret = 0;

  if(a[i] == -1 && i != 0){
    a[i] = i;
    ret += bk(i+1);
    a[i] = -1;
  }else {
    for(int f = 0 ; f < n ; ++f){
      if(a[f] == -1){
        a[f] = f;
        ret += bk(i+1);
        a[f] = -1;
      }
    }
  }
  return ret;
}


int main(){
     // memset(a,-1,sizeof a);




  while(cin>>n,n){
    // d = 0;

    cout << "1/2\n";
    // int num = bk(0);

    // cout << num << "/" << d << "\n";
  }

  return 0;
}
