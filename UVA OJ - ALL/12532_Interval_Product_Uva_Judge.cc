// uso da segment tree... aplicação direta, pegando somente o sinal
// do numero lido, para evitar overflow e uma possivel resposta errada


#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int vet[MAXN];
int st[MAXN*4];
int n;

void build(int root, int l, int r){
	if(l == r){st[root] = vet[l]; return;} // no folha
	
	int noL = 2*root;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	build(noL,l,meio);
	build(noR,meio+1,r);
	
	st[root] = st[noR] * st[noL];
}
//---l--------r--
// ---i------j---

int query(int root, int l , int r, int i, int j){
	
	if(j < l || i > r) return 1; // fora do intervalo de consulta .: retorna um neutro
	
	if(i <= l && j >= r) return st[root]; // verificar se o intervalo entre ]l,r[ pertence a ]i,j[

	int noL = 2*root;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	return query(noL,l,meio,i,j) * query(noR,meio+1,r,i,j);

}

void update(int root, int l, int r, int pos, int value){
	
	if(!(pos >=l && pos <= r))return;
	
	if(l == r && l == pos){st[root] = value;return;}
	
	int noL = 2*root;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	update(noL,l,meio,pos,value);
	update(noR,meio+1,r,pos,value);
	
	st[root] = st[noR] * st[noL];
}



int main(){
	//freopen("in","r",stdin);
	int k;
	while(scanf(" %d %d",&n,&k)!= EOF){
		
		for(int i = 0 ; i < n ; ++i){
			scanf("%d",&vet[i]);
			
			vet[i] = (vet[i] == 0 ? 0 : (vet[i] > 0 ? 1:-1));
					
		}
		build(1,0,n-1);
		char o;
		int a,b;
		
		while(k--){
			scanf(" %c %d %d",&o,&a,&b);
			
			if(o == 'C'){
				
				b = (b == 0? 0 : (b > 0 ? 1: -1));
								
				update(1,0,n-1,a-1,b);
				
			}else{ // o == 'P'
								
				a = query(1,0,n-1,a-1,b-1);				
				printf(a == 0? "0" : a > 0 ? "+":"-");							
			}			
		}
		puts("");	
	}	
	return 0;
}
