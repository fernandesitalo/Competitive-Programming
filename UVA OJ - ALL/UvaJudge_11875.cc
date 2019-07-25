#include <bits/stdc++.h>
using namespace std;

int main(){
	int q,n;
	
	scanf("%d",&q);
	for(int ct = 1 ;ct <= q ; ct++){
		scanf("%d",&n);
		int vet[n];
		for(int i = 0 ; i < n ; ++i)
			scanf("%d",&vet[i]);
		sort(&vet[0],&vet[n]);
		
		printf("Case %d: %d\n",ct,vet[n/2]);	
	}
	
	
	

	return 0;
}
