#include <bits/stdc++.h>
using namespace std;


string E;

int pegaNum(int &i)
{
	string a;
	while( isalnum(E[i]) )a.push_back(E[i++]);
	stringstream ss(a); int b; ss>>b;
	return b; 
}

int solveExpression(int i, int val)
{

	printf("%c %d\n",E[i],val);

	int op = 0;
	if(E[i] == '\0') return val;
	if(isalnum(E[i])) op = pegaNum(i);
	if(E[i] == '\0') return op;
	if(E[i] == '*') return solveExpression(i+1,val*op);
	if(E[i] == '+') return solveExpression(i+1,val+op);	 
	if(E[i] == '(') return solveExpression(i+1,val);
	if(E[i] == ')') return solveExpression(++i,val);
	
	cout << ">>>> " << E[i] << endl;
	
	return -9999999;
	
}



int main(){
	
	cin>>E;
	
	int i = 0;
	int num = pegaNum(i);
	cout << solveExpression(i,num) << endl;
	

	return 0;
}
