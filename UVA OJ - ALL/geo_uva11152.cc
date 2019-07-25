#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);



double areaTriagulo(double ab,double bc, double ca){
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  return sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
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


int main(){

  cout << setprecision(4) << fixed;

  int a,b,c;
  while(cin>>a>>b>>c){

    double R = RaioCirculoForaDoTriangulo(a,b,c);
    double r = RaioDoCirculoDentroDoTriangulo(a,b,c);

    double AreaCircMenor = M_PI*r*r;
    double AreaTri = areaTriagulo(a,b,c);
    double AreaCircMaior = M_PI*R*R;

    cout <<   AreaCircMaior - AreaTri << " " << AreaTri - AreaCircMenor << " " << AreaCircMenor << '\n';
  }
  return 0;
}
