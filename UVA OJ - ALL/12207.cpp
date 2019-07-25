#include<stdio.h>
#include<vector>
#include<list>
using namespace std;

int main(){
	int p,c,aux;
	char o;
	int ct = 1;
	
	while(scanf("%d%d",&p,&c), p || c){
		list<int> l;
		int tam = 0;
		if(p > 1000){
			tam = 1000;
		}
		else{
			tam = p;
		}
		
		for(int i = 1 ; i <= tam ; i++){
			l.push_back(i);
		}
		
		printf("Case %d:\n",ct++);
		
		while(c--){
			scanf(" %c",&o);
			if(o == 'N'){
				printf("%d\n",l.front());
				l.push_back(l.front());
				l.pop_front();			
			}
			else{
				scanf("%d",&aux);
					l.remove(aux);
					l.push_front(aux);				
				}				
			}		
		}
	return 0;
}
