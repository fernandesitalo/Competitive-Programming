#include <bits/stdc++.h>
using namespace std;
typedef long double lf;
int const maxn = 1e5+100;
#define EPS 1e-9

struct pt{
  lf x,y;
  pt(lf x, lf y) : x(x),y(y){}
  pt(){}
  bool operator < (const pt other) const{return (y < other.y); }
  bool operator == (const pt other) const{return (x == other.x && y == other.y);}
  lf dist(const pt other) const{  return hypot(x-other.x,y-other.y);}
  void read(){cin>>x>>y; }
} P[maxn];
int N; // quantidade de pontos

lf closest(){
  // if(N == 1) return infl ou 0;
  // set ordenado por y
  set<pt> sty(P,P+N);
  // vetor ordenado por x
  sort(P,P+N,[](pt a,pt b){ return a.x < b.x;});

  set<pt>::iterator it,pos;
  int j;
  lf ans = P[0].dist(P[1]);

  for(int i = 0 ; i < N ; ++i){ // pt atual i
    pos = sty.lower_bound(pt(P[i].y,0));
    it = pos;

    // varrer eixo y
    // para esquerda
    do{
      if(!(*it == P[i])) ans = min(ans,P[i].dist(*it));
      it--;
    }while(it != sty.begin() && fabs((*it).y-P[i].y) <= ans);

    // para direita
    it = pos;
    while(it != sty.end() && fabs((*it).y -P[i].y) <= ans){
      if(!(*it == P[i])) ans = min(ans,P[i].dist(*it));
      it++;
    }
    // varre eixo x
    // para esquerda
    j = i-1;
    while (j >= 0 && fabs(P[j].x - P[i].x) <= ans) ans = min(ans,P[i].dist(P[j--]));
    // para direita
    j = i+1;
    while (N > j && fabs(P[j].x - P[i].x) <= ans) ans = min(ans,P[i].dist(P[j++]));
  }
  return ans;
}

int main(){  return 0; }
