#include<stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<set>
#include<queue>
using namespace std;

map<string,int> indice;

map<int,string> ci;

vector<int> grau;

vector< vector<int> > grafo;
vector<bool> removido;

vector<int> ts;
//priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > pq;


void reset(int n)
{
    grau.assign(n,0);

    removido.assign(n, false);
    
    vector<int> a;
    grafo.assign(n,a);
    
    ts.clear();
    indice.clear();
    ci.clear();
}




void TS(){
	
	for(int i = 0 ; i < (int)grafo.size() ; i++){/// EXECULTAR A ORDENAÇÃO TOPOLOGICA
			if(grau[i] == 0)
				pq.push(i);				
	}
	
	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();

		ts.push_back(top);
		
		removido[top] = true;
	   
		//printf("%d:      /%d/",top,grafo[top].size());
		for (int k = 0 ; k < (int)grafo[top].size(); ++k)
		{
			
			int v = grafo[top][k];               //  printf("%d  ",v);
		   
			if (!removido[v]  && --grau[v] == 0)
				pq.push(v);
		}//printf("\n");
	}
}	
	


int main(){
	
	char b1[60],b2[60];
	int n,m;
	int ct = 1;
	
	while(scanf(" %d",&n) != EOF){
		
		reset(n);
		
		int cont = 0;
		while(n--){
			scanf(" %s",b1);
				indice[b1] = cont;				
				ci[cont] = b1;				
				cont++;
		}			
		scanf(" %d",&m);	
		
		while(m--){
			scanf(" %s %s",b1,b2);
			grafo[indice[b1]].push_back(indice[b2]);
			
			//printf("(%s)%d -> (%s)%d\n",b1,indice[b1],b2,indice[b2]);
			
			grau[indice[b1]] *= 1;
			grau[indice[b2]]++;		
		}		
		
		TS();
		
		printf("Case #%d: Dilbert should drink beverages in this order:",ct++);
		
		for(int i = 0 ; i < (int)ts.size() ; i++){
			cout <<" "<<ci[ts[i]];
		}
		printf(".\n\n");	
	}	
	return 0;
}
