#include <bits/stdc++.h>
using namespace std;

string s;
int pd[1004][1004];

// recursivo pq e mais facil de codar
int EditDist(int l,int r){ // MODIFICACAO NO EDITDIST... usando somente com uma string ao invez de 2...
	
	if(l >= r) return 0; // caso base
	
	int &ref = pd[l][r];
	if(ref != -1) return ref;
	
	if(s[l] == s[r]) return ref = EditDist(l+1,r-1);
	
	return ref = 1  + min(EditDist(l+1,r),min(EditDist(l,r-1),EditDist(l+1,r-1)));
}


int main(){
	//~ freopen("in","r",stdin);
	int t,ct = 1;
	for(cin>>t;t--;){
		cin>>s;
		memset(pd,-1,sizeof pd);
		printf("Case %d: %d\n",ct++,EditDist(0,s.size()-1));		
	}
	return 0;
}



// e nois que voa
