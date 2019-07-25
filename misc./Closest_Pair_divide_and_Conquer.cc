#include <bits/stdc++.h>
using namespace std;
typedef long double lf;
typedef pair<lf,lf> pt;
#define x first
#define y second
#define infl 0x3f3f3f3f3f3f3fl

lf dist(pt a,pt b){  return hypot(a.x - b.x,a.y - b.y); }

// divisão e conquista
lf closestPair(pt P[], int n){
  if (n <= 3){
    lf D = infl;
    for(int i = 0; i < n; ++i)
    for(int j = i+1; j < n; ++j)
      D = min(D,dist(P[i], P[j]));
    return D;
  }

  int mid = n/2;
  pt midPT = P[mid];

  lf dl = closestPair(P, mid); // left
  lf dr = closestPair(P + mid, n-mid); // right
  lf D = min(dl, dr);

  pt faixaX[n];
  int sz = 0;

  // pega todo mundo que esta tao perto qnto D
  for(int i = 0; i < n; i++)
  if(fabs(P[i].x - midPT.x) < D) faixaX[sz] = P[i], sz++;

  // ordena pelo 'Y'
  sort(faixaX,faixaX+sz,[](pt a, pt b){return a.y < b.y;});

  // vai att D
  for (int i = 0; i < sz; ++i)
  for (int j = i+1; j < sz && (faixaX[j].y - faixaX[i].y) < D; ++j)
    D = min(D,dist(faixaX[i], faixaX[j]));

  return D;
}

lf closest(pt P[], int n){
  // ordena por X
  sort(P,P+n,[](pt a, pt b){return a.x < b.x;});
  return closestPair(P, n);
}

int main(){return 0;}
