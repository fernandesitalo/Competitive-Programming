#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

set<string> s;
map<string,vector<string> > grafo;
map<string,int> dist;
set<string> vis;

void bfs(string erdos){
	vis.clear();dist.clear();
	queue<string> q;
	q.push(erdos);	
	dist[erdos] = 0;
	vis.insert(erdos);
	while(!q.empty()){
		string top = q.front();
		q.pop();		
		for(int i = 0 ; i < (int)grafo[top].size() ; i++)			
			if(vis.find(grafo[top][i]) == vis.end()){
				vis.insert(grafo[top][i]);
				q.push(grafo[top][i]);
				dist[grafo[top][i]] = dist[top] + 1;
			}					
	}
}


void SeparaAutor(string entrada){
	s.clear();
	int i = 1,cont = 1;	
	char aux[100000];	
	aux[0] = entrada[0];

	while(entrada[i] != '\0'){
		
		if(entrada[i-1] == '.' && entrada[i] == ','){			
			aux[cont] = '\0';
			cont = 0;
			s.insert(aux);
			i++;i++;
		}
		else if(entrada[i-1] == '.' && entrada[i] == ':'){
			aux[cont] = '\0';		
			cont = 0;	
			s.insert(aux);	
			break;
		}		
		aux[cont++] = entrada[i++];	
				
	}	
}

void ColocaNoGrafo(){
	
	
	string aux;
	for(set<string>::iterator tor = s.begin() ; tor != s.end() ; tor++){
		aux = *tor;		
		for(set<string>::iterator it = s.begin() ; it != s.end() ; it++)
			if(aux != *it)					
				grafo[aux].push_back(*it);
	}
	s.clear();
}

int main(){
	
	char entrada[1000000];
	int qtd,ct,i,num,tam;
	
	for(scanf(" %d",&qtd), ct = 1 ; ct <= qtd ; ct++){	
		grafo.clear();			
		for(scanf(" %d %d",&num,&tam), i = 0 ; i < num ; i++){
			scanf(" %[^\n]s",entrada);		
			SeparaAutor(entrada);
			ColocaNoGrafo();			
		}
		bfs("Erdos, P.");printf("Scenario %d\n",ct);
		
		for(i = 0 ; i < tam ; i++){
			scanf(" %[^\n]s",entrada);				
			if(dist.find(entrada) == dist.end())
				printf("%s infinity\n",entrada);
			else
				printf("%s %d\n",entrada,dist[entrada]);				
		}
	}
	return 0;
}
