#include <bits/stdc++.h>
using namespace std;


int main(){
	
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	
	char fr[100000];
	string vg = "AaEeIiOoUu";
	int i,j;
	
	while( gets(fr) ){
	
	string str;
	
	bool p = 0;
	
		for(i = 0 ; fr[i] ; ++i){
			
			if(fr[i] == ' ' ){
				
				if(p) printf(" ");p = 1;
				
				if(str.size() > 0){
					
					for(j = 0 ; j < 10 && vg[j] != str[0] ; ++j); 
					
					char ax = *str.rbegin();
					
					if(! isalnum(ax) ) str.erase(str.begin() + str.size()-1);
					
					
					if(j >= 10){ // eh consoante
						str += str[0];
						str.erase(str.begin());
					}
					
					str += "ay";
					
					if(! isalnum(ax) ) str += ax;
					
					cout << str;
					str.clear();				
				}	
			}else str.push_back(fr[i]);
		}	
		
		
		if(str.size() > 0){
			
			if(p)printf(" ");
					
			for(j = 0 ; j < 10 && vg[j] != str[0] ; ++j); 
			
			char ax = *str.rbegin();
			
			if(!isalnum(ax)){
				str.erase(str.begin() + str.size()-1);
			}
			
			if(j == 10){
				str+= str[0];
				str.erase(str.begin());
			}
			
			str += "ay";
			
			if(!isalnum(ax)){
				str += ax;
			}			
			cout << str << endl;	
		}
		
	}
	return 0;
}
