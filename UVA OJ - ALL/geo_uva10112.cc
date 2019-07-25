#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

struct ponto{
  double x,y;
  ponto(double x, double y) : x(x),y(y){}
  ponto(){}

  bool operator != (ponto o){
    return x != o.x && y != o.y;
  }
};

inline int cmp(long double x,long  double y = 0, long double tol = EPS){
  return (x <= y + tol) ? (x+tol < y) ? -1 : 0 : 1;
}

bool cmp(ponto a, ponto b){
  if(fabs(a.x - b.x) < EPS) return a.y < b.y;
  return a.x < b.x;
}

//  1  a.x  a.y  1  a.x
//  1  b.x  b.y  1  b.x
//  1  p.x  p.y  1  p.x


int ProdutoVetorial(ponto a, ponto b, ponto p){
  double det = (a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x);
  return (fabs(det) < EPS ? 0 : det > 0 ? 1 : -1);
}

double det(ponto a, ponto b, ponto p){
 return fabs((a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x));
}

//triangulo a,b,c
// ponto p

double dist(ponto a, ponto b){
 return hypot(a.x-b.x,a.y-b.y);
}

// l1 - lado1, l2 - lado2, l3 - lado3
bool ValidaTriangulo(double l1,double l2,double l3){ // condicao de existencia do triangulo
  return cmp((l3+l2),l1) > 0 && cmp((l1+l3) , l2) > 0 && cmp((l2+l1) , l3) > 0;
}

bool dentro(ponto a, ponto b, ponto c,ponto p){
  int A = ProdutoVetorial(p,a,b);
  int B = ProdutoVetorial(p,a,c);
  int C = ProdutoVetorial(p,b,c);
  return  (A!=B && B!=C);
}

#define pb push_back
#define go freopen("in","r",stdin);
int main(){
// go

  int n;

  while(cin>>n,n){
    vector<ponto> P;
    ponto A;
    string buffer;
    for(int i = 0 ; i < n ; ++i){
      cin>>buffer>>A.x>>A.y;
      P.pb(A);
    }

    string ans("ABC");
    double ar = 0.0;
    for(int i = 0 ; i < n ; ++i){
      for(int j = i+1 ; j < n ; ++j){
        for(int k = j+1 ; k < n ; ++k){
          if(ValidaTriangulo(dist(P[i],P[j]),dist(P[i],P[k]),dist(P[j],P[k]))){
            bool o = true;
            for(int u = 0 ; u < n; ++u){
              if(i != u && j != u && k != u && dentro(P[k],P[i],P[j],P[u])){
                o = false;

                // cout << P[u].x << " " << P[u].y << "  esta dentro   " << P[i].x << " " << P[i].y << "     " << P[j].x << " " << P[j].y << "      " << P[k].x << " " << P[k].y <<'\n';

                break;
              }
            }



            if(o){
              double A = det(P[i],P[j],P[k]);
              // printf("%c%c%c     %lf\n",'A'+i,'A'+j,'A'+k,A);
              if(A > ar){
                ar = A;
                ans = ('A'+i);
                ans += ('A'+j);
                ans += ('A'+k);
              }
            }

          }


        }
      }
    }

    sort(ans.begin(),ans.end());

    cout << ans << '\n';

  }



  return 0;
}
