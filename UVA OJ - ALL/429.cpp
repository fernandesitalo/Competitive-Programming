#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

map<string,vector<string> >::iterator it;
map<string,vector<string> > grafo;
map<string,int> vist;


int bfs(string &a, string &b){	
	queue<string> fila;	
	fila.push(a);
	vist[a] = 0;
	
	while(!fila.empty())
	{
		string top = fila.front();
		fila.pop();
		
		if(top == b)
			return vist[top];
		
		for(int i = 0 ; i < (int)grafo[top].size() ; i++)
		{
			if(!vist[grafo[top][i]])
			{
				vist[grafo[top][i]] = vist[top] + 1;
				fila.push(grafo[top][i]);
			}			
		}
	}
	
	return -1;
}


int main(){
	
	string entrada;
	int diferente,num;
	
	scanf("%d",&num);
	while(num--)
	{
			
		cin>>entrada;	
		while(entrada != "*")
		{
			grafo[entrada];
			for(it = grafo.begin() ; it != grafo.end() ; it++)
			{
				diferente = 0;
				string temp = it->first;
				
				if(temp.size() == entrada.size())// tamanhos iguais... esta ok...
				{ 
					for(int i = 0 ; i < (int)entrada.size() && diferente < 2; i++)
					{
						if(entrada[i] != temp[i])
							diferente++;								
					}					
					if(diferente == 1)
					{
						grafo[temp].push_back(entrada);
						grafo[entrada].push_back(temp);					
					}				
				}			
			}
			
			cin>>entrada;
		}
		string d,c;	
		
		getline(cin,d);	
		cin>>c;
			
		cout << d<<" "<<c;
			
		printf("%d",bfs(d,c));

	}
	return 0;
}
