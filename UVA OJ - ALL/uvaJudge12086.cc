#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;

typedef long long ll;

int vet[MAXN];
ll st[MAXN*4];

void build(int root, int l, int r){
	if(l == r){ st[root] = vet[l]; return; }
	
	int noL = 2*root;
	int noR = noL + 1;
	int meio = (l+r)/2;
	
	build(noL,l,meio);
	build(noR,meio+1,r);
	
	st[root] = st[noR] + st[noL];	
}


void update(int root, int l, int r, int pos, int value){
	
	if(!(pos >= l && pos <= r)) return;
	
	if(l == r && pos == l) { st[root] = value; return;}
	
	int noL = 2*root;
	int noR = noL+1;
	int meio = (l+r)/2;
	
	update(noL,l,meio,pos,value);
	update(noR,meio+1,r,pos,value);
	
	st[root] = st[noR] + st[noL];	
}

int query(int root, int l , int r, int i, int j){
	if(r < i || j < l) return 0;
	
	if(l >= i && r <= j) return st[root]; // o intervalo entre l e r deve estar entre i e j....
	
	int noL = 2*root;
	int noR = noL+1;
	int meio = (l+r)/2;	
	
	return query(noL,l,meio,i,j) + query(noR,meio+1,r,i,j);
}



int main(){
	
	freopen("an","r",stdin);
	int n,ct = 1;
	string str;
	bool p = false;
	
	while(scanf(" %d",&n),n){
		
		for(int i = 0; i < n ; ++i){
			scanf("%d",&vet[i]);
		}
		build(1,0,n-1);
		
		if(p)puts("");  p = true;
		
		printf("Case %d:\n",ct++);
		
		int a,b;
		while(cin>>str,str != "END"){
			scanf(" %d %d",&a,&b);
			
			if(str == "M"){				
				//printf("=>  %d    %d\n",a-1,b-1);
				printf("%d\n",query(1,0,n-1,a-1,b-1));
			}
			else{
				update(1,0,n-1,a-1,b);
			} 
		}
	}
	return 0;
}
