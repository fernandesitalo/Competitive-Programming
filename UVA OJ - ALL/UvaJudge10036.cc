#include <bits/stdc++.h>
using namespace std;

int N,K;
int P[10001];


/*  DICA VALIOSA NESSA QUESTAO... TIRAR O MODO DA SOMA OU SUBTRACAO
 *  ASSIM OS ESTADOS VAO SE COMFLITAR NO RECALCULO E VAI HAVER PROGA
 *  ACAO DINAMICA DE VERDADE ALEM DE ECONOMIZAR MEMORIA
 * 	
 * 
 * 	O RANGE VAI DE -100 ATE + 100
 * 
 * PRA FAZER A DP EM UMA MATRIZ, PEGA O UMERO QUE DER E SOMA 100
 * PRA DR DIFERENÇA E SEMPRE FICAR POSITIVO
 * 
 */


int pd[203][10001];


bool F(int res, int idx){
	
	if(idx == N){
		if(res%K == 0) throw 10;
		return 0;
	}
	
	int & ref = pd[res+101][idx];
	if(ref != -1) return ref;

	return (ref = F((res - P[idx])%K,idx+1) || F((res + P[idx])%K,idx+1));
}


int main(){
	freopen("in","r",stdin);
	int t;
	for(cin>>t;t--;){
		scanf(" %d %d",&N,&K);
		for(int i = 0 ; i < N ; ++i) scanf(" %d",P+i);
		memset(pd,-1,sizeof pd);
		
		try{
			F(P[0]%K,1);
			puts("Not divisible");
		}
		catch(...){
			puts("Divisible");
		}
	}
	
	
	return 0;
}
