#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <iostream>
using namespace std;
	
	/*
	pair<int,int> a,b;
	a.first = 1;
	a.second = 1;
	
	b.first = 1;
	b.second = 1;
	
	if(a == b);
		return 0;
	*/	
bool a;
int main()
{
	set<pair<int,int> > fora;
	pair<int,int> aux;
	
	int xl,yl,x,y,i;
	char o,str[102];

	
	scanf(" %d %d",&xl,&yl);
	
	while(scanf(" %d %d %c",&x,&y,&o) != EOF)
	{				
		cin>>str;		
		a = false;
		
		
		for(i = 0 ; str[i] != '\0'; i++)
		{	
		//	printf(" >>>>>>>>>>>>>>>>>>>>>>>>>> %c\n", str[i]);
		//	printf(":::: %d %d %c \n",x,y,o); 
			aux.first = x;
			aux.second = y;
			

				
			if(str[i] == 'L')
			{
				if(o == 'N') {o = 'W';}				
				else if(o == 'E') {o ='N';}		
				else if(o == 'S') {o = 'E';}
				else {o = 'S';}
				
				continue;
			}		
			if(str[i] == 'R')
			{
				if(o == 'N') o = 'E';									
				else if(o == 'E') o ='S';		
				else if(o == 'S') o = 'W';
				else {o = 'N';}	
				
				continue;
			}
			
	//		if(fora.find(aux) != fora.end() && ((x == 0 && o == 'W') || (y == 0 && o == 'S') || (x == xl && o == 'E') || (y == yl &&  o == 'N')))
		//		continue;
			
			
			if((x == 0 && o == 'W') || (y == 0 && o == 'S') || (x == xl && o == 'E') || (y == yl &&  o == 'N'))
			{
				if(fora.find(aux) != fora.end())
					continue;
				
				aux.first = x;
				aux.second = y;
				fora.insert(aux);			
				a = true;
				break;
			} 
			
			if(o == 'N'){y++;}										
			else if(o == 'E'){x++;}								
			else if(o == 'S'){y--;}					
			else {x--;}					
		}
		
		if(a)
		{
			printf("%d %d %c LOST\n",x,y,o);			
		}
		else printf("%d %d %c \n",x,y,o);	
	}
	return 0;
}
