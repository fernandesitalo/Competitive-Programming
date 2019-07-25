#include <bits/stdc++.h>
using namespace std;
#define file freopen("in","r",stdin);


int GCD(int a, int b){ return b == 0? a : GCD(b,a%b);}

int main(){
	
	
//	file;
	
	int aux,temp;
	
	while(scanf(" %d",&temp), temp){
		
		int ans = 0;
		
		while(scanf(" %d",&aux),aux){
			ans = GCD(ans,fabs(aux-temp));
		}
		
		printf("%d\n",ans);
	
	}

	return 0;
}
