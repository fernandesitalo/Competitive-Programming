#include <bits/stdc++.h>
#define MAXN 100001
#define INF 999999
using namespace std;
typedef pair<int,int> ii;

int vet[MAXN];
int st[MAXN*4];


int ini[MAXN];
int fim[MAXN];


void build(int root, int l, int r){
	if(l == r){ st[root] = vet[l]; return;}
	
	int noL = root<<1;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	build(noL,l,meio);
	build(noR,meio+1,r);
	st[root] = max(st[noL],st[noR]);
}

// ---l-i----r-j----


int query(int root, int l, int r, int i, int j){
	if(i > r || j < l) return -INF;
	
	if(l >= i && r <= j) return st[root];
	
	int noL = root<<1;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	return max(query(noL,l,meio,i,j),query(noR,meio+1,r,i,j));	
}



int main(){
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
		
	int n,i,q;
	while( scanf(" %d",&n), n){		
		scanf(" %d",&q);

		scanf(" %d",&vet[0]);
		int fq = 1;
		
		for(i = 1 ; i < n ; ++i){
			scanf(" %d",&vet[i]);
			
			if(vet[i] != vet[i-1]){				
				for(int k = i-1 ; k >= i - fq  ; --k){
					ini[k] = i - fq;
					fim[k] = i-1;
					vet[k] = fq;
				}
				fq = 0;				
			}
			fq++;		
		}

		for(int k = i-1 ; k >= i - fq  ; --k){
			ini[k] = i - fq;
			fim[k] = i-1;
			vet[k] = fq;
		}			
		
		build(1,0,n-1);	
		
		int l,r;
		
		while(q--){
			scanf("%d%d",&l,&r);--l;--r;
			
			if(ini[l] == ini[r]) printf("%d\n",r-l+1);
			else{
				
				int part1 = fim[l] - l + 1;				
				int part2 = r - ini[r] + 1;								
				int part3 = query(1,0,n-1,fim[l]+1,ini[r]-1);				
				printf("%d\n",max(part1,max(part2,part3)));			
			}
			
		}	
	}	
	return 0;	
}
