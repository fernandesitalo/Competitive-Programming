#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	string nome;
	int i,num;

	for(scanf("%d\n\n",&num), i = 0 ; i < num ; i++)
	{
		map<string,int> m;
		map<string,int>::iterator it;
		int cont = 0;
		
		while(getline(cin,nome), nome[0] != '\0')
		{
			cont++;
			if(m.find(nome) == m.end())
				m[nome] = 1;				
			else
				m[nome]++;		
		}
		it = m.begin();
	
		while(it != m.end())
		{			
			cout << it->first;
			printf(" %.4f\n",(float)(it->second * 100)/cont );			
			it++;
		}
		
		if(i+1 != num)
			printf("\n");	
	}	
	return 0;	
}

