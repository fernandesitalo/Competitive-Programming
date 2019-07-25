#include <bits/stdc++.h>
using namespace std;


int main(){
	
	//freopen("in","r",stdin);

	char fr[10000];

	while(scanf(" %s[^\n]",fr)!= EOF){
		for(int i = 0 ; fr[i] ; ++i){
			printf("%c",fr[i]-7);
		}puts("");
	}	
	return 0;
}