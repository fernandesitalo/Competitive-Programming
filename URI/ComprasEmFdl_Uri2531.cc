#include <bits/stdc++.h>
#define INF 9999999
#define MAXN 100005
using namespace std;
typedef pair<int,int> ii;

ii st[MAXN*4];
int vet[MAXN];

ii FUSAO(ii a, ii b){
	return ii(max(a.first,b.first),min(a.second,b.second));
}


void build(int root, int l, int r){
	if(l == r){st[root] = ii(vet[l],vet[l]); return;}
	
	int middle = (l+r)/2;
	int noL = root<<1 ;
	int noR = (root<<1) + 1;
	
	build(noL,l,middle);
	build(noR,middle+1,r);
	
	st[root] = FUSAO(st[noR],st[noL]);	
}


ii query(int root, int l, int r, int posl, int posr){
	
	if(posl > r || l > posr) return ii(-INF,+INF); // se estiver totalmente fora do intervalo
	
	//	if(l >= i && r <= j) return st[root];
	
	if(l >= posl && posr >= r) return st[root]; // tem pelo menos um pedaço aqui
	
	int middle = (l+r)/2;
	int noL = root<<1;  
	int noR = (root<<1) + 1;
	
	return FUSAO(query(noL,l,middle,posl,posr),query(noR,middle+1,r,posl,posr));
}


void update(int root, int l, int r, int pos, int value){

	if(pos > r || l > pos) return;
	
	if(l == r && pos == l) {st[root] = ii(value,value); return;}
	
	int middle = (l+r)/2;
	int noL = root<<1 ; 
	int noR = (root<<1) + 1;
	
	update(noL,l,middle,pos,value);
	update(noR,middle+1,r,pos,value);
	
	st[root] = FUSAO(st[noR],st[noL]);
}


int main(){
	
	int N,Q;
	int a,o,b;
	while(scanf(" %d",&N) == 1){
		for(int i = 0 ; i < N ; ++i)scanf(" %d",vet+i);
		build(1,0,N-1);
		scanf(" %d",&Q);
		while(Q--){
			scanf(" %d %d %d",&o,&a,&b);
			if(o == 1){
				update(1,0,N-1,a-1,b);
			}else{
				ii ans = query(1,0,N-1,a-1,b-1);
				printf("%d\n",(int)fabs(ans.first - ans.second));
			}
		}
	}
		
	return 0;
}
