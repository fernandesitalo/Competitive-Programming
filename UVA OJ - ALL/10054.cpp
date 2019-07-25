#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int>	ii;
typedef vector<ii>	vii;
typedef vector<int>	vi;

int MatAdj[60][60];
vector<int> ans;

void dfs_r(int u){	
	ans.push_back(u);		
	for(int i = 1 ; i < 51 ; i++){
		if(MatAdj[u][i] > 0){
			MatAdj[i][u]--,	MatAdj[u][i]--;		
			dfs_r(i);			
		}	
	}	
}


int main(){
	int u,v,n,t;
	int ct = 1;
	scanf("%d",&t);
	int usado[60];
	while(t--){
		scanf("%d",&n);
		
		memset(usado,0,sizeof(usado));		
		memset(MatAdj,0,sizeof(MatAdj));
		ans.clear();
	
	
		for(int i = 1 ; i <= n ; i++){
			scanf("%d%d",&u,&v);
			MatAdj[u][v]++;
			MatAdj[v][u]++;			
			usado[u]++;
			usado[v]++;	
		}			
		
		printf("Case #%d\n",ct++);
		
		bool alface = false;
		
		for(int v = 1 ; v <= 60 ; v++){
			if(usado[v] & 1) alface = true;
				break;					
		}
		
		ans.clear();
		
		if(!alface){					
			dfs_r(u);
						
			if(((int)ans.size()-1) != n || ans[0] != *ans.rbegin())
				printf("some beads may be lost\n");
			else
				for(int r = 0 ; r < (int)(ans.size()-1) ; r++)
					printf("%d %d\n",ans[r],ans[r+1]);			
		}
		else printf("some beads may be lost\n");
		
		
		
		if(t) puts("");		
		
	}
	return 0;
}

