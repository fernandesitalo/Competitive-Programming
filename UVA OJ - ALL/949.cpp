/* neste progama usamos uma matriz 5d booleana, poderia ter sido uma 4d, mas tudo bem
 * nas dimensoes 1,2,3,4 marcamos se a celula ja foi ou nao visitada naquela direcao
 * uma funcao 'direcao' foi criada, parametros sendo a celula origem e a celula destino,
 * retornando assim qual direcao seria esta...
 * realizamos bfs nesta matriz analizando sempre as direcoes...
 *  	  
 *           [1]     
 *  		  N
 *		[4]W--|--E[2]	
 *			  S      <--- esquerda       direita---> 
 *	         [3]
 * 
 *  */


#include <stdio.h>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define MAX 101
#define N 1 ///NORTE
#define E 2 ///OESTE
#define S 3 ///SUL
#define W 4 ///LESTE
using namespace std;


int L[] = {0,0,1,-1};
int C[] = {1,-1,0,0};

bool grafo[MAX][MAX][5];
map<pair<int,int>,set<int> > cruzamento;
int linha;
int coluna;

inline bool valida(int l, int c){
	return (l >= 0 && c >= 0 && l < linha && c < coluna);
}

inline int direcao(int li,int ci,int lf,int cf){	
	if(li-1 == lf && ci == cf)return N;		
	if(li+1 == lf && ci == cf)return S;		
	if(ci-1 == cf && li == lf )return W;	
	return E;
}

struct no{
	int l,c,t;	
	no(int l, int c, int t){// construtor no
		this->l = l;
		this->c = c;
		this->t = t;
	}	
};

void reset(){//inicializacao
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j < MAX ; j++){
			grafo[i][j][0] = true;
			grafo[i][j][1] = true;
			grafo[i][j][2] = true;
			grafo[i][j][3] = true;
			grafo[i][j][4] = true;		
		}
	}
	cruzamento.clear();	
}


int bfs(){
	queue<no> q;
	q.push(no(0,0,0));// inicio sempre em (0,0) e tempo 0!!
	int l,c,t,d;
	
	while(!q.empty()){
		l = q.front().l;
		c = q.front().c;
		t = q.front().t;
		q.pop();		
		if(l == linha-1 && c == coluna-1)return t;								
		///printf("l = %d || c = %d\n",l,c);getchar();	
		for(int i = 0 ; i < 4 ; i++){				
			d = direcao(l,c,l+L[i],c+C[i]);	// defina a proxima direcao
				
			if(valida(l+L[i],c+C[i]) && grafo[l][c][d]){				
					if(cruzamento[make_pair(l+L[i],c+C[i])].find(t+1) != cruzamento[make_pair(l+L[i],c+C[i])].end())
						q.push(no(l,c,t+1)); //Espera de um segundo no cruzamento atual pois o prox esta sendo vijiado
					else{
							q.push(no(l+L[i],c+C[i],t+1));
							grafo[l][c][d] = false;							
							///printf(">>>>>     L[i]%d    C[i]%d    D = %d\n",l+L[i], c+C[i],d);				
					}
			}			
		}	
	}	
	
	return -1;
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);
#endif

	int i,qtd,li,lf,ci,cf,tempo;			
	while(scanf("%d%d",&linha,&coluna) != EOF){
		reset();		
		for(scanf("%d",&qtd), i = 0 ; i < qtd ; i++){
			scanf("%d%d%d%d",&li,&ci,&lf,&cf);
			grafo[li][ci][direcao(li,ci,lf,cf)] = false;					
		}
		for(scanf("%d",&qtd), i = 0 ; i < qtd ; i++){
			scanf("%d%d%d",&tempo,&li,&ci);
			cruzamento[make_pair(li,ci)].insert(tempo);
		}
		
		int r = bfs();		
		printf("%d\n",r);		
	}
	return 0;
}


