#include <stdio.h>
#include <queue>
using namespace std;

int main(){
	int num,i;
	queue<int> baralho;
	
	while(scanf(" %d",&num),num){
		for(i = 0 ; i < num  ; i++)
			baralho.push(i+1);		
		
		printf("Discarded cards:");
		while(baralho.size() > 2){
			printf(" %d",baralho.front());	
			baralho.pop();	
			
			i = baralho.front();			
			baralho.pop();
			
			if(!baralho.empty())
				printf(",");				
			
			baralho.push(i);	
		}				
		printf("\nRemaining card: %d\n",baralho.front());	
		baralho.pop();
	}
	return 0;
}
