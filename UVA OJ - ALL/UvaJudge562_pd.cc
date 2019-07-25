#include <bits/stdc++.h>
using namespace std;

int C[101];
int pd[500*51][101];	
int N;


int F(int disp, int idx){
	if(idx == N || disp == 0) return 0;
	
	int & ref  = pd[disp][idx];
	
	if(ref != -1) return ref;
	
	if(disp >= C[idx])
		return ref = max(F(disp-C[idx],idx+1) + C[idx],F(disp,idx+1));
	return ref = F(disp,idx+1);
}



int main(){
	
	//freopen("in","r",stdin);
	
	int t;
	for(cin>>t;t--;){
		scanf(" %d",&N);
		int sum = 0;
		for(int i = 0 ; i < N ; ++i) scanf(" %d",C+i),sum += C[i];
		
		int metade = sum/2;
		
		memset(pd,-1,sizeof pd);
		printf("%d\n",(int)fabs(sum - 2*F(metade,0)));
	}
	
	return 0;
}
