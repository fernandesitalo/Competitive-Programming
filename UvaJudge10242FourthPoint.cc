	#include <bits/stdc++.h>
	using namespace std;

	typedef pair<double,double> point;
	#define x first
	#define y second

	struct vec{ double X,Y;
		vec(double X, double Y) : X(X) , Y(Y){}
		vec(){}
	};

	//				inicio		 fim
	vec toVec(point a, point b){
		return vec(b.x - a.x , b.y - a.y);
	}

	point translate(point p,vec v){
		return point(p.x + v.X , p.y + v.Y);
	}

	vec sum(vec a, vec b){
		return vec(a.X +b.X,a.Y+b.Y);
	}



	int main(){
		
		//~ freopen("in","r",stdin);
		
		point a,oa,ob,b,ans; // poonto a, origem de a, origem de b, ponto de b
		vec vx,vy,vs;
		
		while(scanf(" %lf %lf %lf %lf %lf %lf %lf %lf",&a.x,&a.y,&oa.x,&oa.y,&ob.x,&ob.y,&b.x,&b.y) == 8){
			if(a == ob)	swap(a,oa);
			else if(a == b)	swap(a,oa),swap(b,ob);
			else if(oa == b)	swap(b,ob);
			
			vs = sum(toVec(ob,b),toVec(oa,a));
			ans = translate(oa,vs);
			printf("%.3lf %.3lf\n",ans.x,ans.y);
		}
		return 0;
	}
