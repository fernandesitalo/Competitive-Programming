#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);


int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(3) <<  fixed;
  double l,w,h,theta;
  // abre;

  while(cin>>l>>w>>h>>theta){
    theta = DEG_to_RAD(theta);

    double k = sqrt(l*l+h*h);
    double alfa = l/k; // sin de alfa
    alfa = asin(alfa);

    if(theta > (M_PI/2.0-alfa)){
      double angle1 = M_PI-theta-M_PI/2.0;

      double xx = sin(angle1)*h;
      double bb = cos(angle1)*h;

      double angle2 = M_PI - M_PI/2.0 - angle1;

      double yy = xx/sin(angle2);
      double jj = cos(angle2)*yy;


      cout <<  ((bb+jj)*xx/2.0*w) << " mL\n";
      continue;
    }

    double packet = w*l*h;
    double angle = M_PI - M_PI/2.0 -theta;


    double x = sin(theta)*l;

    double y = x/sin(angle);
    double j = y*cos(angle);
    double b = cos(theta)*l;


    double xicara = (b+j)*x/2.0*w;

    cout << (packet - xicara) << " mL\n";
  }
  return 0;
}
