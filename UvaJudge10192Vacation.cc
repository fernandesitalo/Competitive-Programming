// APLICACAO DIRETA-----> RIDICULO
#include <bits/stdc++.h>
using namespace std;

string s1,s2;

int pd[1090][1090]; // exagero

int LCS(int t1, int t2){ // lcs padrao recursivo...
	if(t1 == -1 || t2 == -1) return 0;
	int &ref = pd[t1][t2];	
	if(ref != -1) return ref;
	if(s1[t1] == s2[t2]) return ref = 1 + LCS(t1-1,t2-1);
	return ref = max(LCS(t1-1,t2),LCS(t1,t2-1));
}

int main(){
		//~ freopen("in","r",stdin);
	int i,j,ct=1;
	while(getline(cin,s1),s1[0] != '#'){
		getline(cin,s2);
		for(i = 0 ; i < (int) s1.size() ; ++i) // inicializa pd
		for(j = 0 ; j < (int) s2.size() ; ++j)
		pd[i][j] = -1;
		printf("Case #%d: you can visit at most %d cities.\n",ct++,LCS(s1.size()-1,s2.size()-1));
	}
	return 0;
}
