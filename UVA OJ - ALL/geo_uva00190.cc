#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-3
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

inline bool le(point &p){
  if(cin>>p.x>>p.y) return true;
  return false;
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
    (b)  /    \    (a)
        /      \
       /        \
      /A________B\
            (c)

Area = base*altura* 0.5

area triangulo = (c*altura)/2
******* altura = sen(A)*hipot, hipot = b , altura e cateto oposto do angulo A*****
areaTriangulo = (c*b*sin(A))/2
dá pra isolar sin(A) = 2*Area/(c*b)
*/


// dado as 3 medianas do triangulo, dá pra calcular sua area
double Area(double mediana1, double mediana2,double mediana3){
    double sm = (mediana1+mediana2+mediana3)/2.0;
    double temp = sm * (sm-mediana1)*(sm-mediana2)*(sm-mediana3);
    if(0 >= temp) return -1; // nao da pra calcular a area com as medianas fornecidas
    else          return 4.0*sqrt(temp)/3.0;
}

// l1 - lado1, l2 - lado2, l3 - lado3
bool ValidaTriangulo(int l1,int l2,int l3){ // condicao de existencia do triangulo
  return (l1 > abs(l3-l2) && (l3+l2) > l1 &&
    l2 > abs(l1-l3) && (l1+l3) > l2 &&
    l3 > abs(l2-l1) && (l2+l1) > l3);
}


// contando somente com entradas validas
// maior circulo dentro do triangulo
double RaioDoCirculoDentroDoTriangulo(double ab, double bc, double ca){ // lados do triangulo
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  double area = sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
  return area/(0.5*sp*2.0);
}

// menor circulo que contem o triangulo fornecido
double RaioCirculoForaDoTriangulo(double ab, double bc, double ca){
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  double area = sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
  return ab*bc*ca/(4.0*area);
}



// linha perpendicular a l, que passa pelo ponto p
void linhaperpendicular(line l, point p, line &l1){
  // l => ax+by+c = 0

  if(fabs(l.a) < EPS){ // l é horizontal
    l1.a = 1.0;
    l1.b = 0.0;
    l1.c = -p.x;
    return;
  }
  l1.a = -l.b/l.a;
  l1.b = 1.0;
  l1.c = (double) - p.y + (l.b*p.x)/l.a;
}



point pontomedio(point a, point b){
  return point((a.x+b.x)/2.0,(a.y+b.y)/2.0);
}

int main(){
  // cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(4) << fixed;


  point a,b,c,p;
  line l,l1,l2;

  // abre;

  while(le(a) && le(b) && le(c)){
    pointsToLine(a,b,l);
    linhaperpendicular(l,pontomedio(a,b),l1);

    pointsToLine(b,c,l);
    linhaperpendicular(l,pontomedio(b,c),l2);

    areIntersect(l1,l2,p); // p e o centro;

    double R = RaioCirculoForaDoTriangulo(dist(a,b),dist(b,c),dist(c,a));

    if(fabs(p.x) < EPS){
      printf("x^2 + ");
    }else{
      printf("(x %c %.3lf)^2 + ",(p.x >= 0?'-':'+'),fabs(p.x));
    }

    if(fabs(p.y) < EPS){
      printf("y^2 = ");
    }else{
      printf("(y %c %.3lf)^2 = ",p.y >= 0? '-':'+', fabs(p.y));
    }
    printf("%.3lf^2\n",R);

    double c =  2*p.x;
    double d = 2*p.y;
    double e = (p.x*p.x)+(p.y*p.y)-(R*R);


    printf("x^2 + y^2 ");

    if(fabs(c) > EPS){
      printf("%c %.3lfx ",(c >= 0?'-':'+'),fabs(c));
    }
    if(fabs(d) > EPS){
      printf("%c %.3lfy ",(d >= 0?'-':'+'),fabs(d));
    }
    if(fabs(e) >= 0.000){
      printf("%c %.3lf ",(e >= 0?'+':'-'),fabs(e));
    }
    printf("= 0\n\n");
  }
  return 0;
}
