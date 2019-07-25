#include<stdio.h>      
#include<list>          
using namespace std;


struct no{
	bool marcado;
	int prioridade;
	
	no(int x,bool a = false){
		marcado = a;
		prioridade = x;
	}
};

int main(){
	int qtd,m,n,aux;
	
	scanf("%d",&qtd);
	
	while(qtd--){
		
		 
		  
		scanf("%d%d",&n,&m);// n é o número de trabalhos na fila   m é a posição do seu trabalho 
		list<no> l;
		
		int i = 0;
		while(n--){			
				scanf("%d",&aux);
			if(i++ == m)	
				l.push_back(no(aux,true));	
			else	
				l.push_back(no(aux,false));	
		}
		
		int time = 0;
					
		while(1){
			
			list<no>::iterator maior = l.begin();
			list<no>::iterator aux;
		
			for(aux = l.begin(); aux != l.end() ; aux++){
				if(aux->prioridade > maior->prioridade)
					maior = aux;			
			}
			
			
			while(l.begin() != maior){
				l.push_back(*l.begin());
				l.pop_front();
			}
			
			time++;
			
			if(l.begin()->marcado == true) break;
			
			l.pop_front();

		}
		
		printf("%d\n",time);
	
	}
	return 0;
}
