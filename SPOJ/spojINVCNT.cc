#include<bits/stdc++.h>
using namespace std;

#define maxn 1000010
typedef long long ll;


int v[maxn];

ll merge(int l, int r, int middle){
  ll inv = 0;
  int vaux[r-l+1],idx = 0;
  for(int i = l ; i <= middle ; ++i) vaux[idx++] = v[i];
  for(int i = r ; i > middle ; --i) vaux[idx++] = v[i];
  idx = l;
  r = r-l;
  l = 0;
  int m = (r+l)/2;
  while(r >= l){
    if(vaux[r] >= vaux[l]) v[idx++] = vaux[l++];
    else{
      if(m >= l && r > m) inv += m-l+1;
      v[idx++] = vaux[r--];
    }
  }
  return inv;
}

ll mergesort(int l, int r){
  ll inv = 0;
  if(r > l){
    int middle = (l+r)/2;
    inv += mergesort(l,middle);
    inv += mergesort(middle+1,r);
    inv += merge(l,r,middle);
  }
  return inv;
}


int main(){

  // freopen("in","r",stdin);
  cin.sync_with_stdio(0),cin.tie(0);

  int n;
  cin>>n;
  for(int i = 0 ; i < n ; ++i) cin>>v[i];

  ll ans =  mergesort(0,n-1);

  if(n % 2 == 0){
    if(ans % 2 == 0) cout << "Petr\n";
    else cout << "Um_nik\n";
  }else{
    if(ans % 2 == 0) cout << "Um_nik\n";
    else cout << "Petr\n";
  }

  return 0;
}
