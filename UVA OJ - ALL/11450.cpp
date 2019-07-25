#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;



int C,M;
int memo[205][25];
int price[24][24];


int shop(int money, int g) {
	if (money < 0) return -666;
	// fail, return a large -ve number
	if (g == C) return M - money;
	// we have bought last garment, done
	// if the line below is commented, top-down DP will become backtracking!!
	if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization
	int ans = -1;
	// start with a -ve number as all prices are non negative
	for (int model = 1; model <= price[g][0]; model++)// try all models	
		ans = max(ans, shop(money - price[g][model], g + 1));
	return memo[money][g] = ans; 
}


// TOP-DOWN: memoize ans and return it


int main(){
	int qtd;
	scanf(" %d",&qtd);
	
	while(qtd--){
		scanf(" %d %d",&M,&C);
		
		for(int i = 0 ; i < C ; i++){
			scanf(" %d",&price[i][0]);
			for(int  j = 1 ; j <= price[i][0] ; j++){
				scanf(" %d",&price[i][j]);				
			}
		}
		memset(memo,-1,sizeof(memo));
		
		int score = shop(M,0);
		
		printf(score < 0 ? "no solution\n":"%d\n",score);	
	}
	return 0;
}






