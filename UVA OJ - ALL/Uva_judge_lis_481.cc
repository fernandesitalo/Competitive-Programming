#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e5+100;

int V[maxn]; // vetor original

int Lis_id[maxn]; // index do elemento do que esta na iesima posicao do lis, o index corresponde a posição do elemento no vetor original
int P[maxn]; // posicao do iesimo elemento do vetor original no lis]




int main(){
	
	//~ freopen("in","r",stdin);
	
	int n = 0;
	while(cin>>V[n])n++;
	
	vector<int> lis;
	int lis_end = 0;
	for(int i = 0 ; i < n ; ++i){
		int pos = lower_bound(lis.begin(),lis.end(),V[i]) - lis.begin();
		
		if(pos == (int)lis.size()){
			lis.push_back(V[i]);
			lis_end = i;
		}else{
			if(pos == (int) lis.size()-1){
				lis_end = i;
			}			
			lis[pos] = V[i];
		}
		
		Lis_id[pos] = i;
		
		P[i] = pos ? Lis_id[pos - 1] : -1; 
	}
	
	
	
	
	vector<int> rec;
	int x;
	for( x = lis_end ; P[x] >= 0; x = P[x]){
		rec.push_back( V[x] );
	}
	reverse(rec.begin(),rec.end());
	
	cout << lis.size() << '\n';
	cout << "-\n";
	cout << V[x] << '\n';
	for(auto i : rec){
		cout << i << '\n';
	}

	return 0;
}
