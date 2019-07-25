#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;



int main(){
	
	int op,aux,qtd;
	
	while(scanf("%d",&qtd) != EOF){
	
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq; 
		
		bool pilha = true;
		bool pfila = true;
		bool fila = true;
		
		while(qtd--){
			scanf("%d%d",&op,&aux);
			
			if(op == 1){
				
				if(pilha)s.push(aux);
				if(fila)q.push(aux);
				if(pfila)pq.push(aux);
			}	
			else{				
				
				if(!s.empty() && pilha && s.top() == aux) s.pop();			
				else pilha = false;
				
				if(!q.empty() && fila && q.front() == aux) q.pop(); 
				else fila = false;
				
				if(!pq.empty() && pfila && pq.top() == aux) pq.pop();
				else pfila = false;					
			}			
		}		
		
		if(!pilha && !fila && !pfila){
			printf("impossible\n");continue;}
		
		if(pilha && !fila && !pfila){
			printf("stack\n");continue;}
		
		if(!pilha && fila && !pfila){
			printf("queue\n");continue;}
		
		if(!pilha && !fila && pfila){
			printf("priority queue\n");continue;}
					
		printf("not sure\n");			
	}
	
	return 0;
}
