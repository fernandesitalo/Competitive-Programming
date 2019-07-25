#include <bits/stdc++.h>

using namespace std;

int LADO;
int N;
int C[1000];
int pd[10001][1001];

int mochila(int disp, int idx){
	
	if(idx == N || disp == 0) return 0;
	
	int &ref = pd[disp][idx]; 
	
	if(ref != -1) return ref;
	
	if(disp >= C[idx]){
		return ref = max(mochila(disp - C[idx],idx+1) + 1,mochila(disp,idx+1)); // pegar ou nao pegar
	
	}
	
	return ref = mochila(disp,idx+1);
}


void reconstrucao(int disp, int idx){
	if(idx == N || disp == 0) return;
	
	if(disp >= C[idx]){		
		if(mochila(disp,idx+1) == pd[disp][idx]){ // pegou o item
			reconstrucao(disp,idx+1);	
		}
		else {
			reconstrucao(disp - C[idx],idx+1);
			C[idx] = LADO;
		}
	}
	else reconstrucao(disp,idx+1);	
}	

int main(){
	
	freopen("in","r",stdin);
	int t;
	for(cin>>t;t--;){
		
		int tam;
		
		scanf(" %d",&tam);
		
		tam *= 100;
		
		for(N = 0 ;;N++){
			 scanf(" %d",C+N);
			 
			 if(C[N] == 0) 
			 break;
		}cout << " >>> " << N << endl;
		
		memset(pd,-1,sizeof pd);
					
		int qtd = mochila(tam,0);
		LADO = 999999990;			
		reconstrucao(tam,0);


		LADO = 999999980;	
		memset(pd,-1,sizeof pd);
		qtd += mochila(tam,0);		
		reconstrucao(tam,0);
		
		 
		printf("%d\n",qtd);
		for(int i = 0 ; i < N ; ++i){
			if(C[i] == 999999990) printf("starboard %d\n",i+1);
			else if(C[i] == 999999980) printf("port %d\n",i+1);
		}
		
		if(t) puts("");
	}
	
	
	
	return 0;
}
