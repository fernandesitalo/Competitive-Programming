#include <bits/stdc++.h>
using namespace std;
#define abre freopen("in","r",stdin);

int mdc(int a, int b) { return b == 0 ? a:mdc(b,a%b);}

int main(){

  int l[5];
  l[3] = 0;
  // abre;

  while(cin>>l[0]>>l[1]>>l[2], l[0] || l[1] || l[2]){
    sort(l,l+3);
    // cout << l[0] <<"  " << l[1] << " " << l[2] << endl;
    if(l[2]*l[2] == l[0]*l[0] + l[1]*l[1]) cout << "right\n";
    else                                   cout << "wrong\n";
  }
  return 0;
}
