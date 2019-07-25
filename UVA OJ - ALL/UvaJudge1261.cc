#include <bits/stdc++.h>
using namespace std;


map<string, bool> pd;

bool F(string str){
	
	//cout << str << endl;
	
	if(str.size() == 0) return true;
	if(str.size() == 1) return false;
	
	if(pd.find(str) != pd.end()) return pd[str];
	
	for(int i = 0 ; i < (int)str.size() ;){
		int f = i+1;
	
		while((int)str.size() > f && str[f] == str[i]) f++;
		
		
		
		if(f-i > 1){
		//	printf("%d %d\n",i,f);
			string aux = str;
			aux.erase(i,f-i); //////	PRIMEIRO PARAMETRO E AONDE TA O INICIO DE ONDE QUERO EXLUIR, O SEGUNDO PARAMENTRO E O TANTO
		//	cout << str << " ---> " << aux << endl;
			
			pd[str] = F(aux);
			if(pd[str] == true) return true;
		}
		i = f;
	}
	
	return pd[str];
}



int main(){
	
	//freopen("in_","r",stdin);
	
	int t;
	string str;
	cin >> t;
	while(t--)
		pd.clear(),cin>>str,cout << F(str)<< endl;
	
	return 0;
}
