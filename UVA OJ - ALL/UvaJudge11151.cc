#include <string.h>
#include <iostream>
#include <stdio.h>
#define MAXN 1004
using namespace std;

//~ char array[MAXN*2];
int pd[MAXN][MAXN];
string array;
int PALINDROME(int l, int r){
		
	if(l == r) return 1; // MENOR PALINDROMO POSSIVEL TEM TAMANHO 1;
	if(l+1 == r) return array[l] == array[r]?2:1;
	if(pd[l][r] != -1)	return pd[l][r];
	
	if(array[l] == array[r]) pd[l][r] = 2 + PALINDROME(l+1,r-1);
	else					 pd[l][r] = max(PALINDROME(l,r-1),PALINDROME(l+1,r));
	
	return pd[l][r];
}
// ADAM
// MADAM


int main(){
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	int t;
	for(cin>>t;t--;){
		getline(cin,array);
		memset(pd,-1, sizeof pd);
		cout << PALINDROME(0,array.size()-1) <<endl;
	}

	
	return 0;
}
