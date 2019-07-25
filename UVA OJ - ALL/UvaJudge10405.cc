#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int tam1, tam2;

int pd[1001][1001];


int lcs(int p1, int p2){ // maior subsequencia entre duas strings
	
	if(p1 == tam1 || p2 == tam2) return 0; // base
	
	if (pd[p1][p2] != -1) return pd[p1][p2];
	
	pd[p1][p2] = max(lcs(p1+1,p2),lcs(p1,p2+1));
	
	if(str1[p1] == str2[p2])
		pd[p1][p2] = max(pd[p1][p2], 1 + lcs(p1+1,p2+1));
	
	return pd[p1][p2];
}

int main(){
	
	while(getline(cin,str1)){
		
		memset(pd,-1,sizeof(pd));
		getline(cin,str2);			
		tam1 = str1.size();
		tam2 = str2.size();
		printf("%d\n",lcs(0,0));
	}
	return 0;
}
