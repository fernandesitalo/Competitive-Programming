#include <bits/stdc++.h>
using namespace std;
#define abre freopen("in","r",stdin);



double RaioDoCirculoDentroDoTriangulo(double ab, double bc, double ca){ // lados do triangulo
  double sp = (ab+bc+ca)/2.0; // semi perimetro
  double area = sqrt(sp*(sp-ab)*(sp-bc)*(sp-ca));
  if(area == 0) return 0;
  return area/(0.5*sp*2.0);
}


int main(){
  // abre;
  cout << setprecision(3) << fixed;
  double a,b,c;
  while(cin>>a>>b>>c) cout <<"The radius of the round table is: "<< RaioDoCirculoDentroDoTriangulo(a,b,c) << '\n';
  return 0;
}
