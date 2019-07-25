// UVA JUDGE 10474 _ Where is the Marble?
// SOLUCAO: APLICACAO DIRETA DA BUSCA BINARIA

#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;

int vet[MAXN];

int BB(int l, int r, int value){
	if(l == r) return (vet[l]==value? l : -1 );
	int middle = (l+r)/2;		
	return (value > vet[middle]? BB(middle+1,r,value):BB(l,middle,value));
}


int main(){
	freopen("in","r",stdin);
	
	int n,m,numb,ans,ct = 1;
	while(scanf("%d%d",&n,&m),n||m){
		for(int i = 0 ; i < n ; ++i) scanf("%d",&vet[i]);
		sort(&vet[0],&vet[n]);
		printf("CASE# %d:\n",ct++);
		
		while(m--){
			scanf("%d",&numb);
			ans = BB(0,n-1,numb);
			
			if(ans != -1)printf("%d found at %d\n",numb,ans+1);
			else printf("%d not found\n",numb);
		}
	}
	

	return 0;
}

/*	/// BUSCA BINARIA ITERATIVA
	
	int l = 0,r = n-1,middle;
	
	while(l!=r){				
		middle = (l+r)/2;				
		if( numb > vet[middle] )l = middle+1 ;
		else r = middle;			
	}					
	
	if(vet[l] == numb)// achou
	else // não achou	
*/
