#include <bits/stdc++.h>
#define in(nom) freopen(nom,"r",stdin)
#define out(num) freopen(num,"w",stdout)
#define deb puts("deb")
#define asc puts("*")
using namespace std;


int main(){	

	
	in("in");
	
	string i,f;
	
	cin >> i;
	
	while(getline(cin,f),f != i){
		
		int bin = 0;
		
		int t = f.size()-2;
		
		for(int i = t ; i > 0 ; --i){
			if(f[i] == '.') continue;
			bin += f[i] == ' '? 0:1<< (t-i);
		}
		
		cout << bin << endl;
		
		//~ printf("%c",bin);
	
	}
	
	return 0;
}
