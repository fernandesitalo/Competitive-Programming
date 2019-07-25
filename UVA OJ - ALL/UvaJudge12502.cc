#include <bits/stdc++.h>
using namespace std;

int main(){
	
	float x,y,rs;

	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%f%f%f",&x,&y,&rs);
		y = (x+y)/3.0;		
		printf("%.0f\n",fabs(x - y)*(rs/y));
	}
	return 0;
}
