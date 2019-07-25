#include<bits/stdc++.h> 
using namespace std;

int main(){
	string arr;
	int ct = 1;
	while(cin>>arr, arr[0] != '*'){
		printf("Case %d: ",ct++);
		printf(arr == "Hajj"? "Hajj-e-Akbar\n": "Hajj-e-Asghar\n");
	}
	return 0;
}
