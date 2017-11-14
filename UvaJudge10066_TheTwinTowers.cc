// aplicacao direta -> ridiculo
#include <bits/stdc++.h>
using namespace std;

int v1[105],v2[105];

int pd[109][109]; 

int LCS(int t1, int t2){
	if(t1 == -1 || t2 == -1) return 0;
	int &ref = pd[t1][t2];	
	if(ref != -1) return ref;
	if(v1[t1] == v2[t2]) return ref = 1 + LCS(t1-1,t2-1);
	return ref = max(LCS(t1-1,t2),LCS(t1,t2-1));
}

int main(){
	//~ freopen("in","r",stdin);
	int i,ct = 1,n,m;
	while(scanf(" %d %d",&n,&m),n|m){
		for(i = 0 ; i < n ; ++i) scanf(" %d",v1+i);
		for(i = 0 ; i < m ; ++i) scanf(" %d",v2+i);
		memset(pd,-1,sizeof pd);
		printf("Twin Towers #%d\n",ct++);
		printf("Number of Tiles : %d\n\n",LCS(n-1,m-1));
	}
	return 0;
}
