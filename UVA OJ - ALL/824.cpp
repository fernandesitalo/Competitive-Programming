#include <stdio.h>
using namespace std;

int main()
{
	int grade[3][3];
	int aux[10];
	int x,y,d,xi,yi,c,i;
		
	while(scanf("%d",&xi), xi != -1)
	{
		scanf("%d%d",&yi,&d);
		grade[1][1] = d;
		
		for(i = 0 ; i < 8 ; i++)
		{
			scanf("%d%d%d",&x,&y,&c);			
			grade[x-xi+1][y-yi+1] = c;	
		}
	
		aux[0] = grade[1][2];
		aux[1] = grade[0][2];
		aux[2] = grade[0][1];
		aux[3] = grade[0][0];
		aux[4] = grade[1][0];
		aux[5] = grade[2][0];
		aux[6] = grade[2][1];
		aux[7] = grade[2][2];
		
		d = (d+5)%8;
		
		
		//int anterior = d;
		
		while(true)
		{
			if(aux[d] == 0){	
				//anterior = d;
				d++;
				if(d == 8)d = 0;	
				
				if(aux[d] == 1)
					break;
			}
			
			if(aux[d] == 1){
				//anterior = d;
				d--;
				if(d == -1)d = 7;				
			}
		}
		
		printf("%d\n",d);
	}
	return 0;

}
