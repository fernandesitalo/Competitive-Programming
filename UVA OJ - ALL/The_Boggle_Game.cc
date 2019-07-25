#include <bits/stdc++.h>
using namespace std;

char m1[5][5];
char m2[5][5];

bool v[5][5];

bool isVowel(char c){
	c = tolower(c);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

bool verificWord(string w){	
	if(w.size() != 4) return false;
	int cont = 0;
	for(int i = 0 ; i < 4 ; ++i) if(isVowel(w[i])) cont++;
	return (cont == 2);
}


bool vld(int l, int c){ return (l > -1 && c > -1 && l < 4 && c < 4);}

int L[] = {-1,0,1,0,-1,-1,1,1};
int C[] = {0,1,0,-1,-1,1,-1,1};

map<string,bool> m;

void bk(int l, int c,string str){
	
	v[l][c] = true;
	
	if(str.size() == 4){
		m[str] = true;
		
		v[l][c] = false;
		return;
	}

	for(int i = 0 ; i < 8 ; ++i){
		if(vld(l+L[i],c+C[i]) && v[l+L[i]][c+C[i]] == false){
			string aux = str;	aux.push_back(m1[l+L[i]][c+C[i]]);
			bk(l+L[i],c+C[i],aux);
		}
	}
	
	v[l][c] = false;
}

set<string> ans;


void bk2(int l, int c,string str){
	
	v[l][c] = true;
	
	if(str.size() >= 4){
		if(m.find(str) != m.end() && verificWord(str)){
			ans.insert(str);
		}
		v[l][c] = false;
		return;
	}
	
	for(int i = 0 ; i < 8 ; ++i){
		if(vld(l+L[i],c+C[i]) && v[l+L[i]][c+C[i]] == false){
			string aux = str;		aux.push_back(m2[l+L[i]][c+C[i]]);
			bk2(l+L[i],c+C[i],aux);
		}
	}
	
	v[l][c] = false;
}


int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	char l;
	int i,k;
	bool p = false;
	
	while(cin>>m1[0][0],m1[0][0]!='#'){
		for(i = 1 ; i < 4; ++i) cin>>m1[0][i];
		for(i = 0 ; i < 4; ++i) cin>>m2[0][i];
		
		for(k = 1 ; k < 4 ; ++k){
				for(i = 0 ; i < 4; ++i) cin>>m1[k][i];		
				for(i = 0 ; i < 4; ++i) cin>>m2[k][i];
		}
		ans.clear();
		m.clear();
	
		
		memset(v,0,sizeof v);
		for(i = 0 ; i < 4 ; ++i)
			for(k = 0 ; k < 4 ; ++k){ 	memset(v,0,sizeof v);string a;a.push_back(m1[i][k]);bk(i,k,a);}
		
		
		memset(v,0,sizeof v);
		
		for(i = 0 ; i < 4 ; ++i)
			for( k = 0 ; k < 4 ; ++k) { 	memset(v,0,sizeof v);string a;a.push_back(m2[i][k]);bk2(i,k,a);}
			
		if(p)puts("");p = 1;
		
		
		if(ans.size() == 0) puts("There are no common words for this pair of boggle boards.");
		else{			
			for(auto it : ans)cout << it << '\n';	
		}
	}
	return 0;
}
