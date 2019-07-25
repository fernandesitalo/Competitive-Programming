#include <bits/stdc++.h>
using namespace std;
int main(){
	//~ freopen("in","r",stdin);
	string fr;
	int ans = 0,a,b,c;
	char op,buff;
	while(cin>>fr){
		stringstream ss(fr);
		if(fr[fr.size()-1] == '?') continue;
		ss>>a>>op>>b>>buff>>c;	
		op == '+'?a+b == c ?ans++:ans:a-b == c?ans++:ans;
	}
	cout << ans << endl;
	return 0;
}
