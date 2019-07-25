#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)

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


// dado 2 pontos do circulo e seu raio,achamos seu centro
bool cicle2PtsRad(point p1,point p2,double r, point &c){

  double d2 = (p1.x - p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y-p2.y);
  double det = r*r / d2 - 0.25;

  if(det < 0.0) return false;

  double h = sqrt(det);
  c.x = (p1.x+p2.x)*0.5 + (p1.y - p2.y)*h;
  c.y = (p1.y+p2.y)*0.5 + (p1.x - p2.x)*h;
  return true;
}



// retorna 0 para dentro do circulo, 1 para borda, 2 para fora do circulo
int insideCircle(point p, point c, double R){
  double dx = p.x - c.x , dy = p.y - c.y;
  double Euc = dx*dx + dy*dy, rSq = R*R;
  return (cmp(Euc,rSq) < 0 ? 0 : fabs(Euc-rSq) < EPS ? 1 : 2);
}


struct retangulo{
  point cd,be;//cima direita, baixo esquerda

  int id;

  retangulo(point a, point b, int id_){
    cd = point(max(a.x,b.x),max(a.y,b.y));
    be = point(min(a.x,b.x),min(a.y,b.y));
    id = id_;
  }

  bool pontoEstaDentro(point p){
    return (cd.x > p.x && cd.y > p.y && p.x > be.x && p.y > be.y);
  }
};


struct circulo{
  point c;
  double r;

  int id;

  circulo(point c, double r,int id) : c(c) , r(r) , id(id) {}
  circulo(){}
};

int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(4) << fixed;
  // abre;
  point A,B;
  string op;
  vector<retangulo> R;
  vector<circulo> C;
  int ID = 1;
  while(cin>>op, op != "*"){
    if(op == "r"){
      le(A),le(B);
      R.pb(retangulo(A,B,ID++));
    }
    else{
      le(A);
      double r; cin>>r;
      C.pb(circulo(A,r,ID++));
    }
  }

  point flag(9999.9,9999.9);

  int cntPonto = 1;

  while(le(A), !(A == flag)){

    vector<int> ans;

    for(int i = 0 ; i <(int) R.size() ; ++i){
      if(R[i].pontoEstaDentro(A)){
        ans.pb(R[i].id);
      }
    }


    for(int i = 0 ; i <(int) C.size() ; ++i){
      if(insideCircle(A,C[i].c,C[i].r) == 0){
        ans.pb(C[i].id);
      }
    }


    if(!(int)ans.size()){
      cout << "Point "<<cntPonto<<" is not contained in any figure\n";
    }else{
      sort(ans.begin(),ans.end());
      for(int i = 0 ; i < (int)ans.size() ; ++i){
        cout << "Point " <<cntPonto<< " is contained in figure "<< ans[i] << '\n';
      }
    }
    cntPonto++;

  }

  return 0;
}
