#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
#define x first
#define y second

#define EPS 1e-9

int raiz(int a, int b, int c){
	double delta = b*b - (4*a*c);
	
	//~ cout << " >> delta : "  << delta << endl;
	
	int x1 = ceil((-b+sqrt(delta))/(2.0*a));
	int x2 = ceil((-b-sqrt(delta))/(2.0*a));
	
	
	//~ cout << "t1 : " << x1 << endl;
	//~ cout << "t2 : " << x2 << endl;
	
	if(x1 > 0 && x2 > 0) return min(x1,x2);
	if(x1 > 0) return x1;
	return x2;
}



int main(){
	
	//~ freopen("in","r",stdin);
	
	int P,B,i,t,xx,yy,a,b,c,d,e,f,g,j;
	double time,dist,menort;
	
	while(scanf(" PLAYERS= %d",&P)!= EOF){
		point jog[P+1];
		double vel[P+1];
		for(i = 0 ; i < P ; ++i)scanf(" %lf %lf %lf",&jog[i].x,&jog[i].y,&vel[i]);
		
		scanf(" BALLS= %d",&B);
		for(i = 0  ; i < B ; ++i){
			scanf(" %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);
			
			t = raiz(a,b,c);
			xx = d*t + e;
			yy = f*t + g;


			if(0 > xx || 0 > yy){
				printf("Ball %d was foul at (%d,%d)\n",i+1,xx,yy);
				continue;
			}
			
			
			menort = 9999999;
			for(j = 0 ; j < P ; ++j){
				dist = hypot(jog[j].x - xx,jog[j].y - yy);
				time = dist/(double)vel[j];
				if(menort > time)	menort = time;				
			}
			
			
			
			if(menort > t) printf("Ball %d was safe at (%d,%d)\n",i+1,xx,yy);
			else 		   printf("Ball %d was caught at (%d,%d)\n",i+1,xx,yy);
		}
	}
	return 0;
}
