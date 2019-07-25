#include <bits/stdc++.h>
using namespace std;


int main(){

	string arr;

	while(cin>>arr){
		
		int i = 0;
		int f = arr.size()-1;
		
		while(i <= f){
			cout <<" 1 : " << arr << endl;
			
			if(arr[i] == arr[f]) ++i;
			else{
				arr.insert(arr.begin()+f+1,arr[i]);
			}
			cout <<" 2 : " << arr << endl;


		}
		
		cout << arr << endl;
		
	
	}

	return 0;
}
