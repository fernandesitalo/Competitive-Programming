#include <bits/stdc++.h>
using namespace std;



int main(){
	int qtd;
	string arr;
	scanf(" %d",&qtd);
	string one = "one";
	while(qtd--){
		cin>>arr;
		int cont = 0;
		if(arr.size() == 3){
			for(int i = 0 ; arr[i] ; i++){
				if(arr[i] != one[i]) cont++;
			}
			if(cont <= 1) printf("1\n");		
			else printf("2\n");		
		} else printf("3\n");		
		
	}
	

	return 0;
}
