#include <bits/stdc++.h>
using namespace std;

bool pode[104][104];
int matriz[104][104];
string vet[101];
int l,c,k;


#define boraCumpadi freopen("in","r",stdin);


int pd[105][105];
int F(int linha,int linhaAnterior){

  if(linha == l) return 0;

  int &ref = pd[linha][linhaAnterior];
  if(ref != -1) return ref;

  ref = -1e9;

  for(int i = 0 ; i < k ; ++i){

    if(pode[linhaAnterior][i]){

      int sum = 0;
      for(int j = 0 ; j < c ; ++j){
        if(vet[i][j] == '+') sum += matriz[linha][j];
        else if(vet[i][j] == '-') sum -= matriz[linha][j];
      }

      ref = max(ref,F(linha+1,i)+sum);
    }
  }

  return ref;
}




bool f(string s, string r){
  for(int i = 0 ; s[i] ; ++i){
    if(s[i]!='.' && r[i] != '.' && s[i] == r[i]) return 0;
  }
  return 1;
}

int main(){

  // boraCumpadi

  while(cin>>l>>c,l||c){

    // cout << l << "        " << c << '\n';
    memset(pd,-1,sizeof pd);
    for(int i = 0 ; i < l ; ++i){
      for(int j = 0 ; j < c ; ++j){
        cin>>matriz[i][j];
      }
    }

    cin>>k;

    for(int i = 0 ; i < k ; ++i){
      cin>>vet[i];
    }

    memset(pode,0,sizeof pode);
    for(int i = 0 ; i < k ; ++i){
      for(int j = i ; j < k ; ++j){
        pode[i][j] = pode[j][i] = f(vet[i],vet[j]);
      }
    }
    for(int i = 0 ; i < 101 ; ++i) pode[k][i] = true;
    cout << F(0,k) << '\n';

  }



  return 0;
}
