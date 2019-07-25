#include <stdio.h>
#include <stack>
#include <list>
#include <iostream>
using namespace std;



int main()
{
	string carta;
	
		list<stack<string> >::iterator iter;
		list<stack<string> >::iterator iter2;	
	
	while(cin>>carta, carta[0] != '#')
	{
		list<stack<string> > v(52);

		
		iter = v.begin();
		
		iter->push(carta);
		
		iter++;
		
		
		for(; iter != v.end() ;++iter)
		{
			cin>>carta;
			iter->push(carta);
		}
		
		iter = v.begin();		
		int i = 0;
		string a,b;
		
		while(iter != v.end())
		{	
			if(i-3 >= 0)
			{
				iter2 = iter;
				
				iter2--;
				iter2--;
				iter2--;
				
				a = iter->top();
				b = iter2->top();
				
				if(a[0] == b[0] || a[1] == b[1])
				{
					iter2->push(iter->top());
					iter->pop();
					
					if(iter->empty())
						v.erase(iter);	
					
					iter = iter2;
					i -= 3;
					continue;										
				}
					
			}
			
			if(i-1 >= 0)
			{
				iter2 = iter;
				
				iter2--;
				a = iter->top();
				b = iter2->top();
				
				if(a[0] == b[0] || a[1] == b[1])
				{
					iter2->push(iter->top());
					iter->pop();
					
					
					if(iter->empty())
						v.erase(iter);
					iter = iter2;
					i--;	
					continue;
				}
			}
			
			i++;
			iter++;
		}
		
		if(v.size() == 1)
		{
			printf("1 pile remaining: 52\n");
			
		}
		else
		{
			printf("%d piles remaining:",v.size());
			
			iter = v.begin();
			
			for(int k = 0 ; k < v.size() ; k++)
			{
				printf(" %d",iter->size());
				iter++;
			}
			printf("\n");
		}
	}
	return 0;
}
