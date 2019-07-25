#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e4;
int way[maxn][maxn];
int L,C;

int main(){
	//~ freopen("in","r",stdin);
	//~ cin.sync_with_stdio(false);
	//~ cin.tie(NULL);
	int temp = 0;
	int t;
	cin>>t;
	bool isfirst = true;
	while(t--){
		temp--;
		if(!isfirst) cout << '\n';
		isfirst = false;
		
		cin>>L>>C;
		getchar();
		
		for(int i = 0,li,number ; i < L; ++i){
			string s;
			getline(cin,s);
			//~ cout << " ::" <<s << '|' << '\n';
			stringstream ss(s);
			ss>>li;
			while(ss>>number){
				way[li][number] = temp;
				//~ cout << li<<","<<number<<endl;
			}
		}
		
		way[1][1] = 1;
		for(int i = 1 ; i <= L ; ++i){
			for(int j = (i==1?2:1) ; j <= C ; ++j){
				if(way[i][j] == temp) continue;
				way[i][j] = (way[i-1][j]==temp?0:way[i-1][j]) + (way[i][j-1]==temp?0:way[i][j-1]);
			}
		}
		cout << way[L][C] << '\n';
	}
	
	
	return 0;
}
