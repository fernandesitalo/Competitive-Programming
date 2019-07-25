#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)


#define x first
#define y second
typedef pair<int,int> ponto;


typedef pair<ponto,ponto> quadrilatero;



inline bool quadrilateroIntercecao(quadrilatero r1, quadrilatero r2, quadrilatero &c)
{

    /*
    x1 = q1.first.x
    y1 = q1.first.y
    x2 = q1.second.x
    y2 = q1.second.y
    x3 = q2.first.x
    y3 = q2.first.y
    x4 = q2.second.x
    y4 = q2.second.y
    */

    double maxX = max(r1.first.x, r2.first.x);
    double minX = min(r1.second.x, r2.second.x);
    double maxY = max(r1.first.y, r2.first.y);
    double minY = min(r1.second.y, r2.second.y);

    if (maxX >= minX || minY <= maxY)
        return false;

    c = quadrilatero(ponto(maxX, maxY),ponto(minX, minY));
    return true;
}

int main(){
  freopen("in","r",stdin);
  freopen("out","w",stdout);

  int t;cin>>t;


  ponto a,b,c,d;

  int ct = 1;
  while(t--){
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

    quadrilatero q(ponto(0,0),ponto(0,0));
    quadrilateroIntercecao(quadrilatero(a,b),quadrilatero(c,d),q);

    int strongly = abs(q.first.x-q.second.x)*abs(q.first.y-q.second.y);

    int weakly = abs(a.x-b.x)*abs(a.y-b.y) + abs(c.x-d.x)*abs(c.y-d.y) - 2*strongly;

    int unsecured = 100*100 - (weakly + strongly);

    cout <<"Night "<<ct++<<": "<< strongly << " " << weakly << " " <<  unsecured <<'\n';



  }

  return 0;
}
