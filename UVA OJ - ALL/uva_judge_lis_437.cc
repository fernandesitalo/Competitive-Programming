#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e4+100;

int x[maxn],y[maxn],z[maxn];
typedef pair<int,int> ii;

int ft[maxn];

struct no{
	ii f;
	int s;
	no(){}
	no(ii f, int s) : f(f),s(s){}
	bool operator < (const no other) const{
		return (f.first < other.f.first || (f.first == other.f.first && f.second > other.f.second));
	}
};


int N;


long long query(int l){
	int r = 0;
	for( ;l ;l-= l&-l){
		r = max(ft[l],r);
	}
	return r;
}

void update(int l, int h){
	for( ;N > l ;l+= l&-l){
		ft[l] = max(h,ft[l]);
	}
}


/*
	LIS 2D
	
	TENHO PONTOS (X,Y), CADA UM COM SEU VALOR
	PRIMEIRO : ORDENADAR PONTOS POR UMA COORDENADA, X POR EXEMPLO
	SEGUNDO  : REALIZAR O LIS NA SEGUNDA COORDENADA,Y NO CASO, 1D MESMO

	OBS .: SE 2 COORDENADAS ESTAO NO MESMO X, ENTÃO A QUE COMEÇA DEPOIS, DEVE SER A PRIMEIRA A SER PROCESSADA
	* DESENHA PRA SABER O PQ....

*/

int main(){
	int n;
	int ct = 1;
	
	while(cin>>n, n){
		
		// FOR MAP
		set<int> s;
		map<int,int> mp;
		
		for(int i = 0 ; i < n ; ++i){
			cin>>x[i]>>y[i]>>z[i];
			s.insert(x[i]);
			s.insert(y[i]);
			s.insert(z[i]);
		}
		
		// MAPPING
		int cnt = 1;
		for(auto i : s){
			mp[i] = cnt++;
		}
		
		// BUILD A VECTOR
		vector<no> v;
		for(int i = 0 ; i < n ; ++i){
			int a = mp[x[i]],b = mp[y[i]] , c = mp[z[i]];
			v.push_back(no(ii(max(a,b),min(a,b)),z[i]));
			v.push_back(no(ii(max(a,c),min(a,c)),y[i]));
			v.push_back(no(ii(max(c,b),min(c,b)),x[i]));
		}
		
		// MAX VALUE
		N = *s.rbegin()+5;
		sort(v.begin(),v.end());


		long long ans = 0;
		memset(ft,0,sizeof ft);
		
		// LIS WITH FENWICK - PARTTERN
		// GET A MIN ELEMENTE OF FENWICK IN THIS POSITION 
		// UPDATE VALUE IN POSITION X WITH, QUERY(X)+VALUE[X,Y]
		for(auto i : v){
			int x = i.f.second,h = i.s;
			int q = query(x-1) + h;
			update(x,q);
			ans = max(ans,(long long)q);
		}
		
		cout << "Case "<<ct++<<": maximum height = "<< ans << '\n';
	}
}
