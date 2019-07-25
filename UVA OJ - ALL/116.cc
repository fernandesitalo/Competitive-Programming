#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

int L;
int C;

int pd[11][MAXN];
int mat[11][MAXN];

inline int miin(int a,int b, int c)
{ return min(a,min(b,c));}


int F(int l, int c){
	
	if(c == C) return 0;
	
	int & ref = pd[l][c];
	
	if(ref != -1) return ref;
	
	return ref = miin(F(  l      , c+1 ) + mat[l][c],
					  F( (l+1)%L , c+1) + mat[l][c],
					  F( (l-1 == -1? L-1: l-1) , c+1) + mat[l][c]);
}

vector<int> resp;

void rec(int l, int c){
	
	if(c == C) return;
	
	
	int ll[] = {(l-1 == -1? L-1: l-1) ,l,(l+1)%L};
	sort(ll,ll+3);
	
	
	if(pd[l][c] ==  (F( ll[0] , c+1) + mat[l][c]) ){
		//cout << "A" << endl;
		resp.push_back(l);
		rec(ll[0],c+1);
	}	
	else if(pd[l][c] == (F(ll[1],c+1) + mat[l][c])){
		//cout << "B" << endl;
		resp.push_back(l);
		rec(ll[1],c+1);
	}
	else if(pd[l][c] == (F( ll[2]  , c+1 ) + mat[l][c])){
		//cout << "B" << endl;
		resp.push_back(l);
		rec(ll[2],c+1);
	}

}



int main(){
	
	//freopen("in","r",stdin);
	
	while(scanf(" %d %d",&L,&C)!= EOF){
		for(int i = 0 ; i < L ; ++i)
		for(int j = 0 ; j < C ; ++j)
		scanf(" %d",&mat[i][j]);
		
		memset(pd,-1,sizeof pd);
		
		int ans = 1e9;
		int linha = 0,aux;
		
		for(int i = 0 ; i < L ; ++i){
			aux = F(i,0);
			if(ans > aux){
				ans = aux;
				linha = i;
			}
		}
		
		resp.clear();
		rec(linha,0);		
		
		printf("%d",resp[0] + 1);
		for(int i = 1; i < (int) resp.size() ; ++i) printf(" %d",resp[i] + 1);
		puts("");		
		printf("%d\n",ans);
	}

}
