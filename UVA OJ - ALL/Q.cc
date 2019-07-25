#include <bits/stdc++.h>
#define MAXN 51
using namespace std;




/* sort row/column/direcoes do sentido horario comecando em N(norte) */

int N;
char m[MAXN][MAXN];

bool vld(int l, int c){ return (l > -1 && c > -1 && l < N && c < N);}

int L[] = {-1, -1,0 ,1 ,1 ,1 ,0   , -1 };
int C[] = {0 , 1 ,1 ,1,0 ,-1  ,-1 , -1 };
int d[] = {0 ,1 , 2 ,3 ,4 ,5  ,6  ,7  };
string dd[] = {"N","NE","E","SE","S","SW","W","NW"};

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int main(){
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	string P;
	int t,i,j,k,ct = 0;
	
	for(cin>>t;t--;){
		
		puts("");
		
		scanf(" %d",&N);
		getchar();
		//scanf(" ");
		for(i = 0; i < N ; ++i){
				getline(cin,P);								
			for(j = 0 ; j < N ; ++j) m[i][j] = P[j];//,cout <<"> "<< P[j] << endl ;
		}
		
		//~ for(i = 0; i < N ; ++i,puts("")){
			//~ for(j = 0 ; j < N ; ++j) cout << " |"<<m[i][j]<<"| ";// = P[j],cout <<"> "<< P[j] << endl ;
		//~ }puts("");
		
		
	
		int idx;
		int l,c;
		scanf(" ");
		while(getline(cin,P) && P[0] != '\0')
		{			
			vector<iii> v;
				
			for(j = 0 ; j < N ; ++j)
				for(k = 0; k < N ; ++k)
				{
					if(m[j][k] != P[0]) continue;					
						
						for(i = 0 ; i < 8 ; ++i)
						{
							l = j,c = k,idx = 0;
							bool db = 0;
							
							while(1)
							{
								if(idx == P.size()){ db = 1;break;}
								if(!vld(l,c)) break;
								
								if(P[idx] == m[l][c]) idx++,l+= L[i],c+= C[i];				
								else{	
									if(m[l][c] == ' ')	l+= L[i],c+= C[i];
									else break;
								}
							}
							
							if(db) v.push_back(iii(ii(j,k),i));
						}
				}
			
			if(ct) puts(""); ct = 1;
			
			printf("%s\n",P.data());
			
			if(v.size() > 0){	
				sort(v.begin(),v.end());
				for(auto it : v){
					 printf("(%d,%d) - %s\n",it.first.first+1,it.first.second+1,dd[it.second].data());
				}
			}else puts("not found");
		}
	}
	return 0;
}
