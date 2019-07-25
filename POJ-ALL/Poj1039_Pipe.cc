#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;


typedef long double lf;
typedef pair<lf,lf> pt;
#define x first
#define y second
#define EPS 1e-8
#define INF 1e40

inline int cmp(lf xx,lf y = 0){
  return (xx <= y + EPS) ? (xx+EPS < y) ? -1 : 0 : 1;
}
bool in_box(pt a, pt b, pt c){
    return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
        &&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}

// line segment p-q intersect with line A-B.
lf lineIntersectSeg(pt p,pt q,pt A,pt B) {
  // coeficientes da line
  lf a = B.y - A.y;
  lf b = A.x - B.x;
  lf c = B.x * A.y - A.x * B.y;

  // substitui o pt na lina
  lf u = fabs(a * p.x + b * p.y + c);
  lf v = fabs(a * q.x + b * q.y + c);

  // faz pt
  pt inter( (p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
  if(in_box(p,q,inter)) return inter.x;
  return -INF;
}
lf cross(pt a, pt b, pt p){ 
	//~ lf d =
	return  (a.y*p.x)+(a.x*b.y)+(b.x*p.y)-(a.x*p.y)-(b.y*p.x)-(a.y*b.x); 
	//~ return d == 0 ? 0 : cmp(d,0) > 0 ? 1 : -1;
}

pt sup[30];
pt inf[30];
int n;

lf solve(pt A, pt B){
	
	for(int i = 0 ; i < n-1 ; ++i){
		lf t1 = cross(A,B,sup[i]);
		lf t2 = cross(A,B,sup[i+1]);
		
		lf t3 = cross(A,B,inf[i]);
		lf t4 = cross(A,B,inf[i+1]);
		
		if(t1 < -EPS|| t2 < -EPS) return lineIntersectSeg(sup[i],sup[i+1],A,B);
		if(t3 > EPS || t4 > EPS) return lineIntersectSeg(inf[i],inf[i+1],A,B);
	}
	//~ cout << " >> " << INF << '\n';
	return INF;
}

int main(){
	//~ freopen("in","r",stdin);
	cout << setprecision(2) << fixed;
	while(cin>>n,n){
		for(int i = 0 ; i < n ; ++i){
			cin>>sup[i].x>>sup[i].y;
			inf[i].x = sup[i].x;
			inf[i].y = sup[i].y-1;
		}
		lf ans = -INF;
		
		for(int j = 0 ; j < n ; ++j){
		for(int i = j+1 ; i < n ; ++i){
			ans = max(ans,solve(sup[j],sup[i]));
			ans = max(ans,solve(sup[j],inf[i]));
			ans = max(ans,solve(inf[j],inf[i]));
			ans = max(ans,solve(inf[j],sup[i]));
		}}
		if(ans == INF) cout <<"Through all the pipe.\n";
		else cout << ans << '\n';
	}
	return 0;
}
