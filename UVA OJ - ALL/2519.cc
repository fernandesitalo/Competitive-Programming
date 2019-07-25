#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;

int ft[MAXN][MAXN];
int L;
int C;

void update(int l, int c, int value){
	for(int i = l ; i <= L ; i += (i&(-i)))
		for(int j = c ; j <= C ; j+= (j&(-j)))
			ft[i][j] += value;
}

int query(int l, int c){
	int sum = 0;
	for(int i = l ; i > 0 ; i -= (i&(-i)))
		for(int j = c ; j > 0 ; j -= (j&(-j)))
			sum += ft[i][j];
	return sum;			
}


int main(){
	//freopen("in","r",stdin);
	int aux,q,l,ll,c,cc;
	while(scanf(" %d %d",&L,&C)!= EOF){
		for(int i = 1 ; i <= L ; ++i)
			for(int j = 1 ; j <= C ; ++j)
				ft[i][j] = 0;	


		for(int i = 1 ; i <= L ; ++i)
			for(int j = 1 ; j <= C ; ++j){
				scanf("%d",&aux);
				if(aux)	update(i,j,aux);	
			}
		scanf("%d",&q);
		
		while(q--){
			scanf("%d%d%d%d%d",&aux,&l,&c,&ll,&cc);			
			if(aux)	printf("%d\n",query(ll,cc) - query(l-1,cc) - query(ll,c-1) + query(l-1,c-1));
			else update(l,c,-1),update(ll,cc,1);	
		}		
	}
	return 0;
}
