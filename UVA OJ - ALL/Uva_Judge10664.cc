#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int peso[MAXN];
int pd[MAXN * 5][MAXN];
int N;


int mochila(int disp, int index){
	if(index == N || disp == 0) return 0;
	
	if(pd[disp][index] != -1) return pd[disp][index];
	
	if(disp >= peso[index])
		pd[disp][index] = max(peso[index] + mochila(disp - peso[index],index+1) ,mochila(disp,index +1));
	else pd[disp][index] = mochila(disp,index +1);
	
	return pd[disp][index];
}







int main(){
	//freopen("in","r",stdin);
	int t;
	char buff;
	for(scanf(" %d",&t);t--;){
		N = 0;
		int sum = 0;		
		while(1){
			scanf(" %d",&peso[N]);
			sum += peso[N++];			
			buff = getchar();
			if(buff == '\n') break;
		}
		memset(pd,-1,sizeof pd);
		puts( (sum - sum/2) - mochila(sum/2,0) == 0?"YES":"NO");	
	}
	return 0;
}
