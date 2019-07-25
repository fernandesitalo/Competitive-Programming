#include <bits/stdc++.h>
using namespace std;

struct cubo{
	int id,vet[6];
	cubo(){}
};


int N;
cubo C[501];
int dp[501][101][501];//< cubo atual,cor do topo,altura do cubo>

int F(int att, int cor,int h){ 
	
	if(att == N) return h; // base
	
	int &ref = dp[att][cor][h];
	if(ref != -1) return ref;

	for(int i = 0 ; i < 6 ; ++i){ 
		if(cor == C[att].vet[i] || cor == 0){
		 	ref = max(ref,F(att+1,C[att].vet[i^1],h+1)); // operando ^1 se e par, pega o proximo numero, se é impar pega o numero anterior
		} 
	}
	
	return ref = max(ref,F(att+1,cor,h));
}

void rec_F(int att, int cor, int h){
	
	if(att == N) return;

	if(F(att+1,cor,h) == dp[att][cor][h]){
		rec_F(att+1,cor,h);
		return;
	}
	else{
		for(int i = 0 ; i < 6 ; ++i){ 
			if( (cor == 0 || cor == C[att].vet[i]) && F( att+1, C[att].vet[i^1] , h+1 ) == dp[att][cor][h] ){	
				
				rec_F(att+1,C[att].vet[i^1],h+1);
				printf("%d ",C[att].id);
				switch(i^1){//front, back, left, right, top and bottom face
					case 0:{puts("front");	break;}
					case 1:{puts("back");	break;}
					case 2:{puts("left");	break;}
					case 3:{puts("right");	break;}
					case 4:{puts("top");	break;}
					case 5:{puts("bottom"); break;}
				}
				
				return;			
			} 
		}
	}
}
	

int main(){
	
//	freopen("in","r",stdin);
	
	int ct = 1;
	bool p = false;
	
	while(scanf(" %d",&N) == 1 && N){
		
		if(p)puts("");
		p = true;
		
		printf("Case #%d\n",ct++);
		
		memset(dp,-1,sizeof dp);
		
		for(int i = N-1 ; i >= 0 ; --i){
			scanf(" %d %d %d %d %d %d",&C[i].vet[0],&C[i].vet[1],&C[i].vet[2],&C[i].vet[3],&C[i].vet[4],&C[i].vet[5]);
			C[i].id = N-i;
		}
		cout << F(0,0,0) << endl;
		rec_F(0,0,0);	
	}
	return 0;
}

