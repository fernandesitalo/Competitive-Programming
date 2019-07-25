#include <bits/stdc++.h>
#define MAXN 21
using namespace std;

int arr1[MAXN],arr2[MAXN];
int n;

int pd[MAXN][MAXN];

int LCS(int i, int j){
	
	if(i == n || j == n) return 0;
	
	if(pd[i][j] != -1 ) return pd[i][j];
	
	if(arr1[i] == arr2[j]) pd[i][j] = LCS(i+1,j+1) + 1;
	else pd[i][j] = max(LCS(i,j+1),LCS(i+1,j));
	
	return pd[i][j];
}




int main(){
	
	int aux;
	scanf(" %d",&n);
	for(int i = 0 ; i < n ; ++i){
		scanf(" %d",&aux);
		arr1[aux-1] = i;
	}
	
	while(1){		
		for(int i = 0 ; i < n ; ++i){
			if(scanf(" %d",&aux)== EOF) return 0;		
			arr2[aux-1] = i;
		}
		memset(pd,-1,sizeof pd);		
		printf("%d\n",LCS(0,0));		
	}
	return 0;
}
