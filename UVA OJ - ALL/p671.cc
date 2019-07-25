#include <bits/stdc++.h>
using namespace std;



//~ int pd[16][16];

//~ int ed(string str1,string str2, int n, int m){
	
	//~ if(n == 0) return m;
	//~ if(m == 0) return n;
	
	//~ int &ref = pd[n][m];
	
	//~ if(ref != -1) return ref;
	//~ if(str1[n-1] == str2[m-1]) return ref = ed(str1,str2,n-1,m-1);
	
	//~ return ref  = 1 +  min(ed(str1,str2,n-1,m),min(ed(str1,str2,n,m-1),ed(str1,str2,n-1,m-1)));
//~ }


bool f(string s1,string s2){
	
	int n = s1.size();
	int m = s2.size();
	
	
	if(n == m){
		int dif = 0;
		for(int i = 0 ; i < n && dif < 2; ++i) if(s1[i] != s2[i]) dif++;
		return (dif <= 1);
	}
	
	if(n == m+1){
		int j = 0;
		int dif = 0;
		for(int i = 0 ; s1[i] && dif < 2 ; ++i){
			if(s1[i] != s2[j]){
				dif++;
			}
			else j++;
		}
		return (dif <= 1);
	}
	
	if(n == m-1){
		int j = 0;
		int dif = 0;
		for(int i = 0 ; s2[i] && dif < 2 ; ++i){
			if(s2[i] != s1[j]){
				dif++;
			}
			else j++;
		}
		return (dif <= 1);
	}
	return false;
	
}





int main(){
	//~ freopen("in","r",stdin);	
		
	int t;
	string p;
	bool b = 0;
	for(cin>>t;t--;){
		if(b) puts(""); b = 1;
		vector<string> v;
		set<string> s;
		while(cin>>p, p[0] != '#') v.push_back(p),s.insert(p);
		
		while(cin>>p,p[0] != '#'){
			
			if(s.find(p) != s.end()) printf("%s is correct",p.data());
			else{
				printf("%s:",p.data());
				for(auto it : v)
				{
						if(f(p,it)) printf(" %s",it.data());
				}
			}
			puts("");
		}
	}	
		
	return 0;
}
