/** 	UVA JUDGE 793....  Network Connections
 * 
 * 		SOLUCAO :  aplicação direta de union find
 * 		
 * 		sem misterio
 * 
 * 		lvl.: easy 
 */
#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int pai[MAXN];

int findSet(int i)
{ return (pai[i] == i? i :pai[i] = findSet(pai[i]));}

bool IsSameSet(int i, int j)
{ return(findSet(i) == findSet(j));}

void UnionSet(int i, int j){
	pai[findSet(i)] = findSet(j);		
}

int main(){
	
	//freopen("in","r",stdin);	
	int op;
	int i,j,t,q;
	bool p = false;
	
	for(scanf(" %d",&t);t--;){
		int sucesso(0);
		int insucesso(0);
		
		if(p)puts(""); p = true;		
		scanf(" %d",&q);		
		for(i = 1 ; i <= q ; ++i) pai[i] = i;
		
		getchar();
		while( (op = getchar ()) && isalpha (op)){
			scanf(" %d %d",&i,&j); getchar();			
			if(op == 'c') 	UnionSet(i,j);
			else			IsSameSet(i,j) ? sucesso++ : insucesso++;
		}
		printf("%d,%d\n",sucesso,insucesso);
	}	
	return 0;
}
