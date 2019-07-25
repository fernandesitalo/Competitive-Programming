#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int moeda[] = {1,5,10,25,50};

ll pd[5][30001];

ll F(int index, int disp){
	
	if(disp == 0) return 1;
	if(index == 5 || disp < 0) return 0;
	
	if(pd[index][disp] != -1) return pd[index][disp];
	
	pd[index][disp] = 0;
	
	pd[index][disp] = F(index,disp - moeda[index]) + F(index+1,disp);

	return pd[index][disp];
}

int main(){
	
	int n;
	
	memset(pd,-1,sizeof pd);
	
	while(scanf(" %d",&n)!= EOF){
		
		ll ans = F(0,n);
		
		if(ans > 1) printf("There are %lld ways to produce %d cents change.\n",ans,n);
		else printf("There is only 1 way to produce %d cents change.\n",n);
	}
	
}
