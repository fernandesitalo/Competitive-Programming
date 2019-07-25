#include <bits/stdc++.h>
#define freopen(nom) freopen(nom,"r",stdin)
using namespace std;

/*
 * LER UMA FRASE, INVERTER CADA PALAVRA, IMPRIMIR...
 */

int main(){
	
	//~ file("in");
	
	char fr[1000];
	stringstream ss;
	
	while(scanf(" %[^\n]",fr) != EOF){
		ss.clear(); // importante!!!! lembrar de limpar a STRINGSTREAM antes de usa-la....
		ss << fr;
		string str;
		
		bool p = 0;
		
		while(ss>>str){
			if(p) cout << " "; p = 1;
			//~ reverse(str.begin(),str.end());		// 	REVERSE ... ENDERECO DO INICIO E DO FIM....
			reverse(&str[0],&str[str.size()-1]);
			/*
			 * 	A STRING TEM BEGIN E END... CASO NAO TIVESSE USAR
			 *  O ENDERECO DE MEMORIA DA PRIMEIRA POSICAO E DA ULTIMA....
			 * */
			
			cout << str; 
		}puts("");
	}
	
	return 0;
}

