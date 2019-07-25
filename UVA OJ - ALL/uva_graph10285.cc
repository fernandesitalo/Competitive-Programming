#include <bits/stdc++.h>
using namespace std;

int const maxn = 200;
int L[] = {1,-1,0,0};
int C[] = {0,0,-1,1};
int mat[maxn][maxn];
int LL,CC;

#define check(l_,c_) (l_>=0&&c_>=0&&LL>l_&&CC>c_)



int dfs(int l, int c){
	int ret = 1;
	for(int i = 0 ;i < 4 ; ++i){
		int li = L[i]+ l;
		int ci = C[i]+ c;
		if(check(li,ci) && mat[li][ci] < mat[l][c]){
			ret = max(ret,dfs(li,ci)+1);
		}
	}
	return ret;
}

bool degreeZero(int l,int c){
	for(int i = 0 ; i < 4 ; ++i){
		int li = L[i]+ l;
		int ci = C[i]+ c;
		if(check(li,ci) && mat[li][ci] > mat[l][c]){
			return false;
		}
	}
	return true;
}


int main(){
	//~ freopen("in","r",stdin);
	
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s>>LL>>CC;
		for(int i = 0 ; i < LL ; ++i){
			for(int j = 0 ; j < CC ; ++j){
				cin>>mat[i][j];
			}
		}
		//~ cout << dfs(0,0) << endl;
		//~ return 0;
		int ans = 0;
		for(int i = 0 ; i < LL ; ++i){
			for(int j = 0 ; j < CC ; ++j){
				if(degreeZero(i,j)){
					int x = dfs(i,j);
					ans = max(ans,x);
				}
			}
		}
		cout << s <<": " << ans << '\n';
	}
	
	return 0;
}
