#include <bits/stdc++.h>
using namespace std;

int main(){
	int q,a1,n,tam;
	
	scanf("%d",&q);
	
	for(int ct = 1 ; ct <= q ; ++ct){
		scanf("%d %d %d",&tam,&a1,&n);
		printf("Case %d: %d\n",ct,( a1 + (n-1)  )%tam + 1);
	}
	return 0;
}
