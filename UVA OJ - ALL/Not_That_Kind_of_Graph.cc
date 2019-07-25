#include <bits/stdc++.h>
using namespace std;


int main(){
	
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	string g;
	int t,j,i,ct = 1;
	
	for(cin>>t;t--;){
		
		cin>>g;
		
		int hmax = -99999,hmin = 99999,h = 0;
		
		for(i = 0 ; g[i]  ; ++i){
			if(g[i] == 'F') --h;
			if(g[i] == 'R') ++h;
			hmin = min(h,hmin),	hmax = max(hmax,h);
		}
				//~ printf("hmin = %d   hmax = %d \n",hmin,hmax);
		if(hmin < 0) h = fabs(hmin);
		else h = 0;
		
		hmin += h;
		hmax += h;
		//~ printf("hmin = %d   hmax = %d \n",hmin,hmax);
		int l = hmin+h,c = 1;
		

		
	
		string mat[1000];
		for(i = 0 ; i < 1000 ; ++i)
		mat[i] = "                                                                                                                                                           ";
		//~ cerr<< "asdasd" << endl;
		for(i = 0 ; g[i] ; ++i){
			//~ cout << l << " " << c << endl;
			if(g[i] == 'F'){ mat[--l][c++] = '\\';continue;}	
			if(g[i] == 'R'){ mat[l++][c++] = '/';continue;}
			mat[l][c++] = '_';
		}
		
		printf("Case #%d:\n",ct++);
		
		for(i = hmax ; i>= hmin ; --i){
			for(j = mat[i].size()-1; j >= 0 && mat[i][j] == ' ';--j) mat[i].erase(mat[i].begin()+j);				
			
			if(mat[i].size() > 0) putchar('|'),cout << mat[i] << '\n';
		}printf("+-");
		for(j = 0 ; j < c ; ++j) putchar('-');
		puts("\n");
		
		//~ for(i = hmax ; i >= hmin ; --i){
			//~ printf("|");
			//~ for(j = 0; j < c ; ++j){
				//~ printf("%c",mat[i][j]);
			//~ }puts("");
		//~ }printf("+_");
		
			
		
	}
		
	return 0;
}
