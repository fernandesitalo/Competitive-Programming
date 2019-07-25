#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI acos(-1.0)


int main(){

  cout << setprecision(10) << fixed;

  int R,N;

  while(cin>>R>>N){


    if(N == 1){
      cout << (double)R <<" "<< 0.0 << " " <<0.0<<'\n';
      continue;
    }

    double theta = 2.0*PI/N;

    double x = sqrt( 2.0*R*R*(1.0 - cos(theta) ));

    double r = x*R/(2.0*R+x);


    double R1 = R - r;

    double angle = PI*(N-2)/N;


    double AreaPoligonoRegular =  r*sqrt(R1*R1-r*r)*N;

    double AreaAzul = AreaPoligonoRegular - (r*r*angle*N*0.5);

    double AreaVerde = PI*R*R - AreaAzul - PI*r*r*N;

    cout <<  r << " " << AreaAzul << " " << AreaVerde << '\n';





  }




  return 0;
}
