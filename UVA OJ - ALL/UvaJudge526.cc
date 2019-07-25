#include <bits/stdc++.h>
using namespace std;

string str1,str2;


int pd[100][100];

int F(int m, int n){
	
	if(m == 0) return n;
	if(n == 0) return m;
	
	if(pd[m][n] != -1) return pd[m][n];
	
	if(str1[m-1] == str2[n-1]) 
		return pd[m][n] = F(m-1,n-1);
	
	return pd[m][n] = 1 + min( F(m,n-1) ,min( F(m-1,n) , F(m-1,n-1) ) );	
}


int cont;

int pos;

void rec(int m, int n){
	
	if(m == 0){
		pos = n+1;
		for(int i = 0 ; i < n ; ++i) printf("%d Insert %d,%c\n",cont++,i+1,str2[i]);
		return;	
	}
	if(n == 0){
		pos = 0+1;
		for(int i = m-1 ; i >= 0 ; --i)	printf("%d Delete %d\n",cont++,1);
		return;	
	}
	

	
	if(str1[m-1] == str2[n-1]){
		
		 rec(m-1,n-1);pos++;
		 
	}
	else{
		if(pd[m][n] == 1+F(m,n-1)){
			rec(m,n-1);
			printf("%d Insert %d,%c\n",cont++,pos++,str2[n-1]);
			
			
			
		}
		else{
			if(pd[m][n] == 1+F(m-1,n)){
				rec(m-1,n);
				printf("%d Delete %d\n",cont++,pos);
			}
			else{
				rec(m-1,n-1);
				printf("%d Replace %d,%c\n",cont++,pos++,str2[n-1]);		
			}
		}	
	}
}



int main(){
	
	
	freopen("in","r",stdin);
	
	bool p = 0;
	
	while(getline(cin,str1)){ getline(cin,str2);
		if(p) puts("");p = 1;
		
		memset(pd,-1,sizeof pd);
		
		pos = str2.size();
		cout << F(str1.size(),str2.size()) << endl;
		cont = 1;
		rec(str1.size(),str2.size());	
	}
	return 0;
}
