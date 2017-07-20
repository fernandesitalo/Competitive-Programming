// Fenwick tree 2D _ solução inteligente
#include <bits/stdc++.h>
#define M 1001
using namespace std;

int ft[M][M];
int L;
int C;

void update(int l, int c, int value){
	for(int i = l; i <= L ; i += (i&-i))
		for(int j = c ; j <= C ; j += (j&-j))
			ft[i][j] += value; 
}

int query(int l, int c){
	int sum = 0;
	for(int i = l; i > 0 ; i -= (i&-i))
		for(int j = c ; j > 0 ; j -= (j&-j))
			sum += ft[i][j];
	return sum;		 
}


int main(){
  freopen("in","r",stdin);
	int preco,q;
	char o;
	int l,c,ll,cc;
	while(scanf(" %d %d %d",&L,&C,&preco),L||C||preco){
				
		for(int i = 1; i <= L ; ++i)
		for(int j = 1; j <= C ; ++j)
		ft[i][j] = 0;
		
		scanf(" %d",&q);
		
		while(q--){
			scanf(" %c",&o);
			if(o == 'A'){
				scanf(" %d %d %d",&cc,&l,&c);
				update(l+1,c+1,cc);
			}else{
				scanf(" %d %d %d %d",&l,&c,&ll,&cc);
				++l,++ll,++c,++cc;
				
					if (l>ll) swap(l,ll);
					if (c>cc) swap(c,cc);
				
				printf("%d\n",(query(ll,cc) - query(l-1,cc) - query(ll,c-1) + query(l-1,c-1))*preco);
			}
		}puts("");
		
	}
  return 0;
}
