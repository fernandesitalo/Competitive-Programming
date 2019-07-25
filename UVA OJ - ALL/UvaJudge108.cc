#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,subRect;
	
	freopen("in","r",stdin);
	
	while(scanf("%d",&n)!= EOF){
		int mat[n][n];
		
		for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j){
			scanf("%d",&mat[i][j]);
			if(i > 0) mat[i][j] += mat[i-1][j];
			if(j > 0) mat[i][j] += mat[i][j-1];
			if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
		
		}
		
		int maxSubRect = -127*100*100;
		
		for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j)
			for(int k = i ; k < n ; ++k) for(int l = j ; l < n ; ++l){
				subRect = mat[k][l];
				if(i > 0) 			subRect -= mat[i-1][l];
				if(j > 0)			subRect -= mat[k][j-1];
				if(i > 0 && j > 0)	subRect += mat[i-1][j-1];
				
				
				
				maxSubRect = max(maxSubRect,subRect);
			}
		printf("%d\n",maxSubRect);	
	}
	return 0;
}
