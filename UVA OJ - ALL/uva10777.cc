#include <bits/stdc++.h>
using namespace std;


// horas prob
// se horas > 0 entao me leva pra um local seguro
// se horas < 0 entao não me leva pra um local seguro

// quero o tempo esperado para chegar a um local seguro

#define endl '\n'


#define limite 50000

int n;
int H[110];
double P[110];

double pd[limite+10];


double F(int idx){

  if(pd[idx] >= 0) return pd[idx];

  if(idx == limite){

    double ret = 0;

    for(int i = 0 ; i < n ; ++i){
      if(H[i] > 0){
        ret += (double)H[i]*P[i];
      }
    }
    return  pd[idx] = ret;
  }

  double ret = 0;
  for(int i = 0 ; i < n ; ++i){

    if(H[i] > 0){

      ret += H[i]*P[i];

    }else{
      ret += (-H[i])*P[i] + P[i]* F(idx+1);
    }

  }
  return pd[idx] = ret;
}



int main(){

  // freopen("in","r",stdin);

  cin.sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  int ct = 1;

  while(t--){
    cin>>n;
    memset(pd,-1,sizeof pd);
    bool o = false;

    for(int i = 0 ; i < n;  ++i){
      cin>>H[i]>>P[i];
      o |= (H[i] > 0);
    }

    cout << "Case " << ct++ << ": ";
    if(o)
      cout<< setprecision(2) <<fixed <<  F(0) << endl;
    else
      cout << "God! Save me\n";
  }

  // verificar se existe pelo menos um tempo positivo, caso contrario nao tem jeito



  return 0;
}
