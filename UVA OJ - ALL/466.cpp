#include <stdio.h>
#define MAX 11
using namespace std;
char ori[MAX][MAX];
char alt[MAX][MAX];
char aux[MAX][MAX];
int tam;

//Rotação de 90 graus: O padrão foi girado para a direita 90 graus.
bool rotacao90(){
	for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam ; j++)
			if(alt[i][j] != ori[(tam-1)-j][i])
				return false;
	}	
	return true;
}

bool rotacao180(){
	for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam ; j++)
			if(alt[i][j] != ori[(tam-1)-i][(tam-1)-j])
				return false;
	}	
	return true;
}

bool rotacao270(){
	for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam; j++){
			if(alt[i][j] != ori[j][(tam-1)-i])
				return false;
			}
	}	
	return true;
}

bool preservada(){
	
		for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam; j++)
			if(alt[i][j] != ori[i][j])
				return false;
	}	
	return true;
}

//Reflexão Vertical: O padrão foi refletido através de um espelho horizontal posicionado acima do padrão.
bool reflexaoVer(){	
		for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam; j++){
			if(alt[i][j] != ori[(tam-1) - i][j])
				return false;			
		}
	}	
	return true;
}



int combinacao(){
	for(int i = 0 ; i < tam ; i++){
		for(int j = 0 ; j < tam; j++){
		aux[i][j] = ori[(tam-1) - i][j];		
		}
	}	
	
	bool flag = true;
	for(int i = 0 ; i < tam ; i++){ ///// rotacao 90
		for(int j = 0 ; j < tam ; j++)
			if(alt[i][j] != aux[(tam-1)-j][i]){				
				flag = false;break;
			}			
	}	
	if(flag)return 90;	
		
		
	flag = true;
	for(int i = 0 ; i < tam ; i++){ ///// rotacao 180
		for(int j = 0 ; j < tam ; j++)
			if(alt[i][j] != aux[(tam-1)-i][(tam-1)-j]){				
				flag = false;break;
			}			
	}
	if(flag)return 180;
			
			
	flag = true;
	for(int i = 0 ; i < tam ; i++){ ///// rotacao 270
		for(int j = 0 ; j < tam ; j++)
			if(alt[i][j] != aux[j][(tam-1)-i]){				
				flag = false;break;
			}			
	}
	
	if(flag)return 270;
				
	return -1;	
}


int main(){
	
	char mat1[20];
	char mat2[20];
	
	int i,j,cont = 1;
	while(scanf("%d",&tam) != EOF){		
		for(i = 0 ; i < tam ; i++){
			scanf(" %s %s",mat1,mat2);
			for(j = 0 ; j < tam ; j++){
				ori[i][j] = mat1[j];
				alt[i][j] = mat2[j];				
			}			
		}
	
		if(preservada()){
			printf("Pattern %d was preserved.\n",cont++);
			continue;
		}		
		if(rotacao90()){
			printf("Pattern %d was rotated 90 degrees.\n",cont++);
			continue;			
		}
		if(rotacao180()){
			printf("Pattern %d was rotated 180 degrees.\n",cont++);
			continue;			
		}
		if(rotacao270()){
			printf("Pattern %d was rotated 270 degrees.\n",cont++);
			continue;			
		}	
		
		if(reflexaoVer()){
			printf("Pattern %d was reflected vertically.\n",cont++);
			continue;			
		}
		int r = combinacao();
		
		if(r != -1){
			printf("Pattern %d was reflected vertically and rotated %d degrees.\n",cont++,r);
			continue;
		}		
		printf("Pattern %d was improperly transformed.\n",cont++);	
	}
	return 0;
}
