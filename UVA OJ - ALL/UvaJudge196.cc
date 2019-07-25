#include <bits/stdc++.h>
using namespace std;
#define MARCA -88


int M[20000][20000];

typedef pair<int,int> ii;
map<ii,vector<ii> > m;

int F(int l, int c){
	
	if(M[l][c] != MARCA) return M[l][c];
	
	int size = m[ii(l,c)].size();
	M[l][c] = 0;
	for(int i = 0 ; i < size ; ++i){
		M[l][c] += F(M[ii(l,c)][i]);
	}
	
	return M[l][c];
}


int number(string str){
	int ret = 0;
	i = 0;
	while(str[i] != '\0'){
		ret *=  10;
		ret += str[i] - '0';
		i++;
	}
	return ret;
}


vector<ii> exp(string sttr){
	
	int i;
	vector<ii> ret;
	
	while(str[i] != '\0'){
		
		ii a;
		int x = 0;
		while(str[i] >= 'A' && str[i] <= 'Z'){
			a.first += str[i] - 'A' + 26*(x++);
		}
		
	}

}

int main(){
	int t;
	string str;
	
	for(cin>>t;t--;){
		scanf(" %d %d",&C,&L);
		for(int i = 0 ; i < L ; ++i){
			for(int j = 0 ; j < C ; ++j){
				cin >> str;
			}
		}	
	}

	return 0;
}
