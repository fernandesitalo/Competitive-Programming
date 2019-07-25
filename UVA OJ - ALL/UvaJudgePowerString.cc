#include <bits/stdc++.h>
using namespace std;


string text;	// size n
string pattern; // size m

int b[10001000];

int n,m;

void kmpProcess(){
	
	int i = 0,j = -1;
	b[0] = -1;
	
	while(i < m){
		while( j >= 0 && pattern[i] != pattern[j]) j = b[j];
		++i,++j;
		b[i] = j;
	}
}


int KMP_Search(){
	int i = 1 , j = 0, freq = 0;

	while(i < n){
		while(j >= 0 && text[i] != pattern[j]) j = b[j];
		++i,++j;
		if(j == m) freq++,j = b[j];
	}
	return freq;
}



int main(){
		
		
	freopen("in","r",stdin);
	freopen("out","w",stdout);	
		
	int x;

	
	while(getline(cin, pattern),pattern[0] != '.'){
		text = pattern + pattern;
		m =  pattern.size();	
		n = text.size();	
		kmpProcess();
		
		cerr << n << endl;
		
		x = KMP_Search();
		
		printf("%d\n",x);
	}
	return 0;
}
