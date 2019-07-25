#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int st[MAXN*4];
int vet[MAXN];


void build(int root, int l, int r){
	if(l == r){st[root] = vet[l]; return;}
	
	int middle = (l+r)/2;
	int noL = root<<1 ;
	int noR = (root<<1) + 1;
	
	build(noL,l,middle);
	build(noR,middle+1,r);
	
	st[root] = st[noR] + st[noL];	
}


int query(int root, int l, int r, int posl, int posr){
	
	if(posl > r || l > posr) return 0; // se estiver totalmente fora do intervalo
	
	//	if(l >= i && r <= j) return st[root];
	
	if(l >= posl && posr >= r) return st[root]; // tem pelo menos um pedaço aqui
	
	int middle = (l+r)/2;
	int noL = root<<1;  
	int noR = (root<<1) + 1;
	
	return query(noL,l,middle,posl,posr)+query(noR,middle+1,r,posl,posr);
}


void update(int root, int l, int r, int pos, int value){

	if(pos > r || l > pos) return;
	
	if(l == r && pos == l) {st[root] = value; return;}
	
	int middle = (l+r)/2;
	int noL = root<<1 ; 
	int noR = (root<<1) + 1;
	
	update(noL,l,middle,pos,value);
	update(noR,middle+1,r,pos,value);
	
	st[root] = st[noL] + st[noR];
}


int main(){
	
	int n = 8;
	
	for(int i = 0 ; i < n ; ++i) vet[i] = i;
	
	build(1,0,n-1);
	
	int a,b;
	while(true){
		cin >> a >> b;
		
		printf("%d\n",query(1,0,n-1,a,b));
		
		cin >> a >> b;
		
		update(1,0,n-1,a,b);
		
		
	}
	
	

	return 0;
}
