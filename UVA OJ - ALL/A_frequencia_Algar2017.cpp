/* O problema e muito simples, muito simples mesmo...
 * temos que contar quantas vezes cada vogal aparece e imprimir na tela
 * em ordem decrecente de valor e caso tenha empate, ordem alfabetica
 * SÓ ISSO... 
 */

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,char> a, pair<int,char> b){
	if(a.first == b.first)
		return (a.second < b.second);
	return (a.first > b.second);	
}

int main(){
	int i;
	string e;
	
	while(getline(cin,e),e[0]!='#'){		
		map<char,int> m;
		for(i = 0 ; e[i] ; ++i){
			if(e[i] <= 65) e[i]+=32;
			m[e[i]]++;		
		}
		
		vector<pair<int,char> > v;
		v.push_back(make_pair(m['a'],'a'));
		v.push_back(make_pair(m['e'],'e'));
		v.push_back(make_pair(m['i'],'i'));
		v.push_back(make_pair(m['o'],'o'));
		v.push_back(make_pair(m['u'],'u'));
		
/////////////////////////////////////////////////////////////// funcao cmp para a comparacao e assim a ordenacao!!!!!!!!!!!!		
		sort(v.begin(),v.end(),cmp); // usa um algoritmo desconhecido para ordenar
		// funcao sort da biblioteca #include <algorithms>
///////////////////////////////////////////////////////////////				
		
		printf("%c:%d",v[0].second,v[0].first);	
		for(i = 1; i < 5 ; i++){			
			printf(" %c:%d",v[i].second,v[i].first);		
		}puts(".");
	
	}	
	return 0;
}
