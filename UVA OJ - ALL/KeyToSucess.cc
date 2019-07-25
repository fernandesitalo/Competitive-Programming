#include <bits/stdc++.h>
using namespace std;

int main(){
	
		//~ freopen("in","r",stdin);
	
	int t,i,a,b;
	string s1,s2;
	bool p = 0;
	for(cin>>t;t--;){
		cin>>s1>>s2;
		map<int,int> m1,m2;
		
		for(i = 0 ; s1[i] ; ++i)m1[ s1[i] ]++;
		for(i = 0 ; s2[i] ; ++i)m2[ s2[i] ]++;
		
		map<int,int> ind;
		
		priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > v1,v2;
		
		for(auto it : m1)v1.push(make_pair(it.second,it.first));
		for(auto it : m2)v2.push(make_pair(it.second,it.first));
			
		while(!v1.empty()){
			a = v1.top().second;
			b = v2.top().second;
			ind[b] = a;
			v1.pop(),v2.pop();
		}	
		
		if(p) puts(""); p = 1;
		for(i = 0 ; s2[i] ; ++i)printf("%c",ind[s2[i]]);
		puts("");
	}
	return 0;
}
