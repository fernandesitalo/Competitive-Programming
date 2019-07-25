#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ponto;
typedef pair<ponto,ponto> quadrilatero;

#define x first
#define y second

bool SobrePosicao(quadrilatero a, quadrilatero b, quadrilatero &ans){

    double maxX = max(a.first.x, b.first.x);
    double minX = min(a.second.x, b.second.x);
    double maxY = max(a.first.y, b.first.y);
    double minY = min(a.second.y, b.second.y);

    if (maxX >= minX || minY <= maxY)
        return false;

    ans = quadrilatero( ponto(maxX, maxY) , ponto(minX, minY) );
    return true;
}




int main(){

  int t; cin>>t;
  quadrilatero ans;
  quadrilatero a,b;
  while(t--){
    cin>>a.first.x>>a.first.y>>a.second.x>>a.second.y;
    cin>>b.first.x>>b.first.y>>b.second.x>>b.second.y;
    if(SobrePosicao(a,b,ans)){
      cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << '\n';
    }else{
      cout << "No Overlap\n";
    }
    if(t) cout << '\n';
  }

  return 0;
}
