#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)
#define INF 0x3f3f3f3f3f3fl

struct pt{
  double x,y;
  pt(): x(0),y(0){}
  pt(double x, double y):x(x),y(y){}
  bool operator < (const pt outro) const {
    if(fabs( x- outro.x ) > EPS) return x < outro.x; // x != x.outro
    return y < outro.y;     // x == x.outro
  }
  pt operator - (const pt other) const {
    return pt(x-other.x,y-other.y);
  }
  pt operator * (double k){ return pt(x * k, y * k); }
  pt operator + (pt p){ return pt(x + p.x, y + p.y); }
  bool operator == (const pt outro) const {
    return (fabs(x-outro.x) < EPS && (fabs(y-outro.y)) < EPS);
  }
};



// produto vetorial
long double cross(pt a, pt b, pt p){
  return (a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x);
}

// convex hull que pega pontos colineares de acordo com a o produto vetorial
vector<pt> MonotoneChain(vector<pt> P){
  // corne case : 1 || 2 pts
  sort(P.begin(),P.end());
  // para pontos repetidos
  // P.resize( unique( P.begin(), P.end() ) - P.begin() ) ;

  #define sz(C_) (int)C_.size()

  if(P.size() <= 2){
      P.push_back(P[0]);return P;
  }

  vector<pt> ch;
  int n = sz(P);
  for(int i = 0 ; i < n ; ++i){
    while(sz(ch) >= 2 && cross(P[i],ch[sz(ch)-1],ch[sz(ch)-2]) <= 0) ch.pop_back();
    ch.pb(P[i]);
  }

  int casco = ch.size()+1;

  for(int i = n-2; i >= 0 ; --i){
    while(sz(ch) >= casco && cross(P[i],ch[sz(ch)-1],ch[sz(ch)-2]) <= 0) ch.pop_back();
    ch.pb(P[i]);
  }
  return ch;
}

typedef vector<pt> polygon;

double norma2(pt a){
  return a.x*a.x+a.y*a.y;
}

double dot(pt a, pt b){
  return a.x*b.x+a.y*b.y;
}

// angulo AOB
double angle(pt a, pt o, pt b){
  pt oa = a-o;
  pt ob = b-o;
  return acos(dot(oa,ob)/sqrt(norma2(oa)*norma2(ob)));
}


// borda e considerado dentro
// poligono pode ser concavo ou convexo
bool inside_poly(pt p, const vector<pt> &P){
  if((int)P.size() == 0) return false;
  double sum = 0;
  for(int i = 0 ; i < (int) P.size() - 1 ; ++i){
    if(cross(p,P[i],P[i+1]) > 0)  sum += angle(P[i],p,P[i+1]);
    else                     sum -= angle(P[i],p,P[i+1]);
  }
  return fabs(fabs(sum) - 2*PI) < EPS;
}

inline int cmp(long double x,long  double y = 0, long double tol = EPS){
  return (x <= y + tol) ? (x+tol < y) ? -1 : 0 : 1;
}

//testa se p esta na caixa limitada por a e b
bool in_box(pt a, pt b, pt p){
  return ( cmp(p.x, min(a.x, b.x)) >= 0 && cmp(p.x, max(a.x, b.x)) <= 0
      &&   cmp(p.y, min(a.y, b.y)) >= 0 && cmp(p.y, max(a.y, b.y)) <= 0 );
}

// determinate de 2 vetores...
double cross(pt a, pt b){
  return a.x*b.y-a.y*b.x;
}
double det2pts(pt a, pt b){
  return ((a.x*b.y) - (b.x*a.y));
}

// area com sinal
double signed_area(pt a, pt b, pt c){
  return cross((a-c),(b-c))/2.0;
}



//interseccao entre as retas a->b e c->d e guarda em inter
bool intersect2(pt a, pt b, pt c, pt d, pt& inter){
  double det = cross(b-a, d-c);
  if(fabs(det) < EPS){
      if( fabs(signed_area(a, b, c) ) < EPS){
          inter = pt(INF, INF);
          return true; //retas coincidentes
      }
      return false; //retas paralelas
  }
  //retas concorrentes
  double ua = ( cross(d-c, a-c) )/det; //parametros (pode ser importante)
// double ub = ( cross(b-a, a-c) )/det;
  inter = a + (b-a)*ua;
  return true;
}

//testa se exsite interseccao entre os dois segmentos
bool intersect_seg(pt a, pt b, pt c, pt d, pt& inter){
  if( !intersect2(a, b, c, d, inter) ) return false; //segmentos paralelos
  if( inter == pt(INF, INF) )
      return in_box(a, b, min(c, d)) || in_box(c, d, min(a, b)); //segmentos sobrepostos
  return in_box(a, b, inter) && in_box(c, d, inter); //segmentos concorrentes
}



bool intersect(polygon a, polygon b, polygon& inter){
    polygon pts;
    pt p;

    //pontos dentro da regiao
  for(int i = 0; i < (int)a.size(); i++)
    if(inside_poly(a[i], b))pts.push_back(a[i]);

  for(int i = 0; i < (int)b.size(); i++)
    if(inside_poly(b[i], a)) pts.push_back(b[i]);

  //pontos gerados pela intersecao de segmentos
  for(int i = 0; i < (int)a.size(); i++)
    for(int j = 0; j < (int)b.size(); j++)
      if(intersect_seg(a[i], a[(i+1)%a.size()], b[j], b[(j+1)%b.size()], p) && !(p == pt(INF, INF)) ){
        pts.push_back(p);
      }


  //sem poligono de intersecao
  if(pts.size() <= 1) return false;
  //faz o fecho convexo da solucao

  inter = MonotoneChain(pts);
  return true;
}

bool ccw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) < 0; }


int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool is_convex(polygon& p){
    int left = 0, right = 0, side;
    for(int i = 0; i < p.size(); i++){
        side = side_sign(p[i], p[(i+1)%p.size()], p[(i+2)%p.size()]);
        if(side < 0) right++;
        if(side > 0) left++;
    }
    return !(left && right);
}


double area(const vector<pt> &P){
  double A = 0.0,x1,y1,x2,y2;
  for(int i = 0 ; i < (int) P.size()-1 ; ++i){
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    A += (x1*y2 - x2*y1);
  }
  return fabs(A)/2.0;
}

void read(pt & p){
  cin>>p.x>>p.y;
}

int main(){

  freopen("in","r",stdin);

  int ct = 1;

  int n;
  while(cin>>n,n){
    polygon A(n);
    for(int i = 0 ; i < n ; ++i) read(A[i]);

    cin>>n;
    polygon B(n);
    for(int i = 0 ; i < n ; ++i) read(B[i]);
    polygon C;

    A.push_back(A[0]);
    B.push_back(B[0]);

    // if(is_convex(A)) cout << "A E CONVEXO\n";
    // if(is_convex(B)) cout << "B E CONVEXO\n";

    if(MonotoneChain(A).size() != A.size()) cout << ct << '\n';
    if(MonotoneChain(B).size() != B.size()) cout << ct << '\n';

    ct++;

    // MonotoneChain(B);


    double ans = area(A) + area(B);

    if(intersect(A,B,C)) ans -= 2.*area(C);
    // cout << ct++ << "    ";
    // printf("%8.2lf\n",ans);
    // cout << endl;
  }cout << endl;


  return 0;
}
