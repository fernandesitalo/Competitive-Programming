#include<bits/stdc++.h>
using namespace std;

int main(){
	int q,aux;
	int ct = 1;	
	while(scanf(" %d",&q),q){
		int ans = 0;
		while(q--){
			scanf(" %d",&aux);
			aux? ans++:ans--;
		}
		printf("Case %d: %d\n",ct++,ans);
	}
	return 0;
}
