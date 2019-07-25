#include<bits/stdc++.h>
using namespace std;

//  Tribbles
// m geraçoes
// k Tribbles



int n,m,k;
double p[1100],dp[1100];

// calcular do jeito burro pode é EXPONENCIAL...
// desde jeito fica n*m suave ....

/*
  novo jeito de pensar:

  calcula um ramo... desloca ele para frente e entao usa ele como base para calcular novos ramos...
  o proximo ramo usa o ramo anterior , isto é, o ramo atual tem o ramo anterior.....

  desse jeito calculamos a probabilidade de tras para frente.
*/

double P(){
  dp[1] = p[0]; // tinha 1 COISA e ela morreu.. como já tinha aquela coisa, contamos somente a probabilidade dela morrer
  for(int ger = 2 ; ger <= m ; ++ger){
    dp[ger] = 0;
    for(int i = 0 ; i < n ; ++i){
      dp[ger] += p[i] * pow(dp[ger-1],i);  // esses caras vao para a geração anterior, isto é nascem lá e morrem aqui(na geração atual)
      // colocando os que estao nascendo agr na geração anterior!!!!! e o resto e deslocado para frente!!!!
      // vou gerar 'i' COISAS. Cada coisa vai gerar outros e morrer.. como a ultima dp calculada....
    }
  }
  return pow(dp[m],k);
}




// pow(0,0) = 1   .: 0⁰ = 1 ?!

int main(){
  int t;
  cin>>t;
  int ct = 1;
  while(t--){
    cin>>n>>k>>m;
    for(int i = 0 ; i < n ; ++i) cin>>p[i];
    cout << "Case #"<<ct++<<": ";
    cout << setprecision(7) << fixed << P() << '\n';
  }
  return 0;
}
