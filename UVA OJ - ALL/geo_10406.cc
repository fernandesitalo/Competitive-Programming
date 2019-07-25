#include <bits/stdc++.h>
using namespace std;
typedef long double lf;
#define EPS 1e-9
#define pi acos(-1)
struct pt{
  lf x,y;
  pt(){}
  pt(lf x, lf y) : x(x),y(y){}
  pt operator - (const pt other) const{
    return pt(x-other.x,y-other.y);
  }
  bool operator == (const pt other) const{
    return (fabs(x-other.x)< EPS && fabs(y-other.y) < EPS);
  }
};


// rotacionar o pt p theta graus no sentido ANTIHORARIO origem(0,0)
// theta em radianos
pt rotate(lf theta,pt p){
  return pt(p.x*cos(theta) - p.y*sin(theta),p.x*sin(theta) + p.y*cos(theta));
}

// produto vetorial
lf cross(pt a, pt b, pt p){
  return (a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x);
}

lf cross(pt a,pt b){ return a.x*b.y - a.y*b.x; }

// line segment p-q intersect with line A-B.
pt lineIntersectSeg(pt p,pt q,pt A,pt B) {
  // coeficientes da line
  lf a = B.y - A.y;
  lf b = A.x - B.x;
  lf c = B.x * A.y - A.x * B.y;

  // substitui o pt na lina
  lf u = fabs(a * p.x + b * p.y + c);
  lf v = fabs(a * q.x + b * q.y + c);

  // faz pt
  return pt( (p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}



/// ESSA FUNCAO AQUI, PEGA SOMENTE O POLIGONO CORTADO QUE ESTA A ESQUERDA...
/// SE EU QUISER O OUTRO LADO QUE NAO E O ESQUERDO, E SO INVERTER OS ptS 'A' E 'B'
vector<pt> cut_polygon(pt a, pt b, const vector<pt> &Q) {
  vector<pt> P;

  for (int i = 0; i < (int)Q.size(); i++) {
    lf left1 = cross(b-a,Q[i]-a);
    lf left2 = 0;

    if (i != (int)Q.size()-1){
       left2 = cross(b-a,Q[i+1]-a);
    }

    cout << "OK\n";


    if (left1 > -EPS){
       P.push_back(Q[i]); // Q[i] is on the left of ab
    }

    if (left1 * left2 < -EPS){ // edge (Q[i], Q[i+1]) crosses line ab
      P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
  }

  if (!P.empty() && !(P.back() == P.front())){
    P.push_back(P.front()); // make P’s first pt = P’s last pt
  }
  return P;
}

int main(){
  freopen("in","r",stdin);

  int n;
  lf d;
  while(1){

    scanf("%Lf",&d);
    scanf("%d",&n);
    if(n == 0 && fabs(d) < EPS) break;
    vector<pt> P(n+1);

    for(int i = 0 ; i < n ; ++i){
      scanf("%Lf%Lf",&P[i].x,&P[i].y);
    }
    P[n] = P[0];
    pt a(100,d);
    pt b(-100,d);

    reverse(P.begin(),P.end());

    cout << setprecision(2) << fixed;

    for(int k = 1 ; k < n+1 ; k++){

      int i = k%n;
      pt temp = P[i];

      pt temp2 = P[i+1]-temp;
      lf alfa = atan2(temp2.y,temp2.x);
      if(0 > alfa) alfa += 2*pi;
      alfa = 2*pi - alfa;

      for(int j = 0 ; j <= n ; ++j){
        P[j] = rotate(alfa,(P[j]-temp));
      }

      P = cut_polygon(b,a,P);

    }

    lf ar = 0;
    for(int i = 2 ; i < (int)P.size()-1 ; ++i){
      ar += cross(P[0],P[i],P[i-1]);
    }
    ar = fabs(ar);
    printf("%.3Lf\n",ar/2.);

  }

  return 0;
}
