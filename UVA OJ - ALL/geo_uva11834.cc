#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

inline void yes(){puts("S");}
inline void no(){puts("N");}

int main(){

  // freopen("in","r",stdin);

  int l,c,r1,r2;


  while(cin>>l>>c>>r1>>r2, l || c || r1 || r2){

    int temp = min(l,c);

    if(!(temp >= 2*r1 && temp >= 2*r2)){
       no();
       continue;
     }

    c -= (r1+r2);
    l -= (r1+r2);

    if(l >= 0 && c >= 0){

      if(l*l + c*c >= (r1+r2)*(r1+r2)){
        yes();
      }else{
        no();
      }
    }else no();
  }

  return 0;
}
