#include <bits/stdc++.h>
using namespace std;

int N,M,T;
typedef pair<int,int> ii;  // <qtd, tempo restante>
ii pd[10009];

int resto;

ii inc(ii a){ return ii(a.first + 1,a.second); }

ii maxx(ii a, ii b){
	if(a.second == b.second){
		if(a.first > b.first) return a;
		return b;
	}
	return (a.second>b.second?b:a);
}


ii F(int Tdisp){
	
	if(Tdisp == 0) return ii(0,0); // da pra comer esse tanto ai e sobrou nada de tempo...
	
	//printf("%d %d\n",pd[Tdisp].first,pd[Tdisp].second);
	
	ii &ref = pd[Tdisp];
	if(ref.first != -1) return ref;
	
	if(Tdisp >= M && Tdisp >= N) // da pra comer um dos dois
		return ref = inc(maxx(F(Tdisp - M),F(Tdisp - N)));
	
	if(Tdisp >= M) // da pra comer
		return ref = inc(F(Tdisp - M));
	
	if(Tdisp >= N) // da pra comer 
		return ref = inc(F(Tdisp - N));
		
	return ii(0,Tdisp); // deu pra comer nenhum sanduiche e sobrou esse tempo ai que e diferente de zero
}




int main(){
		
	//~ freopen("in","r",stdin);
		
	while(scanf(" %d %d %d",&M,&N,&T) == 3){
		memset(pd,-1,sizeof pd);
		ii ans = F(T);
		printf("%d",ans.first);
		if(ans.second) printf(" %d\n",ans.second);
		else puts("");
			
	}	

	return 0;
}
