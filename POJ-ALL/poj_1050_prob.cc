#include <iostream>
using namespace std;

#define go freopen("in","r",stdin);


int M[150][150],sumac[150][150];

int N[150];

int kadane1D(int n){
  int sum = 0;
  int ans = 0;
  for(int i = 0 ; i < n ; ++i){
    sum += N[i];
    if(sum < 0) sum = 0;
    ans = max(sum,ans);
  }
  return ans;
}

inline int get(int l, int c){
  if(l>= 0 && c>=0) return sumac[l][c];
  return 0;
}


int kadane2D(int n){

  int ans = -1e9;

  for(int k = 0 ; k < n ; ++k){ // tamanho da janela

    for(int i = 0 ; i+k < n ; ++i){ //começa em 'i' e termina em 'i+k'

      for(int j = 0 ; j < n ; ++j){ // foi de 'i' ate 'i+k'
        N[j] = get(i+k,j) - get(i-1,j);
      }

      ans = max(ans,kadane1D(n));
    }
  }

  return ans;
}

int main(){


  // go


  int n;
  cin>>n;
  for(int i = 0 ; i < n ;++i)
  for(int j = 0 ; j < n ;++j){
    cin>>M[i][j];
    if(i == 0) sumac[i][j] = M[i][j];
    else sumac[i][j] = sumac[i-1][j]+M[i][j];
  }

  cout << kadane2D(n)<< '\n';

  return 0;
}

