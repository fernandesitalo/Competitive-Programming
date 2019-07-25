#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
	
	
	freopen("in","r",stdin);
	
	string c,d;
	int i;
	
	while(getline(cin,d)){
		getchar();
		getline(cin,c);
		
		map<int,int>m1,m2;
		
		for(i = 0 ; d[i] ; ++i){
			if(isalpha(d[i])){
				m1[tolower(d[i])]++;			
			}
		}
		
		
		for(i = 0 ; c[i] ; ++i){
			if(isalpha(c[i])){
				m2[tolower(c[i])]++;			
			}
		}
		
		
		priority_queue<ii, vector<ii> , greater<ii> > p1,p2;
		
		for(auto it : m1) p1.push(ii(it.second,it.first));
		for(auto it : m2) p2.push(ii(it.second,it.first));
		
		
		map<int,int> id;
		
		while(!p1.empty()){
			
			int a = p1.top().second;
			int b = p2.top().second;
			
			//~ printf("%c %c\n",a,b);
			
			id[b] = a;
			p1.pop(),p2.pop();
		}
		
		for(i = 0 ; c[i] ; ++i){
			if(isalpha(c[i])){
				
				//~ printf("> %c - %c\n",c[i],id[tolower(c[i])]);
				
				printf("%c",id[tolower(c[i])] - (c[i] <= 'Z'?32:0));
			}else printf("%c",c[i]);
		}puts("");
		
	}
	return 0;
}
