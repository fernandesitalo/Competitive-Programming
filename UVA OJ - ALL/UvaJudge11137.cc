#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C[30];

ll pd[10001][22];

ll Conta(int disp,int idx){
	
	if(disp == 0) return 1ll;
	if(disp < 0 || idx == 21) return 0ll;
	
	if(pd[disp][idx] != -1) return pd[disp][idx];
	
	return pd[disp][idx] = Conta(disp-C[idx],idx) + Conta(disp,idx+1); 
}


int main(){
	
	int n;
	
	for(int i = 1 ; i < 22 ; ++i){
		C[i-1] = i*i*i;
	}
	
	memset(pd,-1,sizeof pd);
	while(cin>>n){
		cout << Conta(n,0) << endl; 
	}
	
	
	return 0;
}
