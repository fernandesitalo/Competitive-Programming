#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-15
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)





int main(){

  cout << setprecision(5) << fixed;
  // abre;
  int n;
  double A;

  int ct = 1;

  while(cin>>n>>A){
    if(n <= 2) break;
    double At = A/n;
    double theta = DEG_to_RAD(360.0/n);
    double theta2 = PI/2.0 - theta/2.0;

    double R = sqrt(2*At/sin(theta));
    double r = sqrt(tan(theta2)*A/n);

    double ACIRCULO = PI*R*R;
    double Acirculo = PI*r*r;


    double area1 = ACIRCULO - A;
    double area2 = A - Acirculo;

    cout << "Case "<<ct++<<": "<< area1 <<  " " << area2 << endl;

  }




  return 0;
}
