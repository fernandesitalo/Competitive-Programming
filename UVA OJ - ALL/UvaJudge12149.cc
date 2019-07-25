#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	while(scanf("%d",&n),n){
		
		int ans = 0;
		while(n){
			ans += n*n;
			n--;		
		}
		printf("%d\n",ans);		
	}
	return 0;
}
