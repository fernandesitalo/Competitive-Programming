#include <stdio.h>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int main()
{	
	int t,casos,w,r,c,m,n,a,b,x,y;
	
	scanf("%d",&t);
	for(casos = 1 ; casos <= t ; casos++)
	{
		scanf("%d%d%d%d",&r,&c,&m,&n);	
			
		int agua[r][c];		
		int visitados[r][c];	
		
		for(w = 0,a = 0; a < r ; a++)
			for(b = 0 ; b < c ; b++)
				agua[a][b] = 0,visitados[a][b] = false;		
				
		scanf("%d",&w);
		while(w--){
			scanf("%d%d",&x,&y);			
			agua[x][y] = -1;
		}		
		
		int dx[] = {+m,-m,+m,-m,+n,-n,+n,-n};
		int dy[] = {+n,+n,-n,-n,+m,+m,-m,-m};
		
		
		set<pair<int,int> >s;
		queue<pair<int,int> >q;
		pair<int,int >p,atual;
		
		
		p.first = 0,p.second = 0;
				
		q.push(p);
		visitados[0][0] = true;
				
		while(!q.empty())
		{
			atual = q.front();
			q.pop();
			
			s.clear();
			
			s.insert(make_pair(atual.first+dx[0],atual.second+dy[0]));
			s.insert(make_pair(atual.first+dx[1],atual.second+dy[1]));
			s.insert(make_pair(atual.first+dx[2],atual.second+dy[2]));
			s.insert(make_pair(atual.first+dx[3],atual.second+dy[3]));
			s.insert(make_pair(atual.first+dx[4],atual.second+dy[4]));
			s.insert(make_pair(atual.first+dx[5],atual.second+dy[5]));
			s.insert(make_pair(atual.first+dx[6],atual.second+dy[6]));
			s.insert(make_pair(atual.first+dx[7],atual.second+dy[7]));

			for(set<pair<int,int> >::iterator it = s.begin(); it != s.end() ; it++)
			{
				x = it->first;
				y = it->second;
				
				if(x >= 0 && x < r && y >= 0 && y < c && agua[x][y]  != -1)
				{
					agua[x][y]++;
					if(!visitados[x][y])
					{
						visitados[x][y] = true;
						q.push(*it);
					}					
				}			
			}			
		}
		
		x = 0;//par
		y = 0;//impar
		for(a = 0; a < r ; a++)
			for(b = 0 ; b < c ; b++)
			if(agua[a][b] > 0)
			{
				if(agua[a][b]%2 == 0)
					x++;
				else
					y++;
			}
			
			if(x == 0 && y == 0) x = 1;
				
		printf("Case %d: %d %d \n",casos,x,y);		
			
			
			
			
			
			
		}
		
				
	
	return 0;
}
