#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int num,custo,temp;
	while(scanf("%d",&num), num)
	{
		priority_queue<int,vector<int>,greater<int> > p;
		
		while(num--)
			scanf("%d",&temp),p.push(temp);
		
		custo = 0;	
		while(p.size() != 1)
		{
			temp = p.top();
			p.pop();
			temp += p.top();
			p.pop();
			custo += temp;
			p.push(temp);
		}
		printf("%d\n",custo);	
	}
	return 0;
}
