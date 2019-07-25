#include <bits/stdc++.h>
using namespace std;

typedef pair<long double, long double> point;
#define x first
#define y second


int main(){
	point a,b;
	long double xmedio,ymedio,dx,dy;
	while(scanf(" %Lf %Lf %Lf %Lf",&a.x,&a.y,&b.x,&b.y) == 4){
		xmedio = (a.x + b.x)/2.0;
		ymedio = (a.y + b.y)/2.0;
		dx = a.x - xmedio;			// dica .: sempre evite usar raiz ou qlqer outro caralho que perda precisao
		dy = a.y - ymedio;		
		printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",xmedio-dy,ymedio+dx,xmedio+dy,ymedio-dx); 	
	}
	return 0;
}
