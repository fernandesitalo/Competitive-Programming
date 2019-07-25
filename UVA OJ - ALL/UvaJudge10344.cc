#include <bits/stdc++.h>
using namespace std;

int n[6];
bitset<10> v;


void F(int o,int res){

	if(o == 5 && res == 23) throw 2;
	if(o >= 5) return;
	
	for(int k = 0 ; k < 5 ; ++k){
		
		if(v[k] == 1){
			v[k] = 0;
			F(o+1,res + n[k]);
			F(o+1,res - n[k]);
			F(o+1,res*n[k]);
			v[k] = 1;
		}
	}
}


int main(){
	
	while(scanf(" %d %d %d %d %d",n+0,n+1,n+2,n+3,n+4),n[0]|n[1]|n[2]|n[3]|n[4]){
		
		bool p = true;
		try{
			v.set();
			for(int i = 0 ; i < 5 ; ++i) {v[i] = 0;F(1,n[i]);v[i] = 1;}
		}
		catch(int s){
			puts("Possible");
			p = 0;
		}
		if(p) puts("Impossible");		
	}
	return 0;
}
