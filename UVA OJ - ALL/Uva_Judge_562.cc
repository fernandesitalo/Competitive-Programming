

#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

int moeda[MAXN];
int N;


int pd[MAXN * 500][MAXN];

int MB(int disp,int index){
	
	if(index == N) return 0;
	if(disp == 0) return 0;
	
	if(pd[disp][index] != -1) return pd[disp][index];	
	
	if(disp >= moeda[index])
		pd[disp][index] = max( moeda[index] + MB(disp - moeda[index],index+1) ,MB( disp , index+1));
	else pd[disp][index] = MB(disp , index+1);
		
	return pd[disp][index];
}



int main(){
	
	int t;
	for(scanf(" %d",&t);t--;){
		scanf(" %d",&N);
		int sum = 0;
		memset(pd,-1,sizeof pd);
		for(int i = 0 ; i < N ; ++i) scanf(" %d",&moeda[i]), sum += moeda[i];			
		printf("%d\n",sum - 2* MB(sum/2,0));	
	}
	return 0;
}
