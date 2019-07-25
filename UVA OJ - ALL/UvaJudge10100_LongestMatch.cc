#include <bits/stdc++.h>
using namespace std;

vector<string> v1,v2;

int pd[1000][1000]; // exagero

int LCS(int t1, int t2){
	if(t1 == -1 || t2 == -1) return 0;
	int &ref = pd[t1][t2];	
	if(ref != -1) return ref;
	if(v1[t1] == v2[t2]) return ref = 1 + LCS(t1-1,t2-1);
	return ref = max(LCS(t1-1,t2),LCS(t1,t2-1));
}


int main(){
	
	//~ freopen("in","r",stdin);
	
	int i,j,ct = 1;
	string f,p;	
	while(getline(cin,f)){
		
		v1.clear(); v2.clear();
		
		i = 0,p = "";
		do{
			if(isalnum(f[i]) || isalpha(f[i])) p.push_back(f[i]);
			else if(p.size() > 0) v1.push_back(p), p = "";
		}while(f[i++]);
		
		getline(cin,f);	
		i = 0,p = "";
		do{
			if(isalnum(f[i]) || isalpha(f[i])) p.push_back(f[i]);
			else if(p.size() > 0) v2.push_back(p), p = "";
		}while(f[i++]);
		
		
		for(i = 0 ; i <= (int)v1.size() ; ++i)
		for(j = 0 ; j <= (int)v2.size() ; ++j)
		pd[i][j] = -1;
		
		printf("%2.d. ",ct++);
		if(v1.size() == 0 || v2.size() == 0) puts("Blank!");
		else printf("Length of longest match: %d\n",LCS(v1.size()-1,v2.size()-1));	
	}
	
	return 0;	
}	
