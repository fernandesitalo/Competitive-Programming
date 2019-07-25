#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int  t,n;
	for(cin>>t;t--;){
		scanf(" %d",&n);
		
		int vet[n+1];
		
		scanf(" %d",vet+0);
		
		ll ans = 0ll; 	// para cada elemento do vetor apartir do segundo,	
						// verificar qntos atras dele são menores ou iguais a ele
						// somar cada numero a resposta total final
						// fim
		
		for(int i = 1 ; i < n ; ++i){
			scanf(" %d",vet+i);
			for(int j = i-1 ; j > -1 ; --j){
				if(vet[j]<= vet[i]) ans++;
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}
