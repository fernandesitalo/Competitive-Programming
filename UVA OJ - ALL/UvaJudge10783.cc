#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int q,a,b,ans;
	scanf("%d",&q);
	
	for(int ct = 1 ; ct <= q ; ++ct){	
		scanf("%d%d",&a,&b);
		ans = 0;
		if(!(a%2)) a++;
		
		while(b >= a){	
			ans += a;
			a+= 2;
		}
		printf("Case %d: %d\n",ct,ans);
	}

	return 0;
}
