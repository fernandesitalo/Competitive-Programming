#include <stdio.h>
#include <vector>
#include <utility>
#define INI -1
using namespace std;

int main()
{
	int linha,coluna,pos,i,c;
	char aux[50];
	while(scanf(" %d %d %d",&linha,&coluna,&pos), linha||coluna||pos)
	{
		vector<pair<char,int> > grafo[linha];
		
		pair<char,int > temp;
		
		for(i = 0 ; i < linha ; i++)
		{
			scanf(" %s",aux);
			
			for(c = 0 ; aux[c] != '\0' ; c++)
			{
				temp.first = aux[c];
				temp.second = INI;
				grafo[i].push_back(temp);
			}
		}

		i = 0;
		c = pos-1;		
		int cont= 0;
		while(i > -1 && c > -1 && i < linha && c < coluna && grafo[i][c].second == INI)
		{
			switch(grafo[i][c].first){
			case 'N':
					grafo[i--][c].second = cont;
					break;
			case 'S':
					grafo[i++][c].second = cont;
					break;		
			case 'E':
					grafo[i][c++].second = cont;
					break;
			case 'W':
					grafo[i][c--].second = cont;
					break;			
			}	
			cont++;	
		}
		
		if(i < 0 || c < 0 || i >= linha || c >= coluna)
			printf("%d step(s) to exit\n",cont);
		else
		{
			i = cont - grafo[i][c].second;
			printf("%d step(s) before a loop of %d step(s)\n",cont - i,i);
		}		
	}
	return 0;
}
