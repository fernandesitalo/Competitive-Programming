#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	char arr[30];	
	
	while(scanf(" %[^\n]s",arr) != EOF){	
	printf("%s\n",arr);}
	return 0;
}
