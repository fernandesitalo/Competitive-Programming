#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

map<string,vector<string> > grafo;
set<string> vis;
map<string,string> caminho;

void reset(){
		caminho.clear();
		vis.clear();
		grafo.clear();
}

bool bfs(string inicio,string fim){
	
	queue<string>q;
	q.push(inicio);
	vis.insert(inicio);
	while(!q.empty()){
		string top = q.front();
		q.pop();
		
		if(top == fim)
			return true;	
		
		for(int i = 0 ; i < (int)grafo[top].size() ; i++){
			
			if(vis.find(grafo[top][i]) == vis.end()){
				vis.insert(grafo[top][i]);
				q.push(grafo[top][i]);
				caminho[grafo[top][i]] = top;
			}		
		}		
	}
	return false;
}

int main()
{	
#ifndef ONLINE_JUDGE
    freopen("../e.txt","r", stdin);
    freopen("../s.txt","w", stdout);
#endif

	int i,qtd;
	string str1,str2;
	bool flag = false;
	
	while(scanf("%d",&qtd)!= EOF){
		reset();
		for(i = 0 ; i < qtd ; i++){
			cin>>str1>>str2;
			grafo[str1].push_back(str2); // bidirecional
			grafo[str2].push_back(str1); // bidirecional
		}
		cin>>str1>>str2;
		if(flag)puts("");
		flag = true;
		
		if(bfs(str1,str2)){				
			string aux;		
			aux = str2;
			stack<string>s;
			while(str1 != aux){
				s.push(aux);
				aux = caminho[aux];		
			}
			s.push(str1);
			
			while((int)s.size() > 1){
				aux = s.top();
				s.pop();
				cout<<aux<<" "<<s.top()<<endl;					
			}
		}
		else
			puts("No route");		
	}
	return 0;
}
