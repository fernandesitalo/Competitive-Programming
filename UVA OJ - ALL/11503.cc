/* UVA JUDGE 115023____ Virtual Friends
 * 	
 * SOLUCAO: aplicacao direta do Union find, fazendo um vetor de quantidade
 * vetor de quantidade e atualizado sempre que e feita uma uniao,
 * a quantidade de elemntos de um conjunto mais a quantidade de elementos 
 * do outro conjunto..., sempre verificar se dois elementos sao de conjuntos
 * diferentes... sempre... pq nao podemos unir elementos do mesmo conjunto... 
 * 
 */
#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int pai[MAXN];
int qtd[MAXN];

int findSet(int i)
{return pai[i] == i? i : pai[i] = findSet(pai[i]);}

int UnionSet(int i, int j)
{ 	int x = findSet(i);
	int y = findSet(j);
	if(x != y){
		pai[x] = y;
		qtd[x] += qtd[y];
		return qtd[y] = qtd[x];
	}
	return qtd[x];
}


int main(){

	//freopen("in","r",stdin);
	int t,q;	
	for(scanf(" %d",&t);t--;){		
		for(int i = 0 ; i < MAXN ; ++i) pai[i] = i , qtd[i] = 1;
		string str1,str2;
		map<string,int> m;
		int index = 0;
		for(scanf("%d",&q);q--;){
			cin>>str1>>str2;
			if(m.find(str1) == m.end()) m[str1] = index++;
			if(m.find(str2) == m.end()) m[str2] = index++; 
			printf("%d\n",UnionSet(m[str1],m[str2]));
		}
	}
	return 0;
}
