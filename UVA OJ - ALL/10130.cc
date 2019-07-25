#include <bits/stdc++.h>
using namespace std;

int pd[1111][55];
int valor[1111];
int peso[1111];
int N;

/* RECURSIVO
int mochila(int disp, int index){
	
	if(disp == 0 || index == N) return 0;
	
	if(pd[disp][index] != -1) return pd[disp][index];
	
	if(disp >= peso[index])
		pd[disp][index] = max(mochila(disp,index+1),valor[index] + mochila(disp-peso[index],index+1));
	else pd[disp][index] = mochila(disp,index+1);
	
	return pd[disp][index];
}*/


// ITERATIVO
void mochila(int disp, int n){
	
	for(int i = 0 ; i <= n ; ++i)
		for(int p = 0 ; p <= disp ; ++p){
			if(i==0||p==0) pd[i][p] = 0;
			else if(p >= peso[i-1])
				pd[i][p] = max( valor[i-1] +  pd[i-1][p - peso[i-1]],
								pd[i-1][p]);
			else pd[i][p] = pd[i-1][p];	
		}
}

int main(){
	
	//freopen("in","r",stdin);
	
	int t,g;
	for(scanf(" %d",&t);t--;){
		scanf(" %d",&N);		
		for(int i = 0 ; i < N ; ++i) scanf(" %d %d",&valor[i],&peso[i]);			
		scanf(" %d",&g);
		int pessoa[g];		
		int V = 0;		
		for(int i = 0 ; i < g ; ++i) scanf(" %d",&pessoa[i]), V = max(V,pessoa[i]);	
		mochila(V,N);
		int ans = 0;		
		for(int i = 0 ; i < g ; ++i){
			ans += pd[ N ][ pessoa[i] ];
		}		
		printf("%d\n",ans);
	}	
	return 0;
}
