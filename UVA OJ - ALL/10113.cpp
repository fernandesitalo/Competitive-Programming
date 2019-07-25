#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct no{
		int inicio;
		int fim;
		int verticefim;
		
		no(int a,int b, int c) // construtor
		{
			inicio = a;
			fim = b;
			verticefim = c;			
		}
};

int main(){
	
	vector<vector<no> > g(1000);
	map<string,int> m;
	
	int q1,q2,cont = 0;	
	char n1[20],n2[20],aux;
	
	while(scanf(" %c",&aux),aux != '.')
	{
		if(aux == '!')
		{
			scanf(" %d ",&q1);			
			cin>>n1;
			scanf(" %c %d",&aux,&q2);
			cin>>n2;

			if(m.find(n1) == m.end())
				m[n1] = cont++;				
					
			if(m.find(n2) == m.end())
				m[n2] = cont++;		
			
			g[m[n1]].push_back(no(q1,q2,m[n2]));
			g[m[n2]].push_back(no(q2,q1,m[n1]));						
		}
		else
		{
			cin >> n1>>aux; // inicio
			cin >> n2; // fim
			
			queue<int> f;
			
			f.push(m[n1]);
			vector<bool> visitados(1000,false);
			vector<int> sucessor(1000);
			
			bool flag = false;
			while(!f.empty())
			{
				int a = f.front();
				f.pop();
				
				for(int i = 0 ; i < (int)g[a].size() ; i++)
				{
					if(!visitados[g[a][i].verticefim])
					{
						visitados[g[a][i].verticefim] = true;
						
						sucessor[g[a][i].verticefim] = a;
						
						f.push(g[a][i].verticefim);
												
						if(g[a][i].verticefim == m[n2])
						{
							flag = true;
							break;
						}
					}					
				}				
			}
			if(!flag)
			{
				
				printf("? %s = ? %s\n",n1,n2);
				continue;
				
			}
			
			stack<int> s;
			
			int i = m[n2], a = m[n1];
			
			while(i != a)
			{
				s.push(i);
				i = sucessor[i];
			}
						
			i = 0;//a = s.top(); a e o vertice de saida, isto é, inicio;
			while(g[a][i].verticefim != s.top() && i < (int)g[a].size()) i++;
			
			q1 = g[a][i].inicio;
			q2 = g[a][i].fim;
			
			while((int)s.size() > 1)
			{
				//printf("%d   %d      a = %d  \n", q1,q2,a);
				a = s.top();
				s.pop();
				
				i = 0;

				while(g[a][i].verticefim != s.top() && i < (int)g[a].size()) i++;

				q1 *= g[a][i].inicio;
				q2 *= g[a][i].fim;		
			}
			
			int dnd,dvs,k = 1;
			
			if(q1 > q2)
			{
				dnd = q1;
				dvs = q2;
			}
			else
			{
				dnd = q2;
				dvs = q1;
			}
			
				while(k != 0)
				{
					k = dnd%dvs;
					dnd = dvs;
					dvs = k;
				}
			
			q1 /= dnd;
			q2 /= dnd;
			
			printf("%d %s = %d %s\n",q1,n1,q2,n2);
			
		}
	}
	return 0;
}
