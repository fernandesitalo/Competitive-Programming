#include<stdio.h>
#include<vector>
#include<string.h>
#include<set>
#define TAM 8
using namespace std;

vector<set<int> > graf(6);
bool vis[10][10];
vector<int> resposta;




void CaminhoEuleriano(int n){
	
	if(resposta.size() > 8){
		for(int r = 0 ; r < (int)resposta.size() ; r++){
			printf("%d",resposta[r]);
		}
		puts("");
		return;
	}
	
	
	
	for(set<int>::iterator it = graf[n].begin(); it!= graf[n].end(); ++it){
		int v = *it;
		
		if(!vis[n][v]){
			
			vis[n][v] = true;
			vis[v][n] = true;
			
			resposta.push_back(v);
			CaminhoEuleriano(v);
			resposta.erase(resposta.end()-1);
			
			vis[n][v] = false;
			vis[v][n] = false;			
		}		
	}
	
	
}


int main(){
	
	graf[1].insert(2);
	graf[1].insert(3);
	graf[1].insert(5);

	graf[2].insert(3);
	graf[2].insert(5);
	graf[2].insert(1);

	graf[3].insert(2);
	graf[3].insert(1);
	graf[3].insert(5);
	graf[3].insert(4);

	graf[4].insert(3);
	graf[4].insert(5);

	graf[5].insert(4);
	graf[5].insert(3);
	graf[5].insert(2);
	graf[5].insert(1);
	memset(vis,false,sizeof(vis));
	
	resposta.push_back(1);
	CaminhoEuleriano(1);
	
	return 0;
}
