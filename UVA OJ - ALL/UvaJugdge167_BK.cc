#include <bits/stdc++.h>
using namespace std;

int F[8];

bool vld(int l, int c){ //  coluna representa o numero de rainhas que ja foram colocadas
	for(int k = 0 ; k < c ; ++k)
		if(l == F[k] || abs(l-F[k]) == abs( k - c)) return false;
	return true;
}

int sol[100][8];
int cont;

void BK(int rainha){
	
	if(rainha == 8){
		for(int i = 0 ; i < 8 ; ++i) sol[cont][i] = F[i];
		cont++;	return;
	}
	
	for(int l = 0 ; l < 8 ; ++l){ // i varia as linhas 
		if(vld(l,rainha)){
			F[rainha] = l; BK(rainha+1);
		}
	}
}


int main(){
	
	//~ freopen("in","r",stdin);	
	
	cont = 0;	
	BK(0);
		
	int t,i,j,m[8][8];
	for(cin>>t;t--;){
		
		for(i = 0 ; i < 8 ; ++i)
			for(j = 0; j < 8 ; ++j) 
				scanf(" %d",&m[i][j]);
		
		int ans = 0,temp;
		for(i = 0 ; i < 92 ; ++i){
			for(temp = 0,j = 0 ; j < 8 ; ++j) temp += m[sol[i][j]][j];
			ans = max(ans,temp);
		}
		
		printf("%5d\n",ans);
	}
	return 0;
}
