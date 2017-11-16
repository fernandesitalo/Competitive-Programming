#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// INT_MAX -> 2147483647 .: 10 digitos... logo tentaremos ate 10 digitos!, mais que isso estouramos um INT_MAX

string s;

ll Converte(int i, int f){ // converte a string em numero, somente....
	ll n = 0;
	for(; i <= f ; ++i)	n = n*10 + s[i]-'0'; 
	return (n > INT_MAX ? -1 : n);
}

ll pd[300];


ll F(int p){ // no caso, foi separado a string em 2 partes... de INICIO ate 'p' e de 'p' ate FIM... 
							// apartir dessa separacao,vamos fazer mais separacoes do range maior... 
							// sabemos que um range e pequeno, e nao vamos separa-lo dnv, somente a parte maior, que sera dividida em diferentes formas 
	if(0 > p) return 0;

	if(pd[p] != -1) return pd[p];
	
	for(int i = 1 ; i <= 10 ; ++i ) // cada NO da recursividade terá 10 filhos, cada um desses outros 10.... recursão densa
			pd[p] = max(pd[p], F(p-i) + Converte(p-i+1, p ) );
	return pd[p];
}


int main(){
	//~ freopen("in","r",stdin);
	int t;
	for(cin>>t;t--;){
		cin>>s;
		memset(pd,-1,sizeof pd);		
		cout << F(s.size()-1) << '\n';
	}
	return 0;
}
