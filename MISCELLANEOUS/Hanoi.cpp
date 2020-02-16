#include <stdio.h>

int hanoi(int h)
{
	if(h == 1)
		return 1;
		
	return (hanoi(h-1))*2 + 1;	
}

int main()
{
	int num;
	
	
	do
	{
	
	scanf("%d",&num);
	
	num = hanoi(num);
	
	printf("====> %d movimentos !\n\n",num);
	}while(1);


	return 0;
}
