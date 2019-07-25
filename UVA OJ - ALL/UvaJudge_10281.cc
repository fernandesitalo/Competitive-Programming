#include <bits/stdc++.h>
using namespace std;


int main(){		
	//freopen("in","r",stdin);
	double HI = 0,HF = 0;
	double dist = 0;
	int h,m,s,v;	
	char buf;
	
	while(scanf("%d:%d:%d%c",&h,&m,&s,&buf) != EOF){
		HF = ((s/60.0) + m)/60.0 + h;
		dist += (HF - HI)*v;
		HI = HF;			
			
		if(buf == ' '){
			scanf("%d",&v);
		}
		else{		
			printf("%02d:%02d:%02d %.2lf km\n",h,m,s,dist);
		}	
	}	
	return 0;
}
