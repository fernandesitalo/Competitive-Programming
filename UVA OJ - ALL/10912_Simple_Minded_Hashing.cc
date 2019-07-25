//Neste problema você terá que encontrar o número de cordas de 
// comprimento L, que mapeia para um inteiro S


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pd[400][30][30];

int L,S;

/*	sum -> soma ate a determinada letra 
 * 	tam -> tamanho da sequencia formada ate o momento
 * 	idx -> a ultima letra colocada na sequencia 
 */

ll F(int sum, int tam,int idx){
	
	if(sum == S && tam == L) return 1;
	if(sum >= S || tam >= L) return 0;
	
	ll &ref = pd[sum][tam][idx];
	
	if(ref != -1) return ref;
	
	ref = 0;	
	
	for(int i = idx+1 ; i < 27 ; ++i){		// COM FORZINHO TIME : 0.260
		ref += F(sum + i,tam+1, i );		
	}
	
	return ref;	
}




ll F_2(int sum, int tam ,int idx){
	
	if(sum == S && tam == L) return 1;
	if(idx == 27 || sum >= S || tam >= L) return 0;
	
	ll &ref = pd[sum][tam][idx];
	
	if(ref != -1) return ref;
	
	return ref = F_2(sum,tam,idx+1) + F_2(sum + idx,tam+1,idx+1);   // SEM FORZINHO TIME : 0.170
}






int main(){
	
	
	int ct = 1;	
	while(scanf(" %d %d",&L,&S),L||S){
		memset(pd,-1,sizeof pd);	
		printf("Case %d: %lld\n",ct++,F(0,0,0));
	}
	return 0;
}

