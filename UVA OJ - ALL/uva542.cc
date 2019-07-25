#include<bits/stdc++.h>
using namespace std;


double memo[20][20][20];
double prob[20][20];



/*
  temos 2 lados, o 'L' e o 'R'
  estou em 'L' ganho de um cara de 'R', entao tenho que ganhar de todos do meu lado
  e o cara tem que ganhar de todos do lado dele
  eu faço o que a questão pede de cima pra baixo e não de baixo pra cima....
  *
  *
  *
  *
*/


//na funcao, [l,r] é um intervalo
double F(int ganha, int l, int r){ // quem vai ganhar do intervalo de 'l' a 'r'

  double &ref = memo[ganha][l][r];

  if(ref >= 0) return ref;

  if(abs(l-r) == 1){
    return ref = prob[ganha][ganha == l?r:l];
  }

  ref = 0;

  if(ganha > (l+r)/2){ // significa que quem ganha está a direita de l e r

    for(int i = l ; i <= (l+r)/2 ; ++i){
      ref += prob[ganha][i] * F(i,l,(l+r)/2); // o cara ganha de todo mundo que esta do lado dele
    }

    ref *= F(ganha,(l+r)/2+1,r); //  ganho de todo mundo do meu lado

  }else{
    for(int i = (l+r)/2+1 ; i <= r ; ++i){
      ref += prob[ganha][i] * F(i,(l+r)/2+1,r); // o cara ganha de todo mundo lá
    }

    ref *= F(ganha,l,(l+r)/2); // eu ganho de todo mundo aqui
  }
  return ref;
}


int main(){

  // freopen("in","r",stdin);

  memset(memo,-1,sizeof memo);
  vector<string> time(16);

  for(int i = 0 ; i < 16 ; ++i) cin>>time[i];

  for(int i = 0 ; i < 16 ; ++i){
    for(int j = 0 ; j < 16 ; ++j){
      cin>>prob[i][j];
      prob[i][j] /= 100.0;
    }
  }

  for(int i = 0 ; i < 16 ; ++i){
    printf("%-10s p=%.2f%%\n",time[i].data(),F(i,0,15)*100.0);
  }

  return 0;
}
