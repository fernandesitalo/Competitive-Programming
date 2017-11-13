#include <bits/stdc++.h>
#define M 22
using namespace std;

string s1,s2; // <size n, size m>

int pd[M][M],pos;

int ed(int n, int m){ // S1 -> S2
	
	if(n == 0) return m;
	if(m == 0) return n;
	
	int &ref = pd[n][m];
	
	if(ref != -1) return ref;
	
	if(s1[n-1] == s2[m-1]) return ref = ed(n-1,m-1);
	
	return ref = 1 + min(ed(n-1,m),min(ed(n,m-1),ed(n-1,m-1)));
}


	//      s1    s2
void rec(int n, int m){
	
	if(n == 0){
		pos = m+1;
		for(int i = 0 ; i < m ; ++i) printf("I%c%.2d",s2[i],i+1);
		return;
	}
	
	if(m == 0){
		pos = 1;
		for(int i = 0 ; i < n ; ++i) printf("D%c%.2d",s1[i],1);
		return;
	}
	
	if(s1[n-1] == s2[m-1]){
		rec(n-1,m-1);pos++;
	}else{
		
		if(ed(n-1,m)+1 == pd[n][m]){
			rec(n-1,m);
			printf("D%c%.2d",s1[n-1],pos);
		}
		else{ 
			if(ed(n,m-1)+1 == pd[n][m]){
				rec(n,m-1);
				printf("I%c%.2d",s2[m-1],pos++);
			}
			else{
				rec(n-1,m-1);
				printf("C%c%.2d",s2[m-1],pos++);
			}
		}
	}
}

int main(){
	
	//~ freopen("in","r",stdin);


	while(cin>>s1,s1[0] != '#'){ // s1 -> s2
		cin>>s2;
		pos = s2.size();
		memset(pd,-1,sizeof pd);
		ed(s1.size(),s2.size());
		rec(s1.size(),s2.size());
			
		puts("E");
	}
	return 0;
}
