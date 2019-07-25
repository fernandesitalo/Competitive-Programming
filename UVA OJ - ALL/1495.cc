#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;


int main(){
	
	freopen("in","r",stdin);

	int j,g,m,s,N,marcar[100001];
	
	while(scanf(" %d %d",&j,&g) != EOF){
		N = 0;
		
		int ans = 0;

		
		while(j--){
			scanf("%d %d",&m,&s);			
			if(s >= m) marcar[N++] = (s - m);
			else ans += 3;
		}
		
		sort(marcar,marcar+N);
		
		for(int i = 0 ; i < N ; ++i){	
			
			if(g > 0 && marcar[i] == 0){
				ans+= 3;
				g--;
			}
			else if(g >= marcar[i]+1){
				ans += 3;
				g -= marcar[i]+1;	
			}		
			else if(g >= marcar[i]){
				 ans++;
				 g -= marcar[i];
			}
		}	
		
		printf("%d\n",ans);	
	}	
	return 0;
}
