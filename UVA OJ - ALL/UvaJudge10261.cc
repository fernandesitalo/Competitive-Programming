#include <bits/stdc++.h>
using namespace std;


int C[1000];
int N;
int L;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
map<iii,int> pd;

int F(int idx, int port, int starboard){
	
	if(idx == N || (port == 0 && starboard == 0)) return 0;
	
	iii pos = iii(ii(port,starboard),idx);// mandinga
	
	if(pd.find(pos) != pd.end() ) 	return pd[pos]; // pd
	
	if(port >= C[idx] && starboard >= C[idx])// se couber nos dois lados da balsa
	{ 
		if(port == starboard)		return pd[pos] = F(idx+1,port-C[idx],starboard)+1; // se os dois lados da balsa forem iguais
		return pd[pos] = 1+max(F(idx+1,port-C[idx],starboard),F(idx+1,port,starboard - C[idx])); // se os dois lados forem diferentes
	}	
	
	if(port >= C[idx]) 				return pd[pos]= F(idx+1,port-C[idx],starboard)+1; // so cabe em um lado
	if(starboard >= C[idx]) 		return pd[pos] = F(idx+1,port,starboard-C[idx])+1; // so cabe em um lado
	
	return 0;
}

vector<string> ans;

void rec(int idx, int port, int starboard){
	
	if(idx == N || (port <= 0 && starboard <= 0)) return;
	
	if(port >= C[idx] && starboard >= C[idx]){
		
		if(F(idx+1,port-C[idx],starboard)+1 == pd[iii(ii(port,starboard),idx)]  || port == starboard){
			puts("port");
			rec(idx+1,port-C[idx],starboard);
			return;
		}
		puts("starboard");
		rec(idx+1,port,starboard-C[idx]);
		return;
	}
	
	if(port >= C[idx]) {
		puts("port");
		rec(idx+1,port-C[idx],starboard);
		return;
	}
	
	if(starboard >= C[idx]){
		puts("starboard");
		rec(idx+1,port,starboard-C[idx]);
	}
}



int main(){
	
	freopen("in","r",stdin);
	
	int t,tam;
	for(cin>>t;t--;){
		scanf(" %d",&tam);
		tam *= 100;
		for(N = 0 ;;N++){
			 scanf(" %d",C+N);
			 if(C[N] == 0) break;
		}
		pd.clear();
		ans.clear();		
		printf("%d\n",F(0,tam,tam));
		rec(0,tam,tam);
		if(t) puts("");
	}
	
	return 0;
}
