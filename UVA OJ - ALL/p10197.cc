#include <bits/stdc++.h>
using namespace std;
/// LINHA COLUNA
/// LINHA COLUNA

string tr[3][6] = {"o","as","a","amos","ais","am",
									"o","es","e","emos","eis","em",
									"o","es","e","imos","is","em"};
									
string pn[6] = {"eu        ","tu        ","ele/ela   ","nos       ","vos       ","eles/elas "};
int main()
{	
	pn[3][1] = (char)243;
	pn[4][1] = (char)243;
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	string vpt,ven,rad; // verb portuguese and verb in english
	int i,l;
	bool p = 0;
	while(cin>>vpt>>ven){
		int t = vpt.size()-1; l = -1;
		
		if(vpt.size() >= 2){
			if(vpt[t-1] == 'a') l = 0;
			else if(vpt[t-1] == 'e') l = 1;
			else if(vpt[t-1] == 'i') l = 2;
			
			rad = string(vpt.begin(),vpt.begin()+t-1);
		}
		
		if(p) puts(""); p = 1;
		
		printf("%s (to %s)\n",vpt.data(),ven.data());
		
		if( l > -1 && vpt[t] == 'r'){
			for(i = 0 ; i < 6 ; ++i)	cout << pn[i] << rad<<tr[l][i]<< '\n';
		}else puts("Unknown conjugation");
	}
	
	return 0;	
}

/*
falar (to talk)
eu 				falo
tu		 		falas
ele/ela 	fala
ns 			 falamos
vs 			 falais
eles/elas falam
*/
