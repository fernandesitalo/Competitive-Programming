#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<utility>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;



int numSCC,dfsNumberCounter;

map< string,int > dfs_num, dfs_low;

map<string,int> visited;

stack<string> S;

map< string, set<string> > AdjList;

void tarjanSCC(string u) {

	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	S.push(u);	
	visited[u] = 1;
	
	for(set<string>::iterator it = AdjList[u].begin() ; it != AdjList[u].end() ; ++it){
		string v = *it;
		
		if (dfs_num[v] == -1) // 0 e que nao foi visitado ainda
			tarjanSCC(v);
	
		if (visited[v])		
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
	}
	
	if (dfs_low[u] == dfs_num[u]) {
		
		++numSCC;
		
		bool flag = false;
		
		while(1){
			if(flag) {cout<<", ";}flag = true;
			
			string v = S.top(); S.pop(); visited[v] = 0;
			cout <<v;
			if (u == v) break; 
		}	
		printf("\n");
	} 
}





void reset(){AdjList.clear();}

int main(){
	
	int ct = 1,n,m;
	
	string u,v;
	
	bool alface = false;
	
	while(scanf("%d%d",&n,&m),n||m){
		if(alface)puts("");
		alface = true;
		
		AdjList.clear();
		
		for(int h = 0 ; h < m ; h++){
			cin>>u>>v;
			AdjList[u].insert(v);
			visited[u] = 0;
			visited[v] = 0;
			dfs_num[u] = -1;
			dfs_num[v] = -1;
		}
		
		dfsNumberCounter = numSCC = 0;	
			
		printf("Calling circles for data set %d:\n",ct++);
		for(map<string,set<string> >::iterator it = AdjList.begin() ; it != AdjList.end() ; ++it){
			if (dfs_num[it->first] == -1) tarjanSCC(it->first);
		}
	}

	return 0;
}
