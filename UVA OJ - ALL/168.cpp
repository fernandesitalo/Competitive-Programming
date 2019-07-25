
/*
A:BCD;B:AD;D:BG;F:H;G:DEH;E:FGH;H:EG;C:AD. A C 3
#
*/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	string entrada;
	int i,minotauro,teseu,qtd,v;
	char a,b;
	while(cin>>entrada, entrada[0] != '#')
	{
		vector<vector<int> > grafo(1000);
	
		i = 0;
		while(entrada[i] != '\0') // contrucao do grafo 
		{	
			//printf("%c ::::  ",entrada[i]);
			v = entrada[i] - 65;
			i++;i++;
			while(entrada[i]!= ';' && entrada[i] != '.'){
			//	printf("%d  ",entrada[i]);
				grafo[v].push_back(entrada[i++] - 65);
			}	//	printf("\n");					
			i++;
		}
		scanf(" %c %c %d",&a,&b,&qtd);
		
		minotauro = a - 65;
		teseu = b - 65;
		
		vector<bool > vela(1000,false);
		
		int cont = 0;
		
		bool flag = true;
		while(1)
		{
			for(i = 0 ; i < (int)grafo[minotauro].size(); i++)
			{
				
				if(!vela[grafo[minotauro][i]] && grafo[minotauro][i] != teseu)
				{
					if(++cont == qtd)
					{
						vela[minotauro] = true;        printf("%c ",minotauro + 65);						
						cont = 0;
					}			
					
					teseu = minotauro;//teseu vai atras						
					minotauro = grafo[minotauro][i];	
					flag = false;
					break;				
				}				
			}
			if(!flag)
			{
				flag = true;
				continue;
			}
			
			break;
		
		}

		printf("/%c\n",minotauro+65);

	}
	return 0;
}
