#include <bits/stdc++.h>
using namespace std;

int main(){
	string arr;
	int ct = 1;	
	while(cin>>arr, arr[0] != '#'){
		printf("Case %d: ",ct++);		
		if(arr == "HELLO")				printf("ENGLISH\n");
		else if(arr =="HOLA")			printf("SPANISH\n");
		else if(arr =="HALLO")			printf("GERMAN\n");
		else if(arr =="BONJOUR")		printf("FRENCH\n");
		else if(arr =="CIAO") 			printf("ITALIAN\n");
		else if(arr =="ZDRAVSTVUJTE")	printf("RUSSIAN\n");	
		else  							printf("UNKNOWN\n");
	}	
	return 0;
}
