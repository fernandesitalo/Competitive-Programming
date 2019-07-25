#include <bits/stdc++.h>
#define M 5000
using namespace std;

int pd[M][M];

string arr1[M];
string arr2[M];


int lcs(int t1,int t2){
	if(t1 == -1 || t2 == -1) return 0;
	int &ref = pd[t1][t2];
	if(ref != -1) return ref;
	if(arr1[t1] == arr2[t2]) return ref = 1+lcs(t1-1,t2-1);
	return ref = max(lcs(t1-1,t2),lcs(t1,t2-1));
}

vector<string> ans;

void rec(int t1,int t2){
	
	if(t1 == -1 || t2 == -1) return;
	
	if(arr1[t1] == arr2[t2]){
		rec(t1-1,t2-1);
		ans.push_back(arr2[t2]);
	}
	else if(pd[t1-1][t2] > pd[t1][t2-1]) rec(t1-1,t2);
	else rec(t1,t2-1);		
	
}


int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	string str;
	
	while(cin>>str){
		arr1[0] = str;
		int t1 = 1;
		while(cin>>arr1[t1], arr1[t1] != "#")	t1++;
	
		int t2 = 0;
		while(cin>>arr2[t2], arr2[t2] != "#")	t2++;
		
		
		
		ans.clear();
		memset(pd,-1,sizeof pd);
		lcs(t1-1,t2-1);
		rec(t1-1,t2-1);
		
		cout << ans[0];
		for(int i = 1; i < (int)ans.size() ; ++i){
			cout << " " << ans[i];
		}
		puts("");
	}

	return 0;
}
