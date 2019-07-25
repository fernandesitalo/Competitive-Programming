#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);

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


double cross(point o, point a, point b) { // produto vetorial, area do paralelogramo formado pelos vetores OA e OB
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);   // O -> origem
}



/*
           /\
          / C\
    (B)  /    \    (A)
        /      \
       /        \
      /A________B\
            (C)
 */

// area triangulo = (C*altura)/2
// areaTriangulo = (C*B*sin(A))/2   -> substitui altura por  = sen(A)*hipot, hipot = B
// dá pra isolar sin(A) = 2*Area/(C*B)


int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(2) << fixed;

  // abre;

  point a,b,c,d,z(0,0),p;
  line l1,l2;
  int A,C,B,A1,C1,B1;

  while(1){

    cin>>A>>B>>C>>A1>>B1>>C1;

    if(!(A|B|C|A1|C1|B1)) break;

    double x = B==0?1.0:B;

    l1.a = A/x;
    l1.b = B/x;
    l1.c = -C/x;


    bool flag = true;





    x = B1==0?1.0:B1;

    l2.a = A1/x;
    l2.b = B1/x;
    l2.c = -C1/x;

    if( !(l1.b || l2.b)) flag = false;

    // cout << l1.a << " " << l1.b << " " << l1.c << endl;

    // cout << l2.a << " " << l2.b << " " << l2.c << endl;

    if(flag && areIntersect(l1,l2,p) && fabs(p.x)!= INFINITY && fabs(p.y) != INFINITY){
      cout <<"The fixed point is at ";
      imprime(p);
      cout<< ".\n";
    }
    else {
      cout << "No fixed point exists.\n";
    }
  }
  return 0;
}
