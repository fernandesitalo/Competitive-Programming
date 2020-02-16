#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;


int v[MAXN];		// 	global
int st[4*MAXN];		//	global	
int lazy[4*MAXN];		// 	global
 
 
void build(int root, int l, int r){
	if(l == r){st[root] = v[l]; return;}
	
	int noL = root<<1; int noR = noL + 1;
	int middle = (l+r)/2;
	
	build(noL,l,middle);
	build(noR,middle+1,r);
	
	st[root] = st[noL] + st[noR];	
}
 
void prop(int root, int noL, int noR, int l, int r, int mid) {
    lazy[noL] += lazy[root]; 	/// propaga a att para o lazy do filho da esq
    lazy[noR] += lazy[root];	/// propaga a att para o lazy do filho da dir
   
    st[noL] += lazy[root] * (mid-l+1);  /// aplica a att no filho da esq
    st[noR] += lazy[root] * (r-(mid+1)+1); /// aplica a arr no filho da dir
   
    lazy[root] = 0; /// zera o lazy do pai
}

// posL e posR é o intervalo de atualizacao
void update(int root, int l, int r, int posL, int posR, int valor) {
    if(posL > r || posR < l)  return;
    
    if(posL <= l && r <= posR) {
        st[root] += (r-l+1)*valor;
        lazy[root] += valor; // taca no lazy do pai, 
        return;				 // se eu descer ali dnv atualizo...
    }
    
	int noL = root<<1; int noR = noL + 1;
	int middle = (l+r)/2;
    
    if( lazy[root] ) prop(root, noL, noR, l, r, middle); // se tiver que propagar, propaga!
    
    update(noL, l, middle, posL, posR, valor);
    update(noR, middle+1, r, posL, posR, valor);
    
    st[root] = st[noL] + st[noR];
}
 
int query(int root, int l, int r, int i, int j) {
    if(i > r || l > j) return 0;
   
    if(l >= i && r <= j) return st[root];
    
	int noL = root << 1; int noR = noL + 1;
	int middle = (l+r)/2;
    
    if( lazy[root] ) prop(root, noL, noR, l, r, middle);
    
    return query(noL, l, middle, i, j) + query(noR, middle+1, r, i, j);
}



int main(){


	return 0;
}
