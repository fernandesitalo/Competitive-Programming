#include <bits/stdc++.h>
using namespace std;


#define EPS 1e-10


struct pt{

  long double x,y;
  int id;
  pt(long double x, long double y) : x(x),y(y){}
  pt(){}
  bool operator < (const pt other) const{
    if(fabs(x - other.x) < EPS) return y < other.y;
    return x < other.x;
  }
  bool operator == (const pt other) const{
    return x == other.x && y == other.y;
  }
};



long double cross(pt a, pt b, pt p){
  return (a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x);
}

#define sz(y_) ((int)y_.size())
#define pb push_back

vector<pt> monotoneChain(vector<pt> P){
  sort(P.begin(),P.end());
  P.resize( unique( P.begin(), P.end() ) - P.begin() ) ;

  vector<pt> ch;
  int n = sz(P);

  for(int i = 0 ; i < n ; ++i){
    while(sz(ch) >= 2 && cross(ch[sz(ch)-2],ch[sz(ch)-1],P[i]) <= 0) ch.pop_back();
    ch.pb(P[i]);
  }

  int casco = ch.size()+1;

  for(int i = n-2; i >= 0 ; --i){
    while(sz(ch) >= casco && cross(ch[sz(ch)-2],ch[sz(ch)-1],P[i]) <= 0) ch.pop_back();
    ch.pb(P[i]);
  }

  return ch;
}

inline long double perimetro(vector<pt> & P){
  long double p = 0;
  for(int i = 1 ; i < sz(P) ; ++i){
    p += hypot(P[i].x-P[i-1].x,P[i].y-P[i-1].y);
  }
  return p;
}

int idx(vector<pt> & p){
  int d = 0;
  for(int i = 1 ; i < sz(p) ; ++i){
    if(p[d].y > p[i].y || (p[d].y == p[i].y && p[d].x > p[i].y)) d = i;
  }
  return d;
}

#define endl '\n'

int main(){

  freopen("in","r",stdin);
  cout << setprecision(2) << fixed;
  int n; cin>>n;
  while(n--){
    int k; cin>>k;
    vector<pt> v(k);

    for(int i = 0 ; i < k ; ++i) cin>>v[i].x>>v[i].y,v[i].id = i+1;

    v = monotoneChain(v);
    long double p = perimetro(v)+EPS;
    cout << p << endl;

    if(k == 1) cout << 1 << endl;
    else {
      int i = idx(v);
      v.pop_back();
      for(int q = 0 ; q < sz(v) ; ++q){
        if(q > 0) cout << ' ';
        cout << v[i].id;
        if(++i == sz(v)) i = 0;
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
