#include<bits/stdc++.h>
using namespace std;



int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	char f[1000];
	string ini;
	cin >> ini;
	int i,e;

	while(scanf(" %[^\n]",f), strcmp(ini.data(),f) != 0){
		
		int t = strlen(f) - 2;
		
		int bin = 0;
		
		for(i = t,e = 0 ; i > 0 ; --i,++e){
			if(f[i] == '.') {e--;continue;}
			if(f[i] == 'o'){
				bin += 1 << e;
			}
		}
		printf("%c",bin);
	}
	
	return 0;
}
