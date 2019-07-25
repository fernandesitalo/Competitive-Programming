#include <bits/stdc++.h>
#define in(nom) freopen(nom,"r",stdin)
#define out(num) freopen(num,"w",stdout)
#define deb puts("deb")
#define asc puts("*")
using namespace std;


int main(){

	in("in");
	out("out");
	char fr[1000];
	
	while(gets(fr)){
	
		if(fr[0] >= '0' && fr[0] <= '9'){
			int ax = 0;
			for(int i = strlen(fr)-1; i > -1 ; i--){
				ax = ax * 10 + fr[i]-'0';
				if(('A' <= ax && 'Z' >= ax) || ('a' <= ax && 'z' >= ax) || ax == ' ' || ax == '!'  || ax == ',' || ax == '.' || ax == 	':' || ax == ';' || ax == '?')			
					printf("%c",ax),ax = 0;
			}
		}		
		else 	
			for(int i = strlen(fr)-1 ; i > -1 ; --i){
				 int n = fr[i];
				 
				while(n){
					printf("%d",n%10);
					n /= 10;
				}
			}
		puts("");
		
	}
	return 0;
}
