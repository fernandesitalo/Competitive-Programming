#include <bits/stdc++.h>
using namespace std;

string s;
int pd[1009][1009];

int EditDist(int l,int r){
	if(l >= r) return 0;
	int &ref = pd[l][r];
	if(ref != -1) return ref;
	if(s[l] == s[r]) return ref = EditDist(l+1,r-1);
	return ref = 1 + min( EditDist(l+1,r) ,EditDist(l,r-1));
}

string ans;
int d;
void rec(int l, int r){
	
	if(l >= r){
		return;
	}
	if(s[l] == s[r]){
		rec(l+1,r-1);
	}
	else{
		if(pd[l][r] == 1+EditDist(l+1,r)){
			rec(l+1,r);
			ans.insert(ans.begin() + r+d,s[l]); d++;
		}
		else{
				rec(l,r-1);
				ans.insert(ans.begin()+l,s[r]);d++;
		}
	}
}

int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);

	while(cin>>s){
		memset(pd,-1,sizeof pd);
		ans = s,d = 1;
		cout << EditDist(0,s.size()-1)<< " ";
		rec(0,s.size()-1);
		cout << ans << '\n';		
	}
	return 0;
}
