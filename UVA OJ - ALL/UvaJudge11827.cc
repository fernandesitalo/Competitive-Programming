#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){return (b==0? a : gcd(b,a%b));}


int main(){
	//~ freopen("in","r",stdin);
	
	int t;
	int vet[101];
	
	cin>>t;
    string linha;
    stringstream ss;
	getline(cin,linha);
	
	for(;t--;){
		int i = 0;
		int ans = 1;
		
		getline(cin,linha);
		ss.clear();	
		ss << linha;
		
		while(ss >> vet[i])i++;
			
		for(int j = 0 ; j < i ; ++j){
			for(int k = j+1 ; k < i ; ++k){
				ans = max(ans,gcd(vet[j],vet[k]));
			}
		}	
			
		printf("%d\n",ans);	
	}
	return 0;
}
