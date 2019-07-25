#include <bits/stdc++.h>
using namespace std;


int partition(int *arr,int pos_pivo,int l, int r){
	int pivo = arr[pos_pivo];
	for(int i = l ; i < r ; ++i){
		if(pivo >= arr[i]) 
			swap(arr[l++],arr[i]);
	}	
	swap(arr[l],arr[pos_pivo]);	// colocar o pivo no lugar certo
	return l;
}


void QUICKSORT(int *arr, int l, int r){
	if(l >= r) return; // não tem o que fazer...
	int pos_pivo = partition(arr,r,l,r);	
	QUICKSORT(arr,l,pos_pivo-1);
	QUICKSORT(arr,pos_pivo+1,r);	
}



int main(){	

	int vet[] = {5,3,1,5,8,3,9,4,7,9,11,22,33,44,55,66,77,88,88};
	
	int n = (sizeof (vet)/ sizeof (int));
	
	cout << n << endl;
	
	QUICKSORT(vet,0,n-1);
	
	for(int i = 0 ; i < n ; ++i){
		cout << vet[i] << " ";
	} cout << endl;

	return  0;


	return 0;
}
