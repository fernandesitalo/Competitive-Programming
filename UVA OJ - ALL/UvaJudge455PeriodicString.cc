#include <bits/stdc++.h>
using namespace std;


string P,T; //P-> pattern,size = m   T->text,size = n
int n,m,b[1000000];


void KMPprocess(){
	int i = 0 , j = -1;
	b[0] = -1;
	
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		++i,++j;
		b[i] = j;
	}
}

int KMPsearch(){
	int i = 1,j = 0,f = 0; // f de frequencia
	while(i < n){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		++i,++j;
		if(j == m){ f++;j = b[j];}
	}
	return f;
}


int main(){
	
	freopen("in","r",stdin);
	
	int t;
	for(cin>>t,getchar();t--;){
		cin>>P;
		T = P+P;
		n = T.size();
		m = P.size();
		
		KMPprocess();
		cout << P.size()/KMPsearch() << '\n';
		if(t) puts("");
	}
	return 0;
}
