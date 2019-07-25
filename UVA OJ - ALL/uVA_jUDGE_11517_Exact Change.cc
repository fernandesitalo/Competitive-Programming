// UVA JUDGE 11517  - Exact Change
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<long long,int> ii;


ii sum(ii a, ii b){
	return ii(a.first + b.first,a.second + b.second);	
}

int C[101];
ii pd[10001][101]; //<valor_ate_o_momento,qtddemoedas_ate_o_momento>
int N;

ii F(int disp, int idx){
	if(disp <= 0) return ii(0,0);/////////////////////////////////////
	
	if(idx >= N) return ii(INF,INF);/////////////////////////////////
		
	if(pd[disp][idx] != ii(-1,-1)) return pd[disp][idx];
	
	ii a = F(disp,idx+1);
	ii b = sum(F(disp - C[idx],idx+1),ii(C[idx],1));
	
	return pd[disp][idx] = min(a,b);	
}

int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t,v,i;
	for(scanf(" %d",&t);t--;){		
		scanf(" %d %d",&v,&N);
		for(i = 0 ; i < N ; ++i) scanf(" %d",C+i);
		memset(pd,-1,sizeof pd);
		ii ans = F(v,0);
		printf("%lld %d\n",ans.first,ans.second);
	}		
	return 0;
}
