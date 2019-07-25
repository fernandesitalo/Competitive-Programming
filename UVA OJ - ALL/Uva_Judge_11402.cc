#include <bits/stdc++.h>
#define M 1024001
using namespace std;

int vet[M];
int st[4*M];
char lazy[4*M];

char OP;

void build(int root, int l, int r){
	if(l == r){st[root] = vet[l];return;}
	int noL = root<<1;
	int noR = noL+1;
	int middle = (l+r)/2;
	build(noL,l,middle);
	build(noR,middle+1,r);
	st[root] = st[noL] + st[noR];
}


void INVERTE(int root, int l, int r){ // entrou aqui temos que inverter...	
	if(lazy[root] == 'F'){
		lazy[root] = 'E';
		st[root] = 0;
		return;		
	}
	if(lazy[root] == 'E'){
		lazy[root] = 'F';
		st[root] = (r-l+1);
		return;
	}
	if(lazy[root] == 'I'){
		lazy[root] = ' ';
		st[root] = fabs(st[root] - (r-l+1));
		return;
	}
	if(lazy[root] == ' '){
		lazy[root] = 'I';
		st[root] = fabs(st[root] - (r-l+1));
		return;		
	}	
}



void propaga(int root,int l,int r,int noL,int noR,int middle){
	
	if(lazy[root] == 'F'){			
		lazy[noL] = lazy[noR] = 'F';
		st[noL] = (middle-l+1);
		st[noR] = (r - (middle+1) + 1);
		lazy[root] = ' ';
		return;
	}
	
	if(lazy[root] == 'E'){			
		lazy[root] = ' ';
		lazy[noL] = lazy[noR] = 'E';
		st[noL] = st[noR] = 0;
		return;			
	}
	
	INVERTE(noL,l,middle);
	INVERTE(noR,middle+1,r);
	lazy[root] = ' ';
	return;	
}


void update(int root, int l, int r, int posL, int posR){
	
	if(posL > r || posR < l ) return;
	
	if(l >= posL && r <= posR){
		
		if(OP == 'F'){	
			st[root] = (r - l + 1);
			lazy[root] = 'F'; //propagar isso aos filhos
			return;
		}
		if(OP == 'E'){
			st[root] = 0;			
			lazy[root] = 'E'; //propagar isso aos filhos//
			return;			
		}		
		
		INVERTE(root,l,r); 
		return;					
	}
	
	int noL = root<<1;
	int noR = noL+1;
	int middle = (l+r)/2;
		
	if(lazy[root] != ' ') propaga(root,l,r,noL,noR,middle);	
		
	update(noL,l,middle,posL,posR);
	update(noR,middle+1,r,posL,posR);
	
	st[root] = st[noR] + st[noL];
}

int query(int root, int l, int r, int i, int j){
	if(i > r || j < l) return 0;
	
	if(l >= i && r <= j) return st[root];
	
	int noL = root<<1;
	int noR = noL+1;
	int middle = (l+r)/2;
		
	if(lazy[root] != ' ') propaga(root,l,r,noL,noR,middle);	
		
	return query(noL,l,middle,i,j) + query(noR,middle+1,r,i,j);
}




int main(){
	//freopen("in","r",stdin);
	
	int c,m,n,q;
	scanf(" %d",&c);
	string str;
	
	for(int ct = 1 ; ct <= c ; ++ct){
		
		for(n = 0,scanf(" %d",&m);m--;){
			scanf(" %d",&q);
			cin >> str;
			while(q--)
				for(int i = 0 ; i < (int)str.size() ; ++i) 
					vet[n++] = str[i] - '0';		
		}
		
		for(int i = 0 ; i < 4*n ; ++i) lazy[i] = ' ';
		printf("Case %d:\n",ct);
		
		build(1,0,n-1);
	
		int a,b,count = 1;
		for(scanf(" %d",&q);q--;){
			scanf(" %c %d %d",&OP,&a,&b);			
			if(OP == 'S') printf("Q%d: %d\n",count++,query(1,0,n-1,a,b));
			else update(1,0,n-1,a,b);			
		}				
	}	
	return 0;
}
