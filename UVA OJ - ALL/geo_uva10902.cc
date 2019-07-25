#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back


// template<class type>
struct point{
  double x,y;

  point(): x(0),y(0){}
  point(double x, double y):x(x),y(y){}
  bool operator < (point other){
    if(fabs( x- other.x ) > EPS) return x < other.x; // x != x.other
    return y < other.y;     // x == x.other
  }
  bool operator == (point other){
    return (fabs(x-other.x) < EPS && (fabs(y-other.y)) < EPS);
  }
};

// rotacionar o ponto p theta graus no sentido horario
// theta deve estar em graus!
point rotate(point p, double theta){
  double rad = DEG_to_RAD(theta);
  return point(p.x*cos(rad) - p.y*sin(rad),p.x*sin(rad) + p.y*cos(rad)); // matriz de rotação CP3
}


double dist(point p1,point p2){ // distancia euclidiana
  return hypot(p1.x - p2.x,p1.y-p2.y);
}

struct line{
  double a,b,c;
};

void pointsToLine(point p1,point p2, line &l){ // dado 2 pontos controi uma linha
  if(fabs(p1.x - p2.x) < EPS){
    l.a = 1.0; l.b = 0.0;  l.c = -p1.x;
  }else {
    l.a = -(double) (p1.y-p2.y)/(p1.x-p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a*p1.x) - p1.y;
  }
}

bool areParallel(line l1,line l2){  //  l1//l2 ?
  return (fabs(l1.a-l2.a) < EPS) && fabs(l1.b-l2.b) < EPS;
}

bool areSame(line l1, line l2){ //      l1 == l2 ?
  return areParallel(l1,l2) && (fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(line l1,line l2,point &p){ //   l1 intercepta l2 ?
  if(areParallel(l1,l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                 p.y = -(l2.a * p.x + l2.c);
  return true;
}


struct vec{ // vetor matematico
  double x,y;
  vec(double x,double y) : x(x), y(y) {}
};

vec ToVec(point a, point b){ // AB = B - Acontroi um vec dado dois pontos
  return vec(b.x - a.x,b.y - a.y);
}
vec scale(vec v, double s){ // multiplicar um scalar s pelo vetor v
  return vec(v.x*s,v.y*s);
}
point translate(point p, vec v){ // p passa a ser origem do vetor v
  return point(p.x+v.x,p.y+v.y);
}

double dot(vec a,vec b){    // produto escalar, vetor A * vetor B
 return (a.x*b.x + a.y*b.y);
}

double norm_sq(vec v){    // ????????????????????????????????????????????????????
  return v.x*v.x+v.y*v.y;
}

double distToline(point p, point a, point b,point &c){ // distancia minima de um ponto a uma linha
  vec ap = ToVec(a,p);
  vec ab = ToVec(a,b);
  double u = dot(ap,ab) / norm_sq(ab);
  c = translate(a,scale(ab,u));
  return dist(p,c);
}

double distTolineSegment(point p, point a, point b, point &c){ // distancia do ponto p ao segmento ab
  vec ap = ToVec(a,p);
  vec ab = ToVec(a,b);
  double u = dot(ap,ab)/norm_sq(ab);
  if(u < 0.0){
    c = point(a.x,a.y);
    return dist(p,a);
  }
  if(u > 1.0){
    c = point(b.x,b.y);
    return dist(p,b);
  }
  return distToline(p,a,b,c);
}


double angle(point a, point o, point b){ // angulo AOB
  vec oa = ToVec(o,a);
  vec ob = ToVec(o,b);
  return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double cross(vec a, vec b){
  return a.x*b.y-a.y*b.x;
}

bool ccw(point p, point q, point r){
  return cross(ToVec(p,q),ToVec(p,r)) > 0;
}

bool collinear(point p, point q, point r){
  return fabs(cross(ToVec(p,q),ToVec(p,r))) < EPS;
}

inline void le(point &p){
  cin>>p.x>>p.y;
}

inline void imprime(point p){
  cout << p.x<<" " << p.y;
}

// 1 -  x > y
// 0 - x == y
// -1  x < y
inline int cmp(long double x,long  double y = 0, long double tol = EPS){
  return (x <= y + tol) ? (x+tol < y) ? -1 : 0 : 1;
}
//#########################################
bool VERIFICA(point a, point b, point p){ // verifica se o ponto p esta entre os pontos 'a' e 'b'
  if(cmp(a.x,b.x) > 0) swap(a,b); // a - left, b-right

  if(cmp(p.x,a.x) >= 0 && cmp(b.x,p.x) >= 0){

    if(cmp(a.y,b.y) > 0) swap(a,b); // b - top, a-botton
    if(cmp(p.y,a.y) >= 0 && cmp(b.y,p.y) >= 0){
      return true;
    }
  }
  return false;
}



// bool VERIFICA(point a, point b, point p){
  // return (dist(a,p)-EPS <= dist(a,b) && dist(b,p) - EPS <= dist(a,b));
// }

struct coisa{
  line l;
  point a,b;
  coisa(){}
};


//https://blog.csdn.net/synapse7/article/details/19116327

int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  abre;
  int n; point p;
  while(cin>>n,n){

    point a,b;
    coisa vet[n+1];
    for(int i = 0 ; i < n ; ++i){
      le(a),le(b);
      pointsToLine(a,b,vet[i].l);
      vet[i].a = a;
      vet[i].b = b;
    }

    vector<int> ans;
    vector<int> cont(n+2,0);

    for(int i = n-1 ; i >= 0 && 1000 > ans.size(); --i){
      for(int j = i-1 ; j >= 0 ; --j){
        if(cont[j]== 0 && (areIntersect(vet[i].l,vet[j].l,p) && VERIFICA(vet[i].a,vet[i].b,p)  && VERIFICA(vet[j].a,vet[j].b,p))){
          cont[j]++;
        }
      }

      if(cont[i] == 0){
        ans.pb(i+1);
      }

    }

    cout << "Top sticks:";
    for(int i = ans.size()-1 ; i >= 0 ; --i){
      if((int)ans.size()-1 != i) cout << ',';
      cout << " " << ans[i];
    }
    cout << ".\n";

  }
  return 0;
}

