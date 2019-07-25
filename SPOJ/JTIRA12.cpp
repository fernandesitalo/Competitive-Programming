#include <stdio.h>

int main(){
	
	int x,y;
	char s[7] = {'f','o','r','a'};
	
	scanf("%d%d",&x,&y);
	
	if(x >= 0 && x <= 432)
	{
		if(y <= 468 && y >= 0)
		{
			s = 'dentro';
		}
	}
	
	printf("%s",s);	
	
	return 0;
}
