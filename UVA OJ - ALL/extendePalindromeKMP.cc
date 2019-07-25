#include <bits/stdc++.h>
using namespace std;


int b[100001];
void KMPprocess(string P){
	int m = P.size();
	int i = 0  , j = -1; b[0] = -1;
	
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		++i,++j;		
		b[i] = j;		
	}
	
	
	
}


int main(){

	KMPprocess("abcddcba");
	
	
	return 0;
}
