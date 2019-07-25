#include <bits/stdc++.h>
using namespace std;

int h[30*30+500];

int main(){
  cout << setprecision(2) <<fixed;

  int n,m,v,ct =1;
  // freopen("in","r",stdin);
  while(cin>>n>>m,n&&m){

    for(int i = 0 ; i < n*m ; ++i){
      cin>>h[i];
    }

    cin>>v; // volume despejado

    sort(h,h+(n*m));

    double nivel = (int)h[0];
    double perc = 0.0;
    // n*m === 100%
    // i ===== x %

    for(int i = 1 ; i < n*m ; ++i){
      int dif = h[i] - h[i-1];


      if(dif*100*i >= v){
        nivel += v/(100.0*i);
        v = 0;
        perc = i*100.0/(double)(n*m);
        break;
      }else{
        v -= dif*100*i;
        nivel += dif;
      }
    }

    if(n*m == 1){
      nivel += (v/100.0);
      perc = 100.0;
      v = 0;
    }

    if(v > 0){
      nivel += v / (100.0*n*m);
      perc = 100.0;
    }


    cout << "Region "<<ct++<<'\n';
    cout << "Water level is "<<nivel<<" meters.\n";
    cout << perc << " percent of the region is under water.\n\n";

  }

  return 0;
}
