#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> ponto;
#define x first
#define y second

struct quadrilatero{
  ponto lowerLeft,upperRight;
};

// interseccao entre dois quadrilateros
bool SobrePosicao(quadrilatero a, quadrilatero b, quadrilatero &ans){

    double maxX = max(a.lowerLeft.x, b.lowerLeft.x);
    double minX = min(a.upperRight.x, b.upperRight.x);
    double maxY = max(a.lowerLeft.y, b.lowerLeft.y);
    double minY = min(a.upperRight.y, b.upperRight.y);

    if (maxX >= minX || minY <= maxY)
        return false;

    ans = quadrilatero{ ponto(maxX, maxY) , ponto(minX, minY) };
    return true;
}


int main(){

  int t;
  cin>>t;


  for(int ct = 1; ct <= t ; ++ct){



    quadrilatero sobreposicao,aux1,aux2;
    bool o = true;

    int n;
    cin>>n;

    // if(n == 0){
      // cout << "Case "<<ct << ": 0\n";
      // continue;
    // }

    cin>>sobreposicao.lowerLeft.x>>sobreposicao.lowerLeft.y>>sobreposicao.upperRight.x>>sobreposicao.upperRight.y;

    for(int i = 1 ; i < n;  ++i){

      cin>>aux2.lowerLeft.x>>aux2.lowerLeft.y>>aux2.upperRight.x>>aux2.upperRight.y;

      if(o && SobrePosicao(sobreposicao,aux2,sobreposicao)){
        // ok;
      }else{
        o = false;
        sobreposicao = quadrilatero{ponto(0,0),ponto(0,0)};
      }
    }

    int area = abs(sobreposicao.lowerLeft.x-sobreposicao.upperRight.x)*abs(sobreposicao.lowerLeft.y-sobreposicao.upperRight.y);

    cout << "Case "<<ct << ": "<< area <<"\n";
  }

  return 0;
}
