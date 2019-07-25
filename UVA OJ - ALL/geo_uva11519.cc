#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9
#define DEG_to_RAD(theta_) (M_PI*theta_/180.0)
#define abre freopen("in","r",stdin);
#define pb push_back
#define PI 2*acos(0)

typedef pair<string,int> cmd;
vector<cmd> path;
int k; // onde o '?' está

void angulo(){
  double x,y;
  for(int angulo = 0 ; angulo < 360 ; ++angulo){
    path[k].second = angulo;
    double theta = 0.0;
    x = 0.0;
    y = 0.0;
    for(int i = 0 ; i < (int) path.size() ; ++i){
      string str = path[i].first;
      double uni = path[i].second;

      if(str == "fd"){
        y += sin(DEG_to_RAD(theta))*uni;
        x += cos(DEG_to_RAD(theta))*uni;
      }
      else if(str == "lt")     theta -= uni;
      else if(str == "rt")     theta += uni;
      else{
        y -= sin(DEG_to_RAD(theta))*uni;
        x -= cos(DEG_to_RAD(theta))*uni;
      }
    }

    if(fabs(x) < 0.01 && fabs(y) < 0.01){
      cout << angulo << '\n';
      return;
    }
  }
}


void dist(){

  double x,y,xx,yy,theta = 0.0;

  for(int i = 0 ; i < k ; ++i){
    string str = path[i].first;
    double uni = path[i].second;

    if(str == "fd"){
      y += sin(DEG_to_RAD(theta))*uni;
      x += cos(DEG_to_RAD(theta))*uni;
    }
    else if(str == "lt")     theta -= uni;
    else if(str == "rt")     theta += uni;
    else{
      y -= sin(DEG_to_RAD(theta))*uni;
      x -= cos(DEG_to_RAD(theta))*uni;
    }
  }

  xx = x;
  yy = y;

  for(int i = k+1 ; i < (int)path.size() ; ++i){
    string str = path[i].first;
    double uni = path[i].second;

    if(str == "fd"){
      yy += sin(DEG_to_RAD(theta))*uni;
      xx += cos(DEG_to_RAD(theta))*uni;
    }
    else if(str == "lt")     theta -= uni;
    else if(str == "rt")     theta += uni;
    else{
      yy -= sin(DEG_to_RAD(theta))*uni;
      xx -= cos(DEG_to_RAD(theta))*uni;
    }
  }

  cout << hypot(xx,yy) << '\n';
}




int main(){
  cin.sync_with_stdio(0),cin.tie(0);
  cout << setprecision(0) << fixed;

  // abre;

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    path.clear();

    bool ehangulo = false;

    for(int i = 0 ; i < n ; ++i){
      string c,q;
      cin>>c>>q;
      if(q[0] == '?'){
        path.push_back(cmd(c,0));
        if(c == "lt" || c == "rt") ehangulo = true;
        k = i;
      }else{
        stringstream ss(q);
        int aux; ss>>aux;
        path.push_back(cmd(c,aux));
      }
    }

    if(ehangulo){
      angulo();
    }else{
      dist();
    }
  }
  return 0;
}
