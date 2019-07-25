#include <bits/stdc++.h>
using namespace std;

int main(){	
	int n,ans = 1,i,a,b;	
	scanf("%d",&n); --n;		
	scanf("%d",&b);	
	bool s,p = true;
	int r;
	i = 1;
	while(n--){
		scanf("%d",&a);		
		if( p ) r = a - b,s = false,p = false;
		else{			
			if(s){
				if(r != (a - b)) p = true,ans = max(i,ans), i = 0;				
			}
			else if(r != (b - a)) p = true,ans = max(i,ans), i = 0;				
			s = !s;		
		} 		
		b = a;i++;
	}	
	ans = max(i,ans);
	printf("%d\n",ans);	
	return 0;
}
