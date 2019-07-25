#include <bits/stdc++.h>
using namespace std;


int main(){	
	//~ freopen("in","r",stdin);
	string a,b;
	
	
	while(getline(cin,a))
	{
		getline(cin,b);	// SE EU NAO LIMPAR O BUFFER O GETLINE PEGA ENTER
						// IF I DO NOT CLEAR THE BUFFER THE GETLINE GET ENTER
		int f[30];
		memset(f,0,sizeof f);
		
		string ans;
		
		for(int i = 0 ; i < (int)a.size() ;++i){
			f[a[i]-'a']++;
		}
		
		
		for(int i = 0 ; i < (int)b.size() ;++i){
			if(f[b[i]-'a']) ans.push_back(b[i]),f[b[i]-'a']--;
		}
		
		sort(ans.begin(),ans.end());
		
		cout << ans <<endl;		
	}
	return 0;
}
