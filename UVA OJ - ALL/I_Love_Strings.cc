#include <bits/stdc++.h>
using namespace std;

string T,P;

int b[1000099];
int n,m;

void KMPprocess(){
	int i = 0,j = -1; b[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		++i,++j;
		b[i] = j;
	}
}

bool KMPsearch(){
	int i = 0,j = 0;
	
	while(i < n){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		++i,++j;
		if(j == m) return 1;
	}
	return 0;
}




int main(){
	
	freopen("in","r",stdin);
	
	int t,q;
	
	for(cin>>t;t--;){
		scanf(" ");
		getline(cin,T); n = T.size();
		
		for(cin>>q;q--;){
			scanf(" ");	getline(cin,P);
			
			m = P.size();KMPprocess();
		
			if(KMPsearch()) puts("y");
			else puts("n");
		}
	}
	return 0;
}
