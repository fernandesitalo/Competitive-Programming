#include <bits/stdc++.h>
using namespace std;
int const maxn = 5e3;

int v[maxn];

int main(){

  // freopen("in","r",stdin);
  int t,x;
  cin>>t;
  while(t--){
    int n;
    scanf("%d",&n);
    vector<int> v1,v2;

    while(n--){
      scanf("%d",&x);
      v1.push_back(x);
      v2.push_back(x);
    }

    reverse(v1.begin(),v1.end());
    for(auto i : v2) v1.push_back(i);

    vector<int> L;

    for(auto i : v1){
      int pos = lower_bound(L.begin(),L.end(),i) - L.begin();
      if(pos == (int) L.size()){
        L.push_back(i);
      }else{
        L[pos] = i;
      }
    }

    cout << L.size() << '\n' ;

  }




  return 0;
}
